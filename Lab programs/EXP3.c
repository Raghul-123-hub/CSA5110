
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char mat[5][5];

void makeMatrix(char key[]) {
    int used[26] = {0}, i, j, k = 0;
    char s[26];

    used['J' - 'A'] = 1;

    for (i = 0; key[i]; i++) {
        char c = toupper((unsigned char)key[i]);
        if (c == 'J') c = 'I';
        if (c >= 'A' && c <= 'Z' && !used[c-'A']) {
            s[k++] = c;
            used[c-'A'] = 1;
        }
    }

    for (i = 0; i < 26; i++) {
        if (!used[i]) s[k++] = 'A' + i;
    }

    k = 0;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            mat[i][j] = s[k++];
}

void encryptPair(char a, char b) {
    int r1, c1, r2, c2, i, j;

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++) {
            if (mat[i][j] == a) r1=i, c1=j;
            if (mat[i][j] == b) r2=i, c2=j;
        }

    if (r1 == r2)
        printf("%c%c", mat[r1][(c1+1)%5],
                      mat[r2][(c2+1)%5]);
    else if (c1 == c2)
        printf("%c%c", mat[(r1+1)%5][c1],
                      mat[(r2+1)%5][c2]);
    else
        printf("%c%c", mat[r1][c2], mat[r2][c1]);
}

int main() {
    char key[100], text[200], p[200];
    int i, n = 0;

    printf("Enter keyword: ");
    scanf("%99s", key);
    printf("Enter plaintext: ");
    scanf(" %199[^\n]", text);

    makeMatrix(key);

    for (i = 0; text[i]; i++) {
        char c = toupper((unsigned char)text[i]);
        if (c >= 'A' && c <= 'Z') {
            if (c == 'J') c = 'I';
            p[n++] = c;
        }
    }

    for (i = 0; i < n; i += 2) {
        char a = p[i];
        char b = (i+1 < n) ? p[i+1] : 'X';
        if (a == b) b = 'X';
        encryptPair(a, b);
    }

    printf("\n");
    return 0;
}
