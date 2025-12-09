#include <stdio.h>
#include <string.h>
// https://www.programiz.com/online-compiler/1oGKHiQlQE5Xi

void encrypt(char *s, char *key) {
    int n = strlen(s), k = strlen(k);
    for (int i=0;i<n;i++) {
        int shift = key[i%k] - '0';
        if (s[i] == 'a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            shift++;
        if (s[i]>='a' && s[i]<='z')
            s[i] = (s[i]+shift-'a')%26+'a';
    }
}

int main() {
    char plaintext[] = 'hello world';
    char key[] = '12345';

    encrypt(plaintext, key);
    printf("%s\n", plaintext);
}