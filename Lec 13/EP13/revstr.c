#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// https://www.programiz.com/online-compiler/8F3gYtH2L9i8j

char *reversestr(char *s) {
    int n = strlen(s);
    char *r = malloc(sizeof(char)+1);
    
    for (int i=n-1;i>=0;i--) {
        r[n-1-i] = s[i];
    }
    r[n] = '\0';
    return r;
}

int main() {
    // Write C code here
    char s[] = "Hello my friend!";
    char *r = reversestr(s);
    
    printf("%s\n", r);
    free(r);

    return 0;
}