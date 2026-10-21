
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    char text[500];
    int a, b, i, d;

    printf("Enter ciphertext: ");
    scanf(" %499[^\n]", text);

    for (a = 1; a < 26; a++) {
        if (gcd(a, 26) != 1) continue;

        for (d = 0; d < 26; d++)
            if ((a * d) % 26 == 1) break;

        for (b = 0; b < 26; b++) {
            printf("a=%d b=%d: ", a, b);

            for (i = 0; text[i]; i++) {
                if (isalpha((unsigned char)text[i])) {
                    int c = toupper((unsigned char)text[i]) - 'A';
                    putchar('A' + (d * (c - b + 26)) % 26);
                } else {
                    putchar(text[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
