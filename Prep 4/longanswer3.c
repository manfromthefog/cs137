#include <stdio.h>
#include <stdlib.h>

/***
 * @purpose: returns a decoding array containing the sequence specified by src, modifying *dst_len to be the length of the
 * new sequence. 
 * @requires: src must be a valid array of length src_len; src_len > 1
 */
int *unsay(const int *src, int src_len, int *dst_len) {
    // Find the total decoded length
    int total = 0;
    for (int c = 0; c < src_len; c += 2) {
        total += src[c];
    }

    // Allocate memory for the decoded array
    int *decoded = malloc(total * sizeof(int));
    if (!decoded) return NULL; // allocation failed

    // Decode key-value pairs
    int position = 0;
    for (int i = 0; i < src_len; i += 2) {
        for (int j = 0; j < src[i]; j++) {
            // Starts with 0, and then increments to 1, 2, 3...
            // Position does not reset, unlike j
            decoded[position++] = src[i + 1];
        }
    }

    *dst_len = total;
    return decoded;
}

int main() {
    int src[] = {3, 1, 1, 3, 1, 2, 1, 1, 1, 3, 1, 2, 2, 1};
    int length = 14;
    int dst_len;
    int *ans = unsay(src, length, &dst_len);

    for (int i = 0; i < dst_len; i++) {
        printf("%d ", ans[i]);
        if (i == dst_len - 1)
            printf("\n");
    }
    free(ans);
    ans = NULL;
    return 0;
}