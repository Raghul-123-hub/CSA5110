
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[100];
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i, x;

    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            x = toupper((unsigned char)text[i]) - 'A';
            text[i] = key[x];
        }
    }

    printf("Encrypted text: %s", text);
    return 0;
}

