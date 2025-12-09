#ifndef VECTOR_H
#define VECTOR_H

struct vector ;

//will create a new empty vector.
struct vector *vectorCreate(void);

//deletes the vector *v. Returns NULL on success.
//(return NULL to allow for v=vectorDelete(v);)
struct vector *vectorDelete(struct vector *v);

//adds val to the end of the vector. Allocates new space as necessary.
void vectorAdd(struct vector *v, int val);

//sets value in index ind to be val.
void vectorSet(struct vector *v, int ind , int val);

//returns element at index ind.
int vectorGet(struct vector *v, int ind);

//returns the length of the vector *v.
int vectorLength(struct vector *v);

# endif
