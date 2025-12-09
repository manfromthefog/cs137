# Strings and Characters

```C
char c;
```

Is a 8-bit integer. The integer can be code representing _printable_ and _unprintable_ characters. It can also store a single letter, like `char c = 'a'`.

## Example

```C
#include <stdio.h>

int main(void) {
    char c1 = 'a';
    char c2 = 97;
    printf("%c\n", c1); // output: a
    printf("%d\n", c1); // output: 97
    printf("%d\n", c2); // output: 97
    printf("%c\n", c2); // output: a
    return 0;
}
```

# ASCII

[ASCII](https://hobbyprojects.com/ascii-table/ascii-table.html) (American Standard Code for Information Interchange) codes represent text in computers and other devices.

ASCII uses 7 bits, with the 8<sup>th</sup> bit being either used for a parity check bit or extended ASCII, ranging from 0000000-1111111.

## Table
1. Characters 0-31 are control characters
2. Characters 48-57 are the numbers 0 to 9
3. Characters 65-90 are the letters A to Z
4. Characters 97-122 are the letters a to z
5. Note that 'A' and 'a' are 32 letters away

For the English language, ASCII turns out to be enough for most applications. However, many languages have far more complicated letter systems, and a new way to represent these would be required. To account for other languages, we now have Unicode.

# Strings

Strings are an array of characters terminated by a __NULL__ character `('\0')`. Print them with `%s`.

In all cases, the null character will be added by default unless you initialize a string character by character. In that case the compiler will have an error.

## Example
```C
#include <stdio.h>

int main(void) {
    char s[] = "Hello";
    s[1] = 'a'; // mutating the second letter

    printf("s=%s\n", s); // Output: s=Hallo
    printf("sizeof s is %zu\n", sizeof(s)); // output 6 (because s is an array of 6 characters and each char requires 1 byte
 
    // Slightly different
    char *u = "Hello";

    // The next commented line causes an error! check the explanation below.
    // u[1] = 'a'
    
    printf("u=%s\n", u); // Output: u=Hello
    printf("sizeof u is %zu\n", sizeof(u)); // Output: 8 because the size of a pointer is 8 bytes

    char *hi = "Hello" " world!";

    printf("hi=%s\n", hi); // Output: hi=Hello world!
    printf("sizeof hi is %zu\n", sizeof(hi)); // Output: 8 because the size of a pointer is 8 bytes
    return 0;
}
```

### Why Error?
In C `char *u = "Hello";` "Hello" is called a string literal. String literals are not allowed to be changed, and attempting to change them causes undefined behaviour. String literals are not allocated on the stack nor heap, rather on the ROM (read-only memory).

Notice also that sizeof(u) is different from the sizeof(s) since s is an array vs u is a pointer. Another note. `char *hi = "Hello"" world!";` will combine into one string literal.

# `const` Quantifiers

`const` makes a variable read-only. Assignment to `const` results in an error. Unless, you assign a pointer to the mem address of that variable, even then the compiler will issue a warning.

## `const` vs. `#define`

`const` can be used to create read-only objects of any time we want, including arrays, structures, pointers etc. Constants are subject to the same scope rules as variables and constants have memory addresses.

`#define` can only be used for numerical, character or string constants. Constants created with #define aren’t subject to the same scoping rules as variables - they apply everywhere. Macros don’t have addresses.

## Constant Pointers?

`const int *p` and `int *const q` are very different. Remember to read from __right__ to __left__.

`const int *p`
- Read as "`p` is a pointer to a constant `int`."
- We cannot modify the integer that p points to (through p).
- We can modify the pointer itself.

For example, the line `p = &i` is okay, as this reassigns the pointer itself, not the int it points at. Whereas the line `*p = 5` will cause an error.

If we have another pointer `int *r`, then `p` is a pointer to a constant int, and r is a pointer to a modifiable int. `r = p` will give a warning since we are assigning a constant int pointer to a modifiable int pointer. `r` can now be used to modify something meant to be read-only.

`r = (int *)p` will give no warning. You're forcing the conversion from `const int *p` to `int *p`, i.e. telling the compiler "trust me." `*r = 5` will execute, bypassing the intended behaviour. Be careful! This might crash or corrupt read-only memory.

`int *const q`
- Read as "`q` is a constant pointer to an `int`."
- The line int `*const q` means that we cannot modify the actual pointer `q`. 
- The line `q = p` will cause an error.

The rule is... constant pointers always point to the same thing. Constant variables always have the same value unless there is a pointer to it, then its deref can change the value. 

### Example

`const int *const pcm = &x;` is a "pure catholic marriage (pcm)." It is a constant pointer to a constant variable. The pointer is forever tied to the variable.

# Strings Functions

The C library `<string.h>` provides several functions.
1. `size_t strlen(const char *s);`
2. `char *strcpy(char *s0, const char *s1);`
3. `char *strncpy(char *s0, const char *s1,size_t n);`
    - Only copies the first n characters from s1 to s0.
    - No null character is added to end of s0 if it was not part of s1.
    - Null padded if strlen(s1) < n.
4. `char *strcat(char *s0, const char *s1);`
    - Two strings should not overlap on the same memory!
5. `char *strncat(char *s0, const char *s1, size_t n);`
     - Only concatenates the first n characters from s1 to s0.
     - Adds null character after concatenation.

## Example

```C
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

/***
 * s -> [' ','h','e','l','l','o',' ','\0',' ','w','o','r','l','d',' ','\0']
 *   idx  0   1   2   3   4   5   6    7   8   9   10  11  12  13  14  15
 * 
 * We need to make sure we allocate enough memory, or the null might get cut off
 */
char *concat(const char *s0, const char *s1) {
    // Extra 1 for null character
    char *s = (char *)malloc((strlen(s0) + strlen(s1) + 1) * sizeof(char));
    strcpy(s, s0);
    // strcat appends to the buffer, by finding the former null character!
    // overwrites whatever was there
    strcat(s, s1);
    return s;
}
```

## `gets` vs `scanf`

When trying to read a string from the user using scanf, recall that it stops reading characters at any whitespace type character.

This might not be the desired effect. You could use the gets function to change this, which stops reading input on a newline character. Both are risky functions as they don't check when the array storing the strings is full.

## `printf` for Strings

On certain compilers, the command `char *s = "abcj\n"; printf(s);` gives a warning.

warning: format not a string literal and no format arguments [-Wformat-security]

This is a potential security issue if the string itself contains formatting arguments (for example, if it was user-created). You can avoid these errors if you make the above string a constant or use printf("%s",s); type commands.
