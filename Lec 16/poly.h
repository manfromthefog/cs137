#ifndef POLY_H
#define POLY_H

// Order polynomial so the largest degree is at the beginning
struct polynode;
struct poly;
//Pre: None
//Post: Creates a null polynomial
struct poly *polyCreate(void);

//Pre: *p is a valid polynomial (even null)
//Post: Destroys the polynomial
void polyDelete(struct poly *p);

//Pre: poly *p is valid
//Post: Returns p(x)
double polyEval(struct poly *p, double x);

//Pre: poly *p is valid, deg is non-negative
//Post: Sets the coefficient at degree to be coeff
//Assume: deg not in poly
struct poly *polySetCoeff(struct poly *p, int deg, double coeff);

//Pre: poly *p is valid
//Post: returns largest nonzero entry in poly
int polyDegree(struct poly *p);

//Pre: poly *p is valid
//Post: returns a polynomial copy of it.
struct poly *polyCopy(struct poly *p);

#endif