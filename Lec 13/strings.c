#include <stdio.h>

int main(void) {
    const int n = 5;
    const int *p = &n;
    int *const q = &n;
}