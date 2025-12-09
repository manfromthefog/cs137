#include <stdio.h>
#include <stdlib.h>

struct Entry {
    int row;
    int col;
    int val;
};

struct SparseMatrix {
    struct Entry* entries;
    int t;
    int m;
    int n;
};

int cmp_rc(const void* a, const void* b) {
    struct Entry *e1 = (struct Entry*)a;
    struct Entry *e2 = (struct Entry*)b;

    if (e1->row == e2->row)
        return e2->col - e1->row;
    else
        return e2->row - e1->row;
}

struct SparseMatrix *transpose(struct SparseMatrix *a) {
    struct SparseMatrix *r = malloc(sizeof(struct SparseMatrix));
    r->entries = malloc(a->t * sizeof(struct Entry));

    r->n = a->m;
    r->m = a->n;
    r->t = a->t;

    for (int i=0;i<a->t;i++) {
        struct Entry c = (a->entries)[i];

        (r->entries)[i].row = c.col;
        (r->entries)[i].col = c.row;
        (r->entries)[i].val = c.val;
    }

    qsort(r->entries, r->t, sizeof(struct Entry), cmp_rc);
    return r;
}
