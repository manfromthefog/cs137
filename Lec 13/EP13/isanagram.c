#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
// https://www.programiz.com/online-compiler/5YHF6lJikt1SS

#define len 'z'-'a' + 1

int *charfreq(const char *s) {
    int *r = calloc(len, sizeof(int));
    while (*s != '\0') {
        if (*s > 96 && *s < 123) {
            r[*s - 97]++;
        }
        *s++;
    }
    return r;
}

bool isAnagram(const char *s, const char *t) {
    bool cmp = true;
    int *sf = charfreq(s);
    int *tf = charfreq(t);
    for (int i=0;i<len;i++) {
        if (sf[i] != tf[i]) {
            cmp = false;
            break;
        }
    }
    free(sf);
    free(tf);
    return cmp;
}

int main(void) {
    assert(isAnagram("a gentleman", "elegant man"));
    assert(!isAnagram("a gentleman", "elegant men"));
    assert(isAnagram("election results", "lies - let's recount"));
    assert(!isAnagram("election results", "lies - let recount"));
    assert(isAnagram("the hilton", "hint: hotel"));
    assert(!isAnagram("the hilton", "hint: a hotel"));
    return 0;
}