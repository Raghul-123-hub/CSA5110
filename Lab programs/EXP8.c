
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[200];
    char key[] = "CIPHERABDFGJKLMNOQSTUVWXYZ";
    int i;

    printf("Enter plaintext: ");
    scanf(" %199[^\n]", text);

    for (i = 0; text[i]; i++) {
        if (isalpha((unsigned char)text[i])) {
            int x = toupper((unsigned char)text[i]) - 'A';
            text[i] = key[x];
        }
    }

    printf("Encrypted text: %s\n", text);
    return 0;
}
