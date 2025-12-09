#include <stdio.h>
// https://www.programiz.com/online-compiler/3udWPvSx6HjRB

int fruitpyramid_helper(int a, int b, int c, int s) {
    printf("%d %d\n", a, b);
    if (a == 0 && b == 0) return c;
    if (a < 0 || b < 0) return c-1;
    c++;
    if (s == 0) 
        return fruitpyramid_helper(a, b - c, c, 1);
    else        
        return fruitpyramid_helper(a - c, b, c, 0);
}


int fruitpyramid(int a, int b) {
    int x = fruitpyramid_helper(a,b,0,0);
    int y = fruitpyramid_helper(a,b,0,1);
    printf("%d %d\n", x, y);
    return (x>y ? x:y);
}

int main() {
    // Write C code here
    printf("%d\n", fruitpyramid(9,6));

    return 0;
}