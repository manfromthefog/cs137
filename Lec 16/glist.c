#include "glist.h"
#include "poly"
#include <stdlib.h>
#include <stdio.h>

typedef struct llnode {
    void *data;
    struct llnode *next;
} llnode;

typedef struct gl {
    llnode *head;
} gl;


gl *gl_Create(void) {
    gl *ret = malloc(sizeof(gl));
    ret->head = NULL;
    return ret;
}

void gl_addToFront(gl *lst, void *elem) {
    llnode *newNode = malloc(sizeof(llnode));
    newNode->data = elem;
    newNode->next = lst->head;
    lst->head = newNode;
}

void gl_addInOrder(gl *lst, void *elem, int (*cmp) (void *, void *)){
    llnode *prev = NULL;
    llnode *cur = lst->head;
    // After this loop we want to insert elem right after prev , right before cur.
    for (;cur && cmp(elem, cur->data) > 0; prev = cur, cur = cur->next);
    // Check if we must update head
    if (!prev)
        gl_addToFront(lst, elem);
    else {
        llnode *n = malloc(sizeof(llnode));
        n->data = elem;
        n->next = cur;
        prev->next = n;
    }
}

void gl_delete(gl *lst, void (*kill)(void *)){
    llnode *nextnode = lst->head;
    llnode *curnode = NULL;
    while (nextnode) {
        curnode = nextnode;
        nextnode = nextnode->next;
        kill(curnode->data);
        free(curnode);
    }
    free(lst);
}
int gl_length(gl *lst){
    int len = 0;
    llnode *node = lst->head;
    // iterate over the nodes (items) until node is NULL and count
    for (; node; node = node->next)
        len++;
    return len;
}

void *gl_nthElem(struct gl *lst, int n){
    assert(n <= gl_length(lst));
    int num;
    llnode *node = lst->head;
    for (num = 1; num < n; num++)
        node = node->next;
    return node->data;
}

// *(*cpy)(void *) means "pointer to a function of type pointer that takes argument void pointer"
llnode *llnode_copy(llnode *n, void *(*cpy)(void *)){
    // very different recursive approach
    // well... not really
    if (!n)
        return NULL;
    
    llnode *ret = malloc(sizeof(llnode));
    // we are saying "the next of ret is whatever thing copied to llcopy"
    ret->next = llnode_copy(n->next, cpy);
    ret->data = cpy(n->data);
    return ret;
}

gl *gl_copy(gl *lst, void *(*cpy) (void *)) {
    gl *ret = malloc(sizeof(gl));
    ret->head = llnode_copy(lst->head, cpy);
    return ret;
}