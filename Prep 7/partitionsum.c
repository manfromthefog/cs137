#include <stdio.h>
// https://www.programiz.com/online-compiler/0O0qJ9jT4KYVN

int countPartitions(int n, int m) {
    if (n==0) return 1;
    if (n<0) return 0;
    if (m==0) return 0;
    
    return countPartitions(n-m, m) + countPartitions(n, m-1);
}

int main() {
    // Write C code here
    printf("%d\n", countPartitions(5,5));

    return 0;
}