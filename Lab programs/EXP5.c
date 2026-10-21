
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[100];
    int a, b, i;

    printf("Enter plaintext: ");
    scanf(" %99[^\n]", text);
    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);

    if (a < 0 || a >= 26 || b < 0 || b >= 26) {
        printf("Use a and b between 0 and 25.\n");
        return 1;
    }

    int x = a;
    while (x > 0 && x % 2 == 0) {
        printf("Invalid a: encryption is not one-to-one.\n");
        return 1;
    }
    if (a == 0 || a == 13) {
        printf("Invalid a: encryption is not one-to-one.\n");
        return 1;
    }

    for (i = 0; text[i]; i++) {
        if (isalpha((unsigned char)text[i])) {
            char base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            text[i] = (a * (text[i] - base) + b) % 26 + base;
        }
    }

    printf("Encrypted text: %s\n", text);
    return 0;
}
