#include <stdio.h>
#include <stdlib.h>
// https://www.programiz.com/online-compiler/8WafxTtPI3Gpm

typedef struct Item {
    int val;
    int freq;
} Item;

int cmp_freq(const void *a, const void *b) {
    const Item* n1 = (const Item*)a;
    const Item* n2 = (const Item*)b;
    
    if (n1->freq == n2->freq) return n2->val - n1->val;
    else return n2->freq - n1->freq;
}

void freq_sort(int *a, int n) {
    int f[201] = {0};
    for (int i=0;i<n;i++) {
        ++f[a[i] + 100];
    }
    
    Item *r = malloc(n * sizeof(Item));
    for (int i=0;i<n;i++) {
        r[i].val = a[i];
        r[i].freq = f[a[i] + 100];
    }
    
    qsort(r, n, sizeof(Item), cmp_freq);
    for (int i=0;i<n;i++)
        a[i] = r[i].val;
    
    free(r);
}

int main() {
    // Write C code here
    int orders[9] = {-1,1,-6,4,5,-6,1,4,1};
    int n = 9;
    freq_sort(orders, n);
    
    for (int i=0;i<n;i++)
        printf("%d ", orders[i]);
    printf("\n");
    return 0;
}