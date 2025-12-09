#include <stdio.h>
#include <stdlib.h>
// https://www.programiz.com/online-compiler/0puBe0DayY9id

int *unsay(const int* src, int src_len, int *dst_len) {
    for (int i=0;i<src_len;i+=2) {
        (*dst_len) += *(src + i);
    }
    int *d = malloc((*dst_len) * sizeof(int));
    
    for (int i=0,j=0;i<src_len,j<(*dst_len);i+=2) {
        int f = src[i];
        int k = src[i+1];
        
        for (int u=0;u<f;u++) {
            d[j+u] = k;
        }
        j += f;
    }
    return d;
}

int main() {
    int src[] = {3, 1, 1, 3, 1, 2, 1, 1, 1, 3, 1, 2, 2, 1};
    int length = 14; 
    int dst_len; 
    int *ans = unsay(src, length, &dst_len);
    for (int i = 0; i < dst_len; i++) {
        printf("%d ",ans[i]);
        if (i == dst_len - 1) printf("\n");
    } 
    free (ans);
} 