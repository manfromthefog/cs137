#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
    int n = 5;

    int i;
    int parity = 0;
    for (i = 0; i < n; i++) {
        parity = !parity;
    }

    printf("%d\n", parity);
    return 0;
}