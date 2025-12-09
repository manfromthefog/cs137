# Recursive Functions

Recursive approaches is a function calling itself. Many basic math operations are recursive. A lot of things have recursive solutions.

> Trust the Process

## Example

Exponentiation
We call it repeated addition.

### Base Cases

x^0 = 1
x^1 = x

### Recursive Case

x^n = x * x^n-1
x^n-1 is a breakdown of problem. If you know x^n-1 you know x^n.

## Example 2

Factorial
n! = n(n-1)...(2)(1)

### Base Case

0! = 1

### Recursive Case

n! = n(n-1)!

> Every time factorial is called a new stack frame is created. Therefore we end up with factorial stackframes for each recursive cycle.

### Tracing Recursive Functions

Just add a print statement to reveal the stack frame.

## Fibonnaci Sequence

A recursive classic. THe next sequence is the sum of the previous two.

## Base Case

1 if x <= 1.

## Recursive Case

f(n) = f(n - 1) + f(n - 2)

Each call of the factorial function creates a new stackframe. The return function does not have two stackframes. Rather, every function call goes all the way down.

Then, from the base case fib(1) = 1 and fib(0) = 2, we have to build up. So from one case, everything needs to branch down to the base cases. It consumes a LOT of stackframe.

## Function fib_tr

fib_tr() function only calls one new stackframe per function since the recursive case intakes prev + cur, going down until the base case and then going up again.

fib(0,1,4)
fib(1,1,3)
fib(1,2,2)

A recursive function is tail-recursive if the recursive call is the last thing executed
by the function.

Usually, the desired value to be returned is accumulated via additional
parameter(s) to be returned in the base case

### Parameters

Parameters are the key method to pass information from one function to another, regardless of the function. That's another reason fib_tr is better - we can decide the number of parameters.

Fib_tr is tail recursion.

## Recursive Strategy

In the game Tower of Hanoi, remember to find a method to find a method that works for the next step if it works for the previous step. Have faith in induction.

The function solves itself.