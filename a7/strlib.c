#include <stddef.h>
#include <assert.h>
#include <stdio.h>

/***
 * mystrlen(p)
 * return type: int
 * Returns:
 *      The length of a string p, not including \0
 */
int mystrlen(const char *p){
    int i = 0;
    for (;*p!='\0';p++)
        i++;
    return i;
}

// find(p, n, c)
// return type: const char *
// Returns:
//     The smallest q in [p, p + n) such that *q == c is true
// ​    0​ otherwise
const char *find(const char *p, int n, char c) {
    int i = 0;
    while (i < n) {
        if (p[i] == c)
            return (p+i);
        i++;
    }
    return NULL;
} // worst case O(n) time complexity?

// find_first_of(p, pos, q, count)
// return type: int
// Returns:
//  Finds the first character in [p + pos, p + strlen(p)) equal to one of the characters in the range [q, q + count). 
//  This range can include null characters.
//  If [q, q + count) is not a valid range, the behavior is undefined.
int find_first_of(const char *p, int pos, const char *q, int count) {
    // loop through characters in p, starting from pos
    for (int i=pos;p[i]!='\0';i++) {
        // perform linear search on q
        int match = 0;
        for (int j=0;j<count;j++) {
            if (q[j] == p[i])
                match = 1;
        }
        if (match) return i;
    }
    return -1;
}

// find_first_not_of(p, pos, q, count)
// return type: int
// Returns:
//  Finds the first character in [p + pos, p + strlen(p)) that is not equal to any of the characters in the range [q, q + count).
//  This range can include null characters.
//  If [q, q + count) is not a valid range, the behavior is undefined.
int find_first_not_of(const char *p, int pos, const char *q, int count) {
    for (int i=pos;p[i]!='\0';i++) {
        int match = 0;
        for (int j=0;j<count;j++) {
            if (q[j] == p[i])
                match = 1;
        }
        if (!match) return i;
    }
    return -1;
}

// find_last_of(p, pos, q, count)
// return type: int
// Returns:
//  Finds the last character in [p, p + pos] equal to one of the characters in the range [q, q + count).
int find_last_of(const char *p, int pos, const char *q, int count) {
    // Find the last character by looping backwards
    for (int i=pos;i>=0;i--) {
        int match = 0;
        for (int j=0;j<count;j++) {
            if (q[j] == p[i]) return i;
        }
    }
    return -1;
}

// find_last_not_of(p, pos, q, count)
// return type: int
// Returns:
//  Finds the last character in [p, p + pos] that is not equal to any of the characters in the range [q, q + count).
int find_last_not_of(const char *p, int pos, const char *q, int count) {
    // exact same idea; find the last by finding the first backwards
    // if the position at pos is null, we overcounted!
    if (p[pos] == '\0') pos--;
    for (int i=pos;i>=0;i--) {
        int match = 0;
        for (int j=0;j<count;j++) {
            if (q[j] == p[i])
                match = 1;
        }
        // if count=0 the match we have a false negative
        // no chars in range count, no comparison to make
        if (!match && count != 0) return i;
    }
    return -1;
}

/*
int main(void) {
    /////////////////// find ////////////////////////////
    const char *p = "hello world";

    assert(find(p, 1, 'l') == NULL);
    assert(find(p, 1, 'h') == p);

    assert(find(p, 2, 'l') == NULL);
    assert(find(p, 3, 'l') == p + 2);
    assert(find(p, 4, 'l') == p + 2);

    assert(find(p, mystrlen(p), 'o') == &p[4]);
    assert(find(p, mystrlen(p), 'z') == NULL);

    assert(find(p, 11, 'o') == &p[4]);
    assert(find(p, 11, 'z') == NULL);
    assert(find("", 0, 'a') == NULL); // empty string
    assert(find("a", 1, 'a') == &"a"[0]); // single character match

    /////////////////// find_first_of ///////////////////
   
    assert(1==find_first_of("alignas", 0, "klmn", 4));
    assert(-1==find_first_of("alignof", 0, "wxyz", 4));
    assert(-1==find_first_of("consteval", 0, "xyzabc", 3));
    assert(0==find_first_of("constexpr", 0, "xyzabc", 6));
    assert(find_first_of("hello world", 0, "aeiou", mystrlen("aeiou")) == 1); 
    assert(find_first_of("hello world", 5, "aeiou", mystrlen("aeiou")) == 7); 
    assert(find_first_of("hello world", 8, "aeiou", mystrlen("aeiou")) == -1); 
    assert(find_first_of("", 0, "aeiou", 5) == -1); 
    assert(find_first_of("hello", 0, "", 0) == -1); 

    /////////////////// find_first_not_of ///////////////////

    assert(find_first_not_of("hello world", 0, "helo wrd", mystrlen("helo wrd")) == -1); 
    assert(find_first_not_of("hello world", 0, "helo wr", mystrlen("helo wr")) == 10); 
    assert(find_first_not_of("", 0, "helo wrd", 8) == -1); 
    assert(find_first_not_of("hello", 0, "", 0) == 0); 
    
    /////////////////// find_last_of ////////////////////
    assert(5==find_last_of("alignas", 6, "abcd", 4));
    assert(5==find_last_of("alignas", 5, "abcd", 4));
    assert(0==find_last_of("alignas", 4, "abcd", 4));
    assert(find_last_of("hello world", 10, "aeiou", 5) == 7); 
    assert(find_last_of("hello world", 4, "aeiou", 5) == 4); 
    assert(find_last_of("hello world", 0, "aeiou", 5) == -1); 
    assert(find_last_of("", 0, "aeiou", 5) == -1); 
    assert(find_last_of("hello", 4, "", 0) == -1);
    assert(find_last_of("", 0, "", 0) == -1);

    /////////////////// find_last_not_of ////////////////////

    assert(find_last_not_of("hello world", mystrlen("hello world") - 1, "helo wrd", mystrlen("helo wrd")) == -1); 
    assert(find_last_not_of("hello world", mystrlen("hello world") - 1, "helo wr", mystrlen("helo wr")) == 10); 
    assert(find_last_not_of("", 0, "helo wrd", 8) == -1);
    assert(find_last_not_of("hello", 4, "", 0) == -1);
    assert(find_last_not_of("hello", 4, "ab", 2) == 4);
}
*/
