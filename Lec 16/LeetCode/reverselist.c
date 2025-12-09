#include <stdlib.h>
#include "LinkedList.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *next = NULL;
    struct ListNode *cur = head;
    struct ListNode *prev = NULL;
    while (cur) {
        // iter final, cur=5

        // next -> NULL
        next = cur->next;
        // curnode.next = prev = 4
        cur->next = prev;
        // prevnode = cur = 5;
        prev = cur;
        // cur = NULL
        cur = next;

        // NULL<-1<-2<-3<-4<-5<-NULL
    }
    return prev;
}