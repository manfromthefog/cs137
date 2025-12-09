#include <stdio.h>

void hanoi (int n, char src, char dst, char sp) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", src, dst);
    } 
    else {
        // Move n - 1 disks from src to sp using dst as a spare.
        hanoi(n - 1, src, sp, dst);
        // Move disk n from src to dst
        hanoi(1, src, dst, sp);
        // Move n - 1 disks from sp to dst using src as a spare.
        hanoi(n - 1, sp, dst, src);
    }
}