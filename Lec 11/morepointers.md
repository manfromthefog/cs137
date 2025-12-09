# References 

```C
void swap(int a, int b){
    int tmp;
    tmp = *a; // We set temp to the dereferenced content of a
    *a = *b;  // We set the mem address of a to b
    *b = tmp; // and we set the mem address of b to a
}

int main(void){
    int x = 10;
    int y = -15;
    printf("x=%d, y=%d\n", x, y);
    swap(&x, &y); // We pass in the memory addresses of x and y to the pointers so we're actually changing the values instead of changing a and b
    printf("x=%d, y=%d\n", x, y);
    return 0;
}
```

The `*` symbol is now used for three things. Multiplication, initializing a pointer, and dereferencing.

### Tracing

main
1. x = 10
2. y = -15

swap
1. p1 = address of x -> (address of x)
2. p2 = address of y -> (address of y)
3. tmp = 10 (dereferenced p1 / what p1 is pointing at)
4. set derefenced p1 to dereferenced p2
5. set dereferenced p2 to tmp (dereferenced p1)

output stream
10 -15
-15 10

We are not passing a copy of the variable, we are passing a copy of the address of `x` and `y`. The difference is, the address we passed is unique to the variable.

# Pointer Function
```C
int *what(int *a, int n){
    int *res = &a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > *res) {
            res = &a[i];
        }
    return res;
}

int main(void) {
    int a[10] = { 1, 10, 67, 876, -76, 0, -45, 8, 9, 1 };
    int *ans = what(a, 10);
    printf("The result is %d\n", *ans);
    return 0;
}
```

### Tracing

main
1. arr = { 1, 10, 67, 876, -76, 0, -45, 8, 9, 1 }
2. ans is a pointer to an integer

what
1. res = mem address of the first element of the array
2. for each element, check if the array element is larger than the first
3. if it is larger, res is now pointing towards the memory address of a[i] (not a dereference, we are changing where the pointer points)
4. return an integer pointer that points towards the maximum value in memory

## Array Model

Remember that arrays point towards the first element in an array, so instead of writing `int *res = &a[0]` we can write `int *res = a`.

Remember that a dereference is a value, you cannot assign a memory address. When you initialize a pointer, you are not dereferencing a pointer.

# Pointer Arithmetic
C allows an integer to be added to a pointer. The result depends on the type of the pointer.

__(p+1) adds the sizeof whatever p points at.__

You can NOT add two pointers.

A pointer q can be subtracted from another pointer p if the pointers are the same type (point to the same type). Pointers can be compared with the comparison operators <, <=, ==, !=, >=, >.

## Example

```C
#include <stdio.h>

int main(void){
    int a[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
    int *p, *q, i;
    p = &(a[2]);
    q = p + 3;
    p += 4;
    q = q - 2;
    i = q - p;
    i = p - q;
    if (p <= q)
        printf(" less \n");
    else
        printf(" more \n");
    return 0;
}
```

### Tracing

main
1. a is an array of length 8
2. p, q are integer pointers, i is an integer
3. p points at the memory address of a[2] (which is 4)
4. q points at p + 12 bits -> points at a[5] (which is 7)
5. p + 16 bits -> points at a[6] (which is 8)
6. q - 8 bits -> points at a[3] (which is 5)
7. q is before p, i = q - p = -3
8. p is after q, i = p - q = 3
9. p <= q is false

output stream
more

# Summing Array

```C
int sum(int *a, int n) {
    int total = 0;
    for (int *p = a; p < a + n; p++)
        total += *p;
    return total;
}
```

## Tracing

sum
1. input an array a[] with length n
2. pointer p points at the first element in the array (0)
3. while the position of the pointer is less than or equal to the array's last element
4. add the dereference of p to the total
5. return the total

# Alternative
```C
int sum(int *a, int n) {
    int total = 0;
    for (int i = a; i < n; i++)
        total += *(a + i);
    return total;
}
```

## Tracing

sum
1. input an array a[] with length n
2. increment i less than or equal to the index of the last element
3. add the dereferenced pointer of the ith element to total
4. Return the total


# Largest

```C
int *largest(int *a, int n) {
    int *m = a;
    for (int *p = a + 1;  p < a + n; p++) {
        if (*p > *m) 
            m = p; // The goal is to return the location of the max and min, not change the array
    }
    return m;
}
```

## Result

Returns the pointer that points at the location of the maximum.

# Faulty Sum Entries

```C
#include <stdio.h>

int main(void){
    int a[4] = { 5, 2, 9, 4 };
    int sum = 0;
    int *p = &a[0];
    while (p < &a[4]) { // &a[4] does not point to the array; it points just past it.
        sum += *p++;
    }
    printf("%d\n", sum);
    return 0;
}
```

## Tracing

main
1. Initialize array a of size 4
2. Initialize int sum = 0
3. Initialize pointer at the first element of the array
4. While the pointer is less than equal to the mem address of the last element
5. Dereference p and then sum it... this is the faulty line.

## Rules

It is legal to take the address one past the end of an array, but it is illegal to dereference that address.
```C
int *p = a;
int *end = &a[4]; // or a + 4

while (p < end) {
    // OK to compare
    // OK to increment p up to end
    // NOT OK to dereference p == end
    do_something(*p);  // valid while p < end
    p++;
}

int x = a[4];   // undefined behavior (dereference past end)

int *p = &a[4];
*p = 10;        // undefined behavior — writing to past-the-end memory
```

# Exercise

Assume `x` is at memory address 100 and int has size 4.

```C
#include <stdio.h>

void main(void) {
    int x[5];
    printf("%p\n", x);
    printf("%p\n", x + 1);
    printf("%p\n", &x);
    printf("%p\n", &x + 1);
}
```

## Output

```
100
104
100
120
```

The array is declared as

`int x[5];`
- The base address of the array x (i.e. &x[0]) is 100.
- The size of int = 4 bytes
- The array therefore occupies addresses 100 → 119 (since 5 × 4 = 20 bytes)

| Expression | Type | Meaning | Value Address |
|-------|-----|-----------|-----------|
| x | int *  | address of first element | 100 |
| x + 1 | int *  | address of next int element | 104 |
| &x | int (*)[5]  | address of the entire array | 100 |
| &x + 1 | int (*)[5] | address past the whole array | 120 |
