#include <stdio.h>

int main(void) {
    int a[] = { 0, 1, 2, 3 };
    int *b = a;

    printf("%d\n", a[0]);
    
    b[0] = 7;
    
    printf("%d\n", a[0]);
    return 0;
}