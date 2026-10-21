
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[2000];
    int freq[26] = {0}, i;

    printf("Enter ciphertext:\n");
    scanf(" %1999[^\n]", text);

    for (i = 0; text[i]; i++) {
        if (isalpha((unsigned char)text[i]))
            freq[toupper((unsigned char)text[i]) - 'A']++;
    }

    printf("Letter frequencies:\n");
    for (i = 0; i < 26; i++)
        printf("%c = %d\n", 'A' + i, freq[i]);

    return 0;
}
