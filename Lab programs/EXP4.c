
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[100], key[100];
    int i, j = 0;

    printf("Enter plaintext: ");
    scanf(" %99[^\n]", text);
    printf("Enter keyword: ");
    scanf("%99s", key);

    for (i = 0; text[i]; i++) {
        if (isalpha((unsigned char)text[i])) {
            char base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            int shift = toupper((unsigned char)key[j % (int)__builtin_strlen(key)]) - 'A';
            text[i] = (text[i] - base + shift) % 26 + base;
            j++;
        }
    }

    printf("Encrypted text: %s\n", text);
    return 0;
}
