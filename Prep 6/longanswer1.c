#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct ll {
    struct llnode *head;
};

struct llnode {
    int item;
    struct llnode *next;
};

// the linked list is in ascending order
// remove all nodes that are duplicates

struct ll *create_list() {
    struct ll *h = malloc(sizeof(struct ll));
    h->head = NULL;
    return h;
}

void print_list(struct ll *list) {
    struct llnode *rn = list->head;
    for (;rn;rn=rn->next) {
        printf("%d->", rn->item);
    }
    printf("HEAD");
}

// any errors you might spot?
void remove_duplicates(struct ll *list) {
    if (list == NULL) return;
    struct llnode h;
    h.next = list->head;

    struct llnode *p = &h;
    struct llnode *c = list->head;

    while (c) {
        bool isduplicate = false;
        // makes sense since the ll is sorted
        // c->next could seg fault =) !!!
        while (c->next != NULL && c->item == c->next->item) {
            isduplicate = true;
            struct llnode* sg = c->next;
            c->next = sg->next;
            free(sg);
        }
        // remove the current node as well
        if (isduplicate) {
            struct llnode* ct = c;
            c = c->next; // advance current pointer
            free(ct); // free og mem addr
            // p now points to c, which is advanced
            p->next = c; 
        } else {
            // move forward
            p = c;
            c = c->next;
        }

        //list->head = h.next;
    }
}