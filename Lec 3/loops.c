#include <stdio.h>

int main(void) {
    for (int i = 10; i > 0; i -= 2) {
        if (i % 2 == 0) {
            i -= 2;
            printf("%d", i);
        }
        return 0;
    }
}