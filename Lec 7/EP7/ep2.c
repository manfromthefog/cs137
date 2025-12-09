#include <stdio.h>

int main() {
    long long int n;
    scanf("%lld", &n);
    int digits[10]  = {0};

    while (n) {
        digits[n % 10]++;
        n /= 10;
    }

    for (int i=0;i<10;i++)
        printf("%d %d\n", i, digits[i]);
    
    return 0;
}