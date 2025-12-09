# Arrays

1. Arrays
2. Passing Arrays to Functions
3. Copying Arrays
4. VLA
5. 2D Arrays

## Cases to Consider

int a[5] = {10,-7,3,8,42};        (0)
int a[] = {10,-7,3,8,42};         (1)
int a[5] = {1,2,3};               (2)
int a[5] = {0};                   (3)
int a[5];                         (4)
int a = {[2] = 2, [4] = 3123};    (5)

0. Arrays start from index 0.
1. Size is inferred.
2. Last two entires are 0 are 0 by default.
3. Creates an all 0 array.
4. Uninitialized array contains rubbish.
5. Specified the third and fifth entires. The rest are zero.

### Why Arrays?
- Up to this point, we've seen ways to create variables to store data.
- What if you wanted lots of variables? For example, suppose you wanted to store an office directory. Should we create a variable for each person?
- Arrays solve this.
- Arrays enable us to define a set of ordered items of the same type.
- Arrays start index at 0 (often why in CS, natural numbers start at 0). CS 137 - FALL 2025 3

## How Arrays Store Data in Memory

int a[5] = {10,-7,3,8,42};

| Variable Name | Mem Address |     Value     |
|---------------|-------------|---------------|
|       a       |    10856    |      10       |
|               |     ...     |      -7       |
|               |     ...     |       3       |
|               |     ...     |       8       |
|               |     ...     |      42       |

## Example 1

```C
#include <stdio.h>

int main(void) {
    int a[] = { 10, -7, 3, 8, 42 };
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += a[i];
    }
    printf("%d\n", sum);
    return 0;
}
```

## Example 2

```C
#include <stdio.h>
int main(void)
{
    int fib[10];
    int ind;
    fib[0] = 1;
    fib[1] = 1;
    for (ind = 2; ind < 10; ind++) {
        fib[ind] = fib[ind - 1] + fib[ind - 2];
    }

    // Expected output: 1 1 2 3 5 8 13 21 34 55
    for (ind = 0; ind < 10; ind++) {
        printf("%d ", fib[ind]);
    }
    printf("\n");
    return 0;
}
```

# Array Sizes

- In all of our examples, we know the size of our arrays.
- Ideally, we wouldn’t have to pass this information inside [ ] the array itself should encode how large it is.
- We can access this information using the sizeof() operator, which takes either a type or a variable as a parameter and returns the number of bytes used to store a type or variable.
- Technically, it returns an __unsigned integer of type size_t__, which is an unsigned type.
- You might need to typecast this in certain situations to convince C that this is an integer (more on this later).
- When the statement is read, it is clear the program is asking for the size of the array.

## Example

The %zu is preferred for cross-platform compatibility.

```C
#include <stdio.h>

int main(void){
    int a[] = {-1, 2, -1, 2, -4, 1};
    printf("%d\n", sizeof(a) / sizeof(a[0]));
    printf("%d %d %d %d\n", sizeof(char), sizeof(int), sizeof(a[0]), sizeof(a));
    printf("%zu %zu %zu %zu", sizeof(char), sizeof(int), sizeof(a[0]), sizeof(a));
    return 0;
}
```

## Example

```C
#include<stdio.h>
void plusOne(int a[], int n) {
    printf("(2) address of a: %p\n", a);
    for (int i = 0; i < n; i++) a[i]++;
}
int main(void){
    int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printf("(1) address of a: %p\n", arr);

    plusOne(arr, sizeof(arr) / sizeof(arr[0]));

    printf("(3) address of arr: %p\n", arr);
    // did arr change? YES.
    // passing a sequence of integers to a function will NOT make a copy
    return 0;
}
```