#include <stdio.h>

int mystery(int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += i;
        return total;
    }
}

int main(void) {
    printf("%d", mystery(5));
    return 0;
}
