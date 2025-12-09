#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ll {
    struct llnode *head;
};

struct llnode {
    int item;
    struct llnode *next;
};

// front approach
/*
void double_it(struct ll *list) {
    struct llnode *c = list->head;
    while(c) {
        struct llnode *n = malloc(sizeof(struct llnode));
        n = c;
        n->next = c->next;
        c->next = n;
    }
    c = c->next->next;
}
*/

// back approach
void double_it(struct ll *list) {
    for (struct llnode *c = list->head;c;c=c->next) {
        struct llnode *cpy = malloc(sizeof(struct llnode));
        // add before approach
        cpy->next = c;
        cpy->item = c->item;

        // we also need to handle special head logic
        if (list->head == c) {
            list->head = cpy;
        }
        // link the previous to the new cpy
        else if (c != list->head) {
            struct llnode *trailer = list->head;
            for (;trailer->next != c;trailer=trailer->next);
            trailer->next = cpy;
        }
    }
    
}