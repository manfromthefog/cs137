# Allocators

```C
void* calloc(size_t nmemb, size_t size)
```
- Clear allocate.
- Allocates nmemb elements of size bytes each initialized to 0

```C
void* realloc(void *p, size_t size)
```
- Resizes a previously allocated block. Data may be lost.
- May need to create a new block and copy over old elements.
- Shrink a heap array, or delete values are use cases.

Typically, use malloc unless there's a good reason to use `calloc` and `realloc`.

# Pointers to Structures

```C
struct tod {
    int hours;
    int minutes;
};
```

We can create a pointer to the structure using ```struct tod *t = malloc(sizeof(struct tod));```. Now `t` points to the beginning of a struct where the integers `hours` and `minutes` are located.

Be careful with the type. `t` points towards a heap of size 2 integers. We can modify these values by using `(*t).hours = 18` or `t->18;` Brackets are necessary since the dot `.` has precedence.

If a struct has a pointer, then we need to define everything sequentially. The pointer points to the struct, and we can pass a mem address to the pointer in the structure as usual. This is not a pointer to a pointer.

## Example

The first time we made `tod` all vars were initialized on stack, now we will show a way to get it done on heap.

```C
#include <stdio.h>
#include <stdlib.h>

struct tod {
    int hours;
    int minutes;
};

void todPrint(struct tod *when){
    printf(" %0.2d :%0.2d\n", (*when).hours, (*when).minutes);
}

int main(void) {
    struct tod *now = malloc(sizeof(struct tod));
    (*now).hours = 16;
    (*now).minutes = 50;
    struct tod *later = malloc(sizeof(struct tod));
    (*later).hours = 18;
    printf("now: "); todPrint(now);
    printf("later: "); todPrint(later);
    (*later).minutes = 1;
    printf("updated later: "); 
    todPrint(later);
    free(now);
    free(later);
    return 0;
}
```

### Tracing
1. `now` is initialized on the stack.
2. Define `hours` and `minutes` on the heap.
3. `later` is initialized on the stack.
4. Define `hours` and `minutes` on the heap.
5. Print the updated later.

Copying an address is easier than copying a value.

# Vectors and VLA

What if we want a struct with an arrayw hose size is to be determined? Arrays have a fixed size, but there are vectors in __C++__, unfortunately __C__ does not have it.

See `vectors.c` and `vectors.h`.

# Pointers to Pointers

```C
int *p = malloc(10 * sizeof(int)); // pointer to integer
struct tod *q = malloc(15 * sizeof(struct tod)); // pointer to struct tod

// Now create array of length 5, and each element is another array, each of possible varying length
// Now we have a pointer to pointer to integer (C is easy, right?)
int **a = malloc(5 * sizeof(int*))

// a[0] is a pointer to integer
```