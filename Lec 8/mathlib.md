# Floating Point Numbers

1. Floats are type _float_, doubles are type _double_
2. Floats are 4 bytes and doubles are 8 bytes
3. Floats are precise to 7 digits and doubles are precise to 16 digits
4. Floats have exponents up to `e+/-38` and doubles have exponents up to `e+/-308`

## Conversion Specifications

There are many different ways we can display these numbers using the printf
command. They, in general, have the format %± m.pX where
- ± is the right or left justification of the number, depending on
- If the sign is positive or negative, respectively
- m is the minimum field width, that is, how many spaces to leave for numbers
- p is the precision (this heavily depends on X as to what it means)
- X is a letter specifying the type (see next slide)

## Errors

Notice that these floating-point numbers only store rational numbers; they cannot store real numbers (though there are CAS packages like Sage which try to).

This is okay since the rational numbers can approximate real numbers as accurately as we need. When discussing approximation errors, we have two types of measures we commonly use, namely absolute and relative errors.

### Absolute Error

`| 3.14 - pi | = ...`

### Relative Error

`| 3.14 - pi | / pi = ...`

## Example

```C
#include <stdio.h>

int main(void) {
    double a = 7.0 / 12.0;
    double b = 1.0 / 3.0;
    double c = 1.0 / 4.0;
    if (b + c == a)
        printf("Everything is Awesome !");
    else
        printf("Not cool ... %g\n", b + c - a);
}
```

### Remember
Do not check for equality. These are things you are not supposed to do.
- Subtracting nearly equal numbers
- Dividing by very small numbers
- Multiplying by very large numbers
- Testing for equality

### Testing Equality

Comparing x == y is risky. To be safe, instead of using if (x == y) you can use if ((x - y) < 0.0001 || (y - x) < 0.0001).
Sometimes we call epsilon the "tolerance".

## Example

```C
#include <stdio.h>

int main(void) {
    double a = 1 / 3;
    printf("a = %g\n", a);
    return 0;
}
```

The above example will NOT return 0.3333...
We force real division in many ways.

1. double a = 1.0 / 3;
2. double b = (double)1 / 3;

# The Math Library

`#include <math.h>` is the syntax to import math.

The math library includes lots of fun functions.
- `double sin(double x)` and similarly for `cos, tan, asin, acos, atan`.
- `double exp(double x)` and similarly for `log, log10, log2, sqrt, ceil, floor`. Note log is the natural logarithm and fabs is the absolute value.
- `double fabs(double x)` is the absolute value function for floats (integer abs is in stdlib).
- `double pow(double x, double y)` gives `x^y` , the power function.
- Constants (Caution! These next two lines are not in the basic standard!):
- M_PI (Pi), M_PI_2 (Pi divided by 2), M_PI_4 (Pi divided by 4), M_E, M_LN2, M_SQRT2, INFINITY, NAN (square root of -1), MAXFLOAT

## Root Finding

Use the intermediate value theorem in a given interval. If a function f(x) is continuous on an interval `[a,b]` and f(a) * f(b) < 0, then a value c in `[a,b]` exists for which f(c) = 0.

Following the idea above, the algorithm ends when the value of f(c) is less than a defined tolerance. In this case, we say that c is close enough to be the root of the function. To avoid too many iterations, we can set amaximum number of iterations.

There are two stopping conditions possible.
1. Stop when `|f(m)| < Ɛ` for some fixed Ɛ>0 where m is the interval's midpoint. (Not great since the actual root might still be far away)
2. Stop when `|m_n - 1 – m_n| < Ɛ` (where m_n is the nth midpoint). (Much better) for f(a) * f(b) to be negative it means that f(a) is positive and f(b) is negative or vice versa.

Refer to bisection.c.

### Function Pointer

Notice that we hard-coded a definition of a function in each of the two previous examples. Ideally, the code would also have as a parameter the function itself. C lets us do these using function pointers.
- __Syntax__ 
  
  Pass a parameter double (*f)(double) a pointer to a function that takes a double and returns a double.
- __Note__ 
  
  The brackets around (*f) are important so as not to confuse this with a function that returns a pointer. In our function, we pass a pointer to another function, which takes a double as input and returns a double.

## Integration

Use the trapezoid rule function to approximate. The exact algorithm may or may not be the same 

## Polynomials

A polynomial is an expression with at least one indeterminate and coefficients lying in some set. We will primarily use integer coefficients.

We can represent a polynomial purely by its coefficients, using an array of length `n + 1`.

### Traditional Method

Compute `x, x^2, x^3, ... x^n` and multiply each of them by the coefficients. Add all the results. This gives a total of `2n - 1` multiplications and `n` additions.

Multiplication is a very expensive operation compared to addition.

### Horner's Method

Factor out nests of x. For example, `x^2 - 2x + 1` becomes `x(x - 2) + 1`. This is not very meaningful mathematically, but computationally it reduces the number of multiplications and number of additions to `n`.

We start with the coefficient of x^2.

1. Set a constant c = 1, which is the coefficient of `x^2`.
2. Multiply c by x and add the next constant, and set that value to c. By the end of this c = x - 2.
3. Repeat the above step again. Multiply x by c (which is x - 2) and add the constant term.
4. Return c.

See `polynomials.c`.