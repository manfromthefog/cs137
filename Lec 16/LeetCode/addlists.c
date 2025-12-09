#include <stdlib.h>
#include "LinkedList.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;

    int carry = 0;
    int v1, v2, digit, sum;

    // The carry is in case we have an extra carry after l1 and l2 are exhausted
    while (l1 || l2 || carry) {
        v1 = l1 ? l1->val : 0;
        v2 = l2 ? l2->val : 0;
        
        sum = v1+v2+carry;
        digit = sum % 10;
        carry = sum / 10;

        struct ListNode *curnode = malloc(sizeof(*curnode));

        curnode->val = digit;
        curnode->next = NULL;

        // first iteration, initialize head and tail
        if (!head) {
            head = curnode;
            tail = curnode;
        }
        // head exists
        else {
            // set the next one to curnode and make tail point to it
            tail->next = curnode;
            tail = curnode;
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return head;
}