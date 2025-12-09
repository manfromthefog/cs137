#ifndef BISECTION_H
#define BISECTION_H
#include <math.h>

/***
 * Pre:  Epsilon > 0 is a tolerance, iterations > 0,
 *       f(x) has only one root in [a,b], f(a)f(b) < 0
 * Post: Returns an approximate root of f(x) using bisection method. Stops when either number of iterations is 
 *       exceeded or |f(m)| < epsilon
***/

double bisect(double a, double b, double epsilon, int iter, double (*f) (double));

#endif