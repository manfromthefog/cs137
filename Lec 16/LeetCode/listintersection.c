#include "LinkedList.h"
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *tailA = headA;
    struct ListNode *tailB = headB;

    int cA=0, cB=0;
    for (;tailA->next;tailA=tailA->next) cA++;
    for (;tailB->next;tailB=tailB->next) cB++;

    if (tailA->val != tailB->val) return NULL;

    if (cA > cB)
        for (int i=0;i<cA-cB;i++) headA=headA->next;
    else
        for (int i=0;i<cB-cA;i++) headB=headB->next;

    for (;headA && headB;headA=headA->next, headB=headB->next) {
        if (headA == headB)
            return headA;
    }
    return NULL;
}