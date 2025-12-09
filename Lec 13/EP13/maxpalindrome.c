#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
// https://www.programiz.com/online-compiler/3jCEyDCi3vj58

bool bounded_palindrome(const char *s, int l, int h) {
    for (int i=0;i<=(h-l)/2;i++) {
        if (s[i+l] != s[h-i])
            return false;
    }
    return true;
}

int longestpalindrome(char *st, int start, int end) {
    int m=0;
    for (int i=start;i<=end;i++) {
        char s=st[i];
        for (int j=end;j>=start;j--) {
            if (st[j] == s) {
                if (bounded_palindrome(st,i,j)) {
                    int run = j-i+1;
                    if (run > m) m=run;
                }
            }
        }
    }
    return m;
}

int main() {
    assert(6==longestpalindrome("111111",0,5));
    assert(7==longestpalindrome("abbbcxyzazyxbba",0,14));
    assert(1==longestpalindrome("a",0,0));
    assert(6==longestpalindrome("aaa77777jbbbbbboh666aaa",0,23));
    assert(6==longestpalindrome("abccbacba",0,8));
    return 0;
}