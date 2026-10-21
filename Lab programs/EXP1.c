#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[100];
    int key, i;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter key (1-25): ");
    scanf("%d", &key);
    key = (key % 26 + 26) % 26;

    for (i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i]))
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        else if (islower((unsigned char)text[i]))
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
    }

    printf("Encrypted text: %s", text);
    return 0;
}
