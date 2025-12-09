#include <stdio.h>

int main(void){
    int a[] = {-1, 2, -1, 2, -4, 1, 6, 7};
    printf("%d\n", sizeof(a) / sizeof(a[0]));
    printf("%d %d %d %d\n", sizeof(char), sizeof(int), sizeof(a[0]), sizeof(a));
    printf("%zu %zu %zu %zu\n", sizeof(char), sizeof(int), sizeof(a[0]), sizeof(a));
    return 0;
}