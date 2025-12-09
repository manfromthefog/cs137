#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// https://www.programiz.com/online-compiler/5DnbiYFeM04J6

struct llnode {
    int item;
    struct llnode *next;
};

struct ll {
    struct llnode *head;
};

/*** TESTING FUNCTIONS ***/

void push_back(struct ll *list, int v) {
    struct llnode *n = malloc(sizeof(struct llnode));
    n->item = v;
    n->next = NULL;
    
    if (list->head == NULL) {
        list->head = n;
        return;
    }
    
    struct llnode *c = list->head;
    while (c->next) {
        c=c->next;
    }
    c->next = n;
}

void print_list(struct ll *list) {
    struct llnode *p = list->head;
    while (p) {
        printf("%d ", p->item);
        p = p->next;
    }
    printf("\n");
}

void free_list(struct ll *list) {
    struct llnode *p = list->head;
    while (p) {
        struct llnode *t = p->next;
        free(p);
        p = t;
    }
    list->head = NULL;
}

/*** IMPLEMENTIONS ***/

struct llnode *rl_helper(struct llnode *cur, struct llnode *prev) {
    if (cur == NULL)
        return prev;
    
    struct llnode *t = cur->next;
    cur->next = prev;
    
    return rl_helper(t, cur);
}

void reverse_list_recur(struct ll *list) {
    assert(list);
    struct llnode *prev = list->head;
    struct llnode *cur = NULL;
    
    if (list->head->next == NULL) return;
    else cur = list->head->next;
    
    // first detach
    prev->next = NULL;
    
    list->head = rl_helper(cur, prev);
}

void reverse_list_iter(struct ll *list) {
    assert(list);
    struct llnode *prev = list->head;
    struct llnode *cur = NULL;
    
    if (list->head->next == NULL) return;
    else cur = list->head->next;
    
    // first detach
    prev->next = NULL;
    
    struct llnode *t = NULL;
    while (cur) {
        t = cur->next;
        cur->next = prev;
        prev = cur;
        cur = t;
    }
    list->head = prev;
}

/*** MAIN FUNCTION ***/

int main(void) {
    struct ll list = { .head = NULL };
    struct ll *l = &list;
    int x;

    while (scanf("%d", &x) == 1) {
        push_back(&list, x);
    }

    print_list(l);
    // reverse_list_iter(l);
    reverse_list_recur(l);
    print_list(l);
    
    free_list(l);
    return 0;
}
