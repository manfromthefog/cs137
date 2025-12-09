#include <stdio.h>

// You can replace *a with a[] and the same output will occur
void sizeofArray(int *a) {
    printf("%zu\n", sizeof(a)); // output: 8
}

int main(void) {
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printf("%zu\n", sizeof(a)); // output: 40
    sizeofArray(a);
    return 0;
}