#include <stdbool.h>
#include "LinkedList.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    int i = 0;
    for (int i=0;i<n;i++) {
        if (fast) fast = fast->next; // will be at position 1, i.e. 3
    }

    // this means the nth element from the head
    // is our first element, so we free the head (edge case)
    if (!fast) {
        struct ListNode *marked = head;
        head = slow->next;
        free(marked);
        return head;
    }

    // this means fast stops at the last element
    while (fast->next) {
        slow = slow->next; // position of deletion
        fast = fast->next;
    }
    // slow marks the spot
    struct ListNode *marked = slow->next;
    slow->next = marked->next;
    free(marked); // free the marked element
    
    return head;
}