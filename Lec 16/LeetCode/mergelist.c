#include "LinkedList.h"
#include <stdlib.h>

struct ListNode* merger(struct ListNode *dest, struct ListNode *src) {
    struct ListNode* p1 = dest;
    struct ListNode* p2 = src;

    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* tail = head;

    while (p1 != NULL && p2 != NULL) {
        // standard merging logic
        if (p1->val < p2->val) {
            tail->next = p1;
            tail = p1;
            p1=p1->next;
        }
        else {
            tail->next = p2;
            tail = p2;
            p2=p2->next;
        }
    }
    // same in merge sort, append stranded elements
    if (p1 != NULL) {
        tail->next = p1;
        tail = p1;
    }
    if (p2 != NULL) {
        tail->next = p2;
        tail = p2;
    }
    
    return head->next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;

    /* pov: you've never seen merge sort
    struct ListNode* r = lists[0];
    for (int i=1;i<listsSize;i++) {
        r = merger(r, lists[i]);
    }
    */

    while (listsSize > 1) { // O(logn) witn O(n) function called
        int mid = (listsSize + 1)/2;
        // do it with half the data each time
        for (int i=0;i<listsSize/2;i++) {
            lists[i] = merger(lists[i], lists[i+mid]);
        }
        listsSize = mid;
    }
    return lists[0];
}