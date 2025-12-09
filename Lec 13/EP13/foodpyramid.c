#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// https://www.programiz.com/online-compiler/2NTZ7lceQBJn1

typedef struct Foods {
    char food[100];
    int cal;
    char cat[100];
} Foods;

int cmpcal1(const void *a, const void *b) {
    int c1 = (*((const Foods**)a))->cal;
    int c2 = (*((const Foods**)b))->cal;
    
    if (c1 > c2) return 1;
    else if (c1 == c2) return 0;
    else return -1;
}

int cmpcal2(const void *a, const void *b) {
    int c1 = (*((const Foods**)a))->cal;
    int c2 = (*((const Foods**)b))->cal;
    
    if (c1 < c2) return 1;
    else if (c1 == c2) return 0;
    else return -1;
}

int main() {
    // Write C code here
    int n, g=0,b=0;
    scanf("%d", &n);
    
    Foods **gf = malloc(n * sizeof(Foods*));
    Foods **bf = malloc(n * sizeof(Foods*));
    for (int i=0;i<n;i++) {
        char v1[100];
        int v2;
        char v3[100];
        scanf("%s %d %s", v1, &v2, v3);
        if (strcmp(v3, "healthy") == 0) {
            gf[g] = malloc(sizeof(Foods));
            strcpy(gf[g]->food, v1);
            gf[g]->cal = v2;
            strcpy(gf[g]->cat, v3);
            g++;
        }
        else {
            bf[b] = malloc(sizeof(Foods));
            strcpy(bf[b]->food, v1);
            bf[b]->cal = v2;
            strcpy(bf[b]->cat, v3);
            b++;
        }
    }
    
    qsort(gf, g, sizeof(Foods*), cmpcal1);
    qsort(bf, b, sizeof(Foods*), cmpcal2);
    
    for (int j=0;j<b;j++) {
        Foods *entry = bf[j];
        printf("Food: %s, Calories: %d, Category: %s\n",
            entry->food,
            entry->cal,
            entry->cat
        );
    }
    for (int j=0;j<g;j++) {
        Foods *entry = gf[j];
        printf("Food: %s, Calories: %d, Category: %s\n",
            entry->food,
            entry->cal,
            entry->cat
        );
    }
    
    for (int i = 0; i < g; i++) {
        free(gf[i]);
    }
    for (int i = 0; i < b; i++) {
        free(bf[i]);
    }
    
    free(gf);
    free(bf);

    return 0;
}