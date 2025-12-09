# The Pointer Era

What if we want functions to change values inside memory that are outside the
scope of a function?

## Swap Example

```C
#include <stdio.h>

void swap(int a, int b){
    printf("a=%d, b=%d\n", a, b);
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    printf("a=%d, b=%d\n", a, b);
}

int main(void){
    int x = 10;
    int y = -15;
    printf("x=%d, y=%d\n", x, y);
    swap(x, y);
    printf("x=%d, y=%d\n", x, y);
    return 0;
}
```

We see the output is
```
x=10, y=-15
a=10, b=-15
a=-15, b=10
x=10, y=-15
```

All that for a swap that doesn't work? Because a copy of the x and y values were assigned to the parameters a and b.

Any changes to a and b did not affect x and y. But how can we make the changes
in the swap function affect the variables x and y in the main?

We saw this already when we changed values in an array. We can do this with
other values by using pointers and references.

## Pointer Variation
```C
#include <stdio.h>

int main(void) {
    int i = 6;
    int *p;
    p = &i; // mem address of i
    *p = 10; // assign 10 at where p is pointing at !!! i will become 10
    printf("%d \n", i);
    int *q;
    q = p; // q will have the address of i, as well as p
    *q = 17; // now i will become 17
    printf("%d \n", i);
    return 0;
}
```
Make sure we don't neglect what we want to do visually and then implement it because debugging pointers is a nightmare. Pointers will blow your program up.

## Fixed Swap

```C
#include <stdio.h>

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

Let's trace this new solution.