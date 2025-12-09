#include "vectors.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

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


int main(void) {
    struct vector *v = vectorCreate();
    for (int i = 0; i < 20; ++i) {
        vectorAdd(v, i);
    }
    printf("%d\n\n", vectorLength(v));
    for (int i = 0; i < 20; ++i) {
        printf("v[%d]=%d ", i, vectorGet(v, i));
    }
    printf("\n\n");
    for (int i = 0; i < 20; ++i) {
        vectorSet(v, i, i * i);
        printf("v[%d]=%d ", i, vectorGet(v, i));
    }
    printf("\n\n");
    v = vectorDelete(v);
    if (v==NULL) printf("Success!\n");
    else printf("Freeing was not completed successfully!\n");
    return 0;
}