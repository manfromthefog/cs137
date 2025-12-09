#include <stdio.h>

int main(void) {
    int freq[101] = {0};

    int n;
    while(scanf("%d\n", &n)) {
        freq[n]++;
    }

    for (int i=0;i<101;i++) {
        if (freq[i])
            printf("%d %d\n", i, freq[i]);
    }
    return 0;
}