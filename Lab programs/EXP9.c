
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char m[5][5];

void makeKey(char key[]) {
    int used[26] = {0}, n = 0, i, j;
    char s[25];

    used['J'-'A'] = 1;

    for (i = 0; key[i]; i++) {
        char c = toupper((unsigned char)key[i]);
        if (c == 'J') c = 'I';
        if (c >= 'A' && c <= 'Z' && !used[c-'A']) {
            s[n++] = c;
            used[c-'A'] = 1;
        }
    }

    for (i = 0; i < 26; i++)
        if (!used[i]) s[n++] = 'A' + i;

    n = 0;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            m[i][j] = s[n++];
}

void decrypt(char a, char b) {
    int r1=0,c1=0,r2=0,c2=0,i,j;

    for (i=0; i<5; i++)
        for (j=0; j<5; j++) {
            if (m[i][j]==a) r1=i,c1=j;
            if (m[i][j]==b) r2=i,c2=j;
        }

    if (r1==r2)
        printf("%c%c",m[r1][(c1+4)%5],
                       m[r2][(c2+4)%5]);
    else if (c1==c2)
        printf("%c%c",m[(r1+4)%5][c1],
                       m[(r2+4)%5][c2]);
    else
        printf("%c%c",m[r1][c2],m[r2][c1]);
}

int main() {
    char key[100], text[500];
    int i;

    printf("Enter keyword: ");
    scanf("%99s",key);

    printf("Enter ciphertext (letters only): ");
    scanf("%499s",text);

    makeKey(key);

    printf("Decrypted text: ");
    for (i=0; text[i] && text[i+1]; i+=2)
        decrypt(toupper((unsigned char)text[i]),
                toupper((unsigned char)text[i+1]));

    printf("\n");
    return 0;
}
