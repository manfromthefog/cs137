#include <stdio.h>

/*
We go by even and odd numbered rows in recursion.

Base Case
There are no more apples or oranges to build a valid row.
In other words, a < row or b < row, then we have to return the number of the previous row that could be built by that fruit, or row - 2.

Inductive Step
Assume for any arbitrary odd row, we want to build the next row.
# fruits = n - # fruits on that row, move on to the next row requirement, which is always row + 2

For any even row, it's the exact same thing, except we subtract from the other fruits since rows are alternating.

Conclusion
We build with either fruit and see which one is highest.
*/

int triangle(int a, int b, int row) {
    if (b < row || a < row) return row - 2;
    
    if (row % 2 == 0) { // Case where the # of rows is even, therefore 
        return triangle(a, b - row, row + 1);
    }
    else {
        return triangle(a - row, b, row + 1);
    }
}

int fruit(int apple, int orange) {
    int x = triangle(apple, orange, 1);
    int y = triangle(orange, apple, 1);
    return (x > y) ? x : y;
}

int main(void) {
    printf("%d\n", fruit(2, 4));
    return 0;
}