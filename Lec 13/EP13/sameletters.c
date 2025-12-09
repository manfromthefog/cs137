#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
// https://www.programiz.com/online-compiler/3jCEOjyhnv3q1

#define len 'z'-'a'+1

bool allWordsSameLetters(const char *str) {
    int f[len] = {0};
    int n = strlen(str);
    int j = 0;
    while (str[j] != ' ') {
        if (str[j] > 64 && str[j] < 91) f[str[j] - 65]=1;
        if (str[j] > 96 && str[j] < 123) f[str[j] - 97]=1;
        j++;
    }
    for (j;str[j] == ' ';j++);
    for (int i=j;i<n;) {
        int k=i;
        int c[len] = {0};
        while (str[k] != ' ') {
            if (str[k] > 64 && str[k] < 91) c[str[k] - 65]=1;
            if (str[k] > 96 && str[k] < 123) c[str[k] - 97]=1;
            k++;
        }
        for (int u=0;u<len;u++) {
            if (f[u] != c[u]) {
                return false;
            }
        }
        i += k;
        for (i;str[i]==' ';i++);
    }
    return true;
}

int main(void) {
    assert(allWordsSameLetters(" "));
    assert(allWordsSameLetters("abc  "));
    assert(allWordsSameLetters("abc bBca acb"));
    assert(allWordsSameLetters("Abc bca Acb"));
    assert(allWordsSameLetters("abc ccabc acb"));
    assert(!allWordsSameLetters("abcd bBca acb"));
    assert(!allWordsSameLetters("ab bBca acb"));
    return 0;
}