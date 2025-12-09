# Five Sections of Memory

| Expression     | Type / Description                                                                                                    |
|----------------|------------------------------------------------------------------------------------------------------------------------|
| Code           | Stores the program’s compiled instructions (machine code), placed in a read-only section of memory.                    |
| Read-Only Data | Stores global constants and string literals.                                                                          |
| Global Data    | Stores global/static variables, accessible throughout the program’s execution.                                        |
| Heap           | Used for dynamic memory allocation (`malloc`, `new`, etc.); grows upward (toward higher addresses).                   |
| Stack          | Stores local variables and function call information (return addresses, parameters). Grows downward (toward lower addresses). |


# Stack vs Heaps

## Stack
- Scratch space for a thread of execution.
- Each thread gets a stack.
- Elements are ordered (new elements are stacked on older elements).
- Faster since allocating/deallocating memory is very easy.

## Heap
- Memory set aside for dynamic allocation.
- Typically, only one heap for an entire application.
- Entries might be unordered and chaotic.
- Usually slower since need a lookup table for each element (i.e. More bookkeeping).

# Syntax

We use malloc and free from stdlib.h library to allocate and deallocate memory from the Heap.

```C
void *malloc(size_t size);

// Allocates block of memory of size number of bytes but doesn't initialize.
// Returns a pointer to it.
// Returns NULL, the null pointer, if insufficient memory or size == 0.

void free(void *p)
// Frees a memory block that p is pointing at that was allocated by the user (say using malloc).
// Failure to free your allocated memory is called a memory leak.
```

# NULL Pointer

Since pointers are memory addresses, we need to be able to distinguish from a pointer to something and a pointer to nothing.

The NULL pointer is how we do this. It can be called by
- int *p = NULL;
- int *p = 0;
- int *p = (int *) 0;
- int *p = (void *) 0;
The (void *) typecast will automatically get converted to the correct type. We will talk about it later on in this course. The NULL pointer is in many libraries, including <locale.h>, <stddef.h>, <stdio.h>, <stdlib.h>, <string.h>, <time.h>, <wchar.h> and possibly others.

## Example

```C
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int *numbers(int n);
int main(void) {
    int *q = numbers(100);

    printf("%d\n", q[50]);
    free(q);
    return 0;
}

int *numbers(int n) {
    int *p = malloc(n * sizeof(int));
    assert(p);
    for (int i = 0; i < n; i++)
        p[i] = i;
    return p;
}
```

## Purpose

#### main
1. `q` is pointing at an array of length 100, allocated on HEAP
2. print 50
3. free() avoids memory leak

#### numbers
1. allocate enough space for `n` integers
2. verify that malloc has succeeded (p is not NULL)
3. assign the values 0-99 to p
4. return as a pointer to the beginning of the array

# Memory Leaks

```C
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *my_array;
    my_array = malloc(10 * sizeof(int));
    my_array = malloc(10 * sizeof(int));
    free(my_array);
    return 0;
}
```

## Tracing

1. Initialize a pointer.
2. Allocate space for 10 integers, and point my_array at the allocated memory block.
3. We re-assign my_array to another block of memory, so we lose reference to the first memory block.
4. Free the second allocation. The first block remains allocated, causing a memory leak.

We've lost our pointers. The first block can no longer accessed or freed. __Memory leak__.

# Example of Good Memory Management

```C
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *my_array;

    // First allocation
    my_array = malloc(10 * sizeof(int));
    if (!my_array) {
        perror("malloc failed");
        return 1;
    }

    // Use my_array ...
    for (int i = 0; i < 10; i++) {
        my_array[i] = i;
    }

    // Done with it — free it
    free(my_array);
    my_array = NULL;  // Good practice: avoid dangling pointer

    // Now safe to reassign it
    my_array = malloc(20 * sizeof(int));
    if (!my_array) {
        perror("malloc failed");
        return 1;
    }

    // Use the new block ...
    for (int i = 0; i < 20; i++) {
        my_array[i] = i * 2;
    }

    // Free again when done
    free(my_array);
    my_array = NULL;

    return 0;
}
```

## Explaination
- Allocate with malloc() to get valid memory
- Usage is fine until freed
- free(ptr)	releases the memory
- access after free() is undefined behavior
- reassign after free()	is safe; pointer now points to a new block
- set to NULL after free()
