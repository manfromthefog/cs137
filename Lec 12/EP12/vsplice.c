#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
// #include "vectors.h"

// --- RE-PASTE YOUR STRUCT AND CREATE/ADD FUNCTIONS HERE ---
struct vector {
    int *arr;
    int size, len; 
    // actual size, len is how many are assigned
    // when size == len, the array is full
};

struct vector *vectorCreate(void) {
    // malloc returns NULL if not successful
    struct vector *v = malloc(sizeof(struct vector));
    assert(v);

    v->size = 4; // (*v).size, actual size
    v->arr = malloc(4 * sizeof(int));
    assert(v->arr);

    v->len = 0; // we put no integers in the array yet
    return v;
}

struct vector *vectorDelete(struct vector *v) {
    if (v) {
        free(v -> arr);
        free(v);
    }
    return NULL;
}

void vectorAdd(struct vector *v, int value) {
    assert(v);
    if (v->len == v->size) {
        // if arr is full
        int new_size = v->size * 2;
        // allocate the new size
        int *new_arr = malloc(new_size * sizeof(int));
        for (int i = 0; i < v->size; i++) {
            *(new_arr + i) = *(v->arr + i);
        }
        new_arr[v->size] = value;
        v->arr = realloc(new_arr, new_size * sizeof(int));
        // free(v->size);
        v->size = new_size;
        v->arr = new_arr;
    }
    else {
        v->arr[v->len] = value;
    }
    ++v->len;
}

void vectorSet(struct vector *v, int ind, int value) {
    assert(v && ind >= 0 && ind < v->len);
    v->arr[ind] = value;
}

int vectorGet(struct vector *v, int ind) {
    assert(v && ind >= 0 && ind < v->len);
    return v->arr[ind];
}

int vectorLength(struct vector *v) {
    assert(v);
    return v->len;
}

// --- YOUR TASK ---
void vectorSplice(struct vector *dst, struct vector *src, int index) {
    assert(dst && src);
    assert(index >= 0 && index <= dst->len); // index == len is valid (append)

    if (!vectorLength(src)) return;

    int n = vectorLength(dst);
    int m = vectorLength(src);

    for (int i=0;i<m;i++) {
        vectorAdd(dst, 0);
    }
    // shift right by m
    // n is the old length, actual length is n+m
    for (int i=n-1;i>=index;i--) {
        int s = vectorGet(dst, i);
        vectorSet(dst, i+m, s);
    }
    // enter the new entries
    for (int j=0;j<m;j++) {
        int e = vectorGet(src, j);
        vectorSet(dst, j+index, e);
    }
}

// --- TEST ---
void printVector(struct vector *v) {
    printf("[");
    for (int i = 0; i < v->len; i++) {
        printf("%d%s", v->arr[i], i == v->len - 1 ? "" : ", ");
    }
    printf("]\n");
}

int main(void) {
    struct vector *v1 = vectorCreate();
    struct vector *v2 = vectorCreate();

    // Setup v1: [10, 20, 30]
    vectorAdd(v1, 10);
    vectorAdd(v1, 20);
    vectorAdd(v1, 30);

    // Setup v2: [99, 98]
    vectorAdd(v2, 99);
    vectorAdd(v2, 98);

    printf("Start v1: "); printVector(v1);
    printf("Start v2: "); printVector(v2);

    printf("\nTest 1: Splicing v2 into v1 at index 1...\n");
    printf("Expected: [10, 99, 98, 20, 30]\n");
    vectorSplice(v1, v2, 1);
    printf("Actual:   "); printVector(v1);

    printf("\nTest 2: Splicing v2 into v1 at index 0 (Prepend)...\n");
    printf("Expected: [99, 98, 10, 99, 98, 20, 30]\n");
    vectorSplice(v1, v2, 0);
    printf("Actual:   "); printVector(v1);

    printf("\nTest 3: Splicing v2 into v1 at end (Append)...\n");
    printf("Expected: [99, 98, 10, 99, 98, 20, 30, 99, 98]\n");
    vectorSplice(v1, v2, v1->len);
    printf("Actual:   "); printVector(v1);

    // Cleanup (Assuming you implement vectorDelete properly)
    vectorDelete(v1); 
    vectorDelete(v2);
    
    return 0;
}