// Online C compiler to run C program online
#include <stdio.h>

int main() {
    long long int res = 0;
    for (int i = 1; i < 23; i++) {
        for (int j = i; j > 0; j--) {
            for (int k = j; k > 0; k--) {
                res = i * i * i + j * j * j + k * k * k;
                if (res <= 10000) {
                    if (res == 9998) {
                        printf("%d %d %d\n", i, j, k);
                    }
                    printf("%lld\n", res);
                }
            }
        }
    }
    return 0;
}