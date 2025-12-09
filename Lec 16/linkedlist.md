# Linked List Structure

A typical data structure were data are individual pieces stored together, and it is easy to insert new data.
A linked list consists of...
1. A piece of data (for now, an integer)
2. A pointer to the next element in the list or NULL if it is the last element in the list.

# Implementation
```C
struct ll {
    struct llnode * head; // hold the start of the list
}
struct llnode {
    int item
    struct llnode * next;
}
```

# Polynomial

Let's map the polynomial y=8x<sup>3</sup>+3x+3.

We will include the power and coefficient for each term. We also want the polynomials to be sorted in descending power. Reference the interface file `poly.h`.

# Generalized Lists

We discussed linked lists for integers, and polynomial terms, but what if we wanted linked lists of other structures, like a LL of floats, new structure, arrays, or even more LLs?

Observe, a `void*` can point at anything. This is how generalizations are done in C.

## Deep Copy

Copying lists is a common practice, but when creating copies of arrays or objects, we can make shallow copies of deep copies. A shallow copy, we use a variable that shares the reference of the original object, but in a deep copy, we create a true copy disconnected to the original list.

To make a deep copy, we also need to create a new node for each node in the list we want to copy.

Take a look at `glist.h`.