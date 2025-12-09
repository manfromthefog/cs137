# Pointers

We learned previously that when passing a variable to a function, we are passing a copy of that variable, but that is __not__ the same for arrays. Let's check the memory address of a and arr. In summary, we realize that they are sharing the same data.

An array (by name) is a pointer to something in memory.

## Syntax
```C
int *a; // a is a pointer to an integer

void plusOne(int a[], int n) is equivalent to void plusOne(int *a, int n)
```

We hold the pointer in the first instance.
- "a" is the variable name. We say the holder variable is of type _pointer_.
- Every time there is an address in "a", the address goes to the memory address and grabs 4 bytes (for integers).
- We don't need to hold the address of all the values, just the starting value.

## Example
```C
#include <stdio.h>

void sizeofArray(int a[]) {
    printf("%zu\n", sizeof(a)); // output: 8
}

int main(void) {
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printf("%zu\n", sizeof(a)); // output: 40
    sizeofArray(a);
    return 0;
}
```

### Let's Conclude
1. The array name is the address of the first value.
2. Remember that the a in the function is really just a memory address, and so has the size of a memory address location (which in this case is 8 bytes).
3. The sizeof(a) inside main is actually the size of the array (so the size of all the elements in the array). In this case, this is 10 times sizeof(int)
4. This awkwardness is why we need to pass the size of the array to functions.
5. This is called pointer decay.

# References

```C
#include <stdio.h>

int main(void) {
    int a[] = { 0, 1, 2, 3 };
    int *b = a;

    printf("%d\n", a[0]);
    
    b[0] = 7;
    
    printf("%d\n", a[0]);
    return 0;
}
```

### Let's Conclude
- "*b" takes the memory address of a, and then, the pointer sets the zeroth value of a to 7.
- Pointers allow you to share data. This is important but also dangerous.
- b[anything other than 0] will print out a garbage value since an array is the memory address of the first value.

## Example
```C
#include <stdio.h>

int main(void) {
    int a = 0, b; // declared a,b and set a = 0
    int c[] = { 0 }; // created array with a single zero
    
    int *d; // declared pointer "d"
    b = a; // set b = 0, a = 0;
    a = 2; // set a = 2, b = 0;

    d = c; // d shares the same mem address as c
    c[0] = 2; // set first mem address value to 2

    printf("%d %d", b, d[0]); // remember that since d shares the same mem, we have 0 2 as the output
    return 0;
}
```

# Variable-Length Arrays

```C
#include <stdio.h>
#define LEN 3

int main(void) {
    int a[LEN] = { 2, 4, 6 };
    int b[LEN];
    for (int i = 0; i < LEN; i++)
    b[i] = a[i];
    a[0] = 19;
    printf("a[0] == %d\n", a[0]);
    printf("b[0] == %d\n", b[0]); // b is a copy of a. No reference case
    return 0;
}
```

In C, a VLA, also called variable-sized or runtime-sized, is a array data structure whose length is determined during runtime. This is __not__ allowed in CS137. You are only allowed to define constants. We will later know how to allocate dynamically using heaps.

The above program is allowed because we are assigning a constant value. However, if we used scanf(), that would be VLA and therefore not allowed.

# Multi-Dimensional Arrays

```C
#include <stdio.h>

int main(void) {
    int matrix[4][3] = { 
        {0,  1,  2 },
        {10, 11, 12},
        {20, 21, 22},
        {30, 31, 32},
    };
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    printf("Sum = %d\n", sum);
    return 0;
}
```

### Matrix Values
- Grab values like matrix[2][1], which in the above example returns 21.
- The stack grows in one direction, from the first row to the second to the third.
- A matrix is a pointer to matrix[0][0].

This means you can also do ```sum += matrix[0][i * 3 + j];``` for your information. It is unreadable, but works.

## Example

```C
int main(void) {
    int a[10] = {0};
    long long int num;
    printf("Enter an integer: ");

    scanf("%lld", &num);
    
    while (num > 0) {
        ++ a[num % 10];
        num = num / 10;
    }

    printf("The output:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d %d\n", i, a[i]);
    }
    printf("\n"); return 0;
}
```

Let's say the input is 9059393.

1. We see that num > 0, and 9059393 % 10 = 3.
2. In the third position we add 1.
3. Then it prints the frequency of each digit.
4. a = {1, 0, 0, 2, 0, 1, 0, 0, 0, 3}
5. This is a case where we are using the array index to store data, rather than the array itself.