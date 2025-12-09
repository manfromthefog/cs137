#include <stdbool.h>
#include "LinkedList.h"
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *curnode = head;
    int n = 0;

    while (curnode) {
        curnode = curnode->next;
        n++;
    }
    curnode = head;
    int *lle = malloc(n * sizeof(struct ListNode*));
    for (int i=0;i<n;i++) {
        lle[i] = curnode->val;
        printf("%d\n", curnode->val);
        curnode = curnode->next;
    }

    for (int j=0;j<n/2;j++) {
        if (lle[j] != lle[n-j-1]) {
            return false;
        }
    }
    free(lle);
    return true;
}