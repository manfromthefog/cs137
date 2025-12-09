#include "poly.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct polynode {
    int deg;
    double coeff;
    struct polynode *next;
} polynode; // Type of each element in the linked list

typedef struct poly {
    struct polynode *head;
} poly; // head points at polynode

poly *polyCreate() {
    poly *p = malloc(sizeof(poly)); // this actually gets the whole data structure of the array
    p->head = NULL; // same as (*p).head;
    return p;
}

// curnode points to the node to be deleted/freed, the first node 
// in the list. The head will point to the next node after currnode
// After freeing all the data/nodes, free the pointer to poly.
void polyDelete(poly *p) {
    // How do we wipe all the nodes? We start from head and start yinging

    // we start from a pointer that shares the address as p.head (which points at [A])
    polynode *curnode = p->head;
    while (p->head) {
        // what this means is, point head at the next node after the one it's currently pointing at.
        // Let's say we have a list p -> head -> [A] [B] [C] -> NULL
        // now it's p -> head -> [B] [C] -> NULL
        p->head = p->head->next;

        // curnode is still pointing at [A], so that's the node we free
        free(curnode);
        
        // curnode -> [B] [C] NULL
        // p -> head -> [B] [C] NULL
        curnode = p->head;

        // in the next iteration, p->head -> [C] NULL and curnode will free [B]
    }
    free(p);
}

double polyEval(poly *p, double x) {
    double f = 0.0;
    // eg 2x^4 + 5x^3 + 2
    // p->head -> [4,2] -> [3,5] -> [0,2] -> NULL 
    
    // node now points at [4,2]
    polynode *node = p->head;

    // Iterate over the nodes (items) until node is NULL and
    // evaluate each appropriately

    // condition: node is not null
    // what we do: node -> [3,5]
    for (;node;node = node->next) {
        f += pow(x, node->deg) * node->coeff;
    }
    return f;
}

// What if we want to create a brand new element with a specific degree and coefficient
poly *polySetCoeff(poly *p, int deg, double coeff) {
    // p->head -> [node]
    polynode *node = p->head;
    if (!node || deg > node->deg) {
        // We add to the front, we need to allocate space for a new node
        polynode *r = malloc(sizeof(polynode));
        r->coeff = coeff;
        r->deg = deg;
        // [r] -> [node]
        r->next = node;
        // p->head -> [r] [node]
        p->head = r;
        return p;
    }
    // find the right place to add the node
    polynode *cur = p->head;
    for (;cur->next && cur->next->deg > deg; cur=cur->next);
    // if we happen to have the same degree, set coeff
    if (cur->next && cur->next->deg == deg) {
        cur->next->coeff = coeff;
    } else {
        polynode *r = malloc(sizeof(polynode));
        r->coeff = coeff;
        r->deg = deg;
        // [r] -> [...] <- [cur]
        r->next = cur->next;
        // [cur] -> [r] -> [...]
        cur->next = r;

        // if we tried doing this in reverse
        // [cur] -> [r] (cur.next = r)
        // [r] -> [r] ??? (r.next = cur.next)
    }
    return p;
}

// Assuming our polynomial is sorted correctly
// Returns the degree of our polynomial (highest power)
int polyDegree(poly *p) {
    assert(p);
    return p->head->deg;
}

// make a copy of a linked list
poly *polyCopy(poly *p) {
    poly *q = polyCreate();
    polynode *node = p->head;
    while (node) {
        q = polySetCoeff(q, node->deg, node->coeff);
        node = node->next;
    }
    return q;
}

int main(void){
    // Create 3x^4 + 2.5x^2 - 10
    struct poly *p = polyCreate();  
    p = polySetCoeff(p, 4, 3.0);
    p = polySetCoeff(p, 2, 2.5);
    p = polySetCoeff(p, 0, -10.0);
    // Print results for first poly
    printf("p(0)=%.2f\n", polyEval(p, 0)); //output: p(0)=-10.00
    printf("p(1)=%.2f\n", polyEval(p, 1)); //output: p(1)=-4.50
    printf("degree=%d\n", polyDegree(p)); //output: degree=4
    // Create a copy
    struct poly *p2 = polyCopy(p);

    // Delete the first poly
    // Important to free all allocated memory to avoid memory leak.
    polyDelete(p);
    // Print results for the copy poly. Same output as above.
    printf("p2(0)=%.2f\n", polyEval(p2, 0));
    printf("p2(1)=%.2f\n", polyEval(p2, 1));
    printf("degree=%d\n", polyDegree(p2));
    // Delete the second poly
    // Important to free all allocated memory to avoid memory leak.
    polyDelete(p2);
    return 0;
} // end of main