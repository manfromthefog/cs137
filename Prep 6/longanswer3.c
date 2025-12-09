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

/**
 * A "balanced" node means the sum of everything to its left is
 * the same to everything of its right!
 */
bool has_balanced(struct ll *list) {
    int total_sum = 0;
    for (struct llnode *n=list->head;n!=NULL;n=n->next) total_sum += n->item;

    int left_sum = 0;
    for (struct llnode *n=list->head;n!=NULL;n=n->next) {
        // the right sum == left sum
        if (total_sum - left_sum - n->item == left_sum) return true;
        left_sum += n->item;
    }
    return false;
}