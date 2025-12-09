#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
// https://www.programiz.com/online-compiler/2RcGAisdTCUav

// '?' represents any letter
bool isPrefix(char *str, char *prefix) {
    if (*prefix == '\0') return true;
    if (*str == '\0') return false;
    
    if (*prefix == '?' || *str == *prefix)
        return isPrefix(++str, ++prefix);
        
    return false;
}

// counts how many times a pattern appears in a text
int countOccurrences(char *text, char *pattern){
    if (*text == '\0') return 0;
    if (isPrefix(text, pattern))
        return countOccurrences(++text, pattern) + 1;
    return countOccurrences(++text, pattern);
}

int main(void){
    assert(isPrefix("CS137 is great", "CS137"));
    assert(isPrefix("CS137 is great", "CS137 is great"));
    assert(isPrefix("CS137 is great", "CS?37"));
    assert(!isPrefix("CS137 is great", "great"));
    assert(!isPrefix("CS137 is great", "cs137"));
    assert(!isPrefix("CS137", "CS138"));
    assert(countOccurrences("mama and papa", "?a?a")==3);
    assert(countOccurrences("a", "ab")==0);
    assert(countOccurrences("mama and papa", "dad")==0);
    assert(countOccurrences("xxxxxxxxx", "xx")==8);
}
