#ifndef GLIST_H
#define GLIST_h

struct llnode;
struct gl;

struct gl *gl_Create(void);

//Pre: elem is a pointer to heap-allocated data that this list now owns.
//Adds a new node storing elem at the front of our list.
void gl_addToFront(struct gl *lst, void *elem);

/**
 * Adds a node storing elem to lst in sorted order wrt cmp.
 * 
 * Pre: lst is already sorted wrt to cmp.
 * cmp(a,b) returns:<0 if a should be before b==0 if a==b>0 if a should be after b
 */
// we previously saw this type of syntax with gsort()
void gl_addInOrder(struct gl *lst, void *elem, int (*cmp)(void *, void *));

//Pre: *lst is a valid lst
//Post: Destroys the list
void gl_delete(struct gl *lst, void (*kill)(void *));

//Pre: lst is valid
//Post: returns the length of lst
int gl_length(struct gl *lst);

//Pre: lst is valid
//Post: returns pointer to nth data
// Assume n is not bigger than the length of the list
void *gl_nthElem(struct gl *lst, int n);

// cpy provided by the user
// deep copy
struct gl *gl_copy (struct gl *lst, void *(*cpy)(void *));

#endif
