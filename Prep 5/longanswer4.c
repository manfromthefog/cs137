#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define LEN 'z'-'a'+1

void count_letters(const char *s, int letters[26]) {
    while (*s != 0) {
        if (*s >= 'a' && *s <= 'z') {
            letters[*s - 'a']++;
        }
        s++;
    }
}

bool isAnagram(const char *s, const char *t) {
    int s_letters[26] = {0};
    int t_letters[26] = {0};
    int i = 0;
    
    /*
    count_letters(s, s_letters);
    count_letters(t, t_letters);
    for (int i = 0; i < 26; i++) {
        if (s_letters[i] != t_letters[i]) {
            return false;
            break;
        }
    }
    return true;
    */
    

    // There's actually another smart/sketchy way to do this
    // Instead of having two arrays, count s_array
    // Decrement the value at each index for each appearance in t
    count_letters(s, s_letters);

    for (int i = 0; t[i] != 0; i++) {
        if (t[i] >= 'a' && t[i] <= 'z') {
            s_letters[t[i] - 'a']--;
        }
    }

    for (int k = 0; k < 26; k++) {
        if (s_letters[k] != 0)
            return false;
    }

    return true;
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