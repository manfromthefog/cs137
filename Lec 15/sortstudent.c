#include <stdio.h>
#include <stdlib.h>

struct student{
    unsigned int id;
    double avg;
};

int compare1(const void *a, const void *b){
    unsigned int p = ((const struct student *)a)->id;
    unsigned int q = ((const struct student *)b)->id;

    if (p < q) return -1;
    else if (p == q)return 0;
    else return 1;
}

int compare2(const void *a, const void *b){
    int p = *(const int*)a;
    int q = *(const int*)b;

    if (p < q) return -1;
    else if (p == q) return 0;
    else return 1;
}

int main(void) {
    struct student st[3]= {
        {333,86.7},
        {111,90.7},
        {222, 80}
    };
    qsort(st, 3, sizeof(struct student), compare1);
    for (int i = 0; i < 2; i++){
        printf("%d, ", st[i].id);
    }
    printf("%d\n", st[2].id);
    // Output: 111, 222, 333

    int a[] = { -10, 2, 14, -7, 11, 38 };
    const int n = sizeof(a) / sizeof(a[0]);
    qsort(a, n, sizeof(int), compare2);
    for (int i = 0; i < n - 1; i++){
        printf("%d, ", a[i]);
    }
    printf("%d\n", a[n - 1]);
    // Output: -10, -7, 2, 11, 14, 38
    return 0;
}