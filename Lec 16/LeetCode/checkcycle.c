#include <stdbool.h>
#include "LinkedList.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    // we need to ensure the current node and the next nodes are not NULL
    // if next->next is NULL we're fine, it will be false on the next cycle
    while (fast && fast->next) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}