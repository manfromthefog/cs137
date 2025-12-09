#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/***
 * maxsequence(a[], n)
 * Finds the largest consecutive sum in a list of integers. 
 * return: largest consecutive sum, zero if all elements are negative
 * requires: list of integers
 */
int maxsequence(int a[], int n) {
    // sum everything
    int max = 0, sub_max = 0;
    
    for (int i=0;i<n;i++) { // O(n)
        // keep adding
        sub_max += a[i];
        if (sub_max > max)
            // find the cumulative max
            max = sub_max;
        if (sub_max < 0) 
            // if the sum goes negative any time, reset the sum
            sub_max = 0;
    }
    return max;
}

/*
int main()
{
    int a[] = {-2,-4,3,-1,5,6,-7,-2,4,-3,2};
    int n = sizeof(a)/sizeof(int);
    assert(maxsequence(a, n) == 13);

    int b[] = {-2,-4,-3,-1};
    n = sizeof(b)/sizeof(int);
    assert(maxsequence(b, n) == 0);

    int c[] = {1,2,3,4,5,6};
    n = sizeof(c)/sizeof(int);
    assert(maxsequence(c, n) == 21);

    int d[] = {-2,-3,4,-1,-2,1,5,-3};
    n = sizeof(d)/sizeof(int);
    assert(maxsequence(d, n) == 7);

    int e[] = {1,-2,-3,-4,0,67};
    n = sizeof(e)/sizeof(int);
    assert(maxsequence(e, n) == 67);

    return 0;
}
*/
