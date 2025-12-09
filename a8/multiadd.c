#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// performs the multiplication operation on the pointer to an ascending array
void multi(long long int **arr, int *n) {
    // the length gets cut in half
    long long int *multi = calloc(*n/2, sizeof(long long int));
    // multiply pairs, two at a time
    for (int i=0,j=0;j<*n;i++,j+=2) {
        multi[i] = (*arr)[j] * (*arr)[j+1];
    }
    // free the old array
    free(*arr);
    *arr = multi; // replace with new one
    *n /= 2;
}

// performs the add() operation on the pointer to an ascending array
void add(long long int **arr, int *n) {
    // the length gets cut in half again
    long long int *add = calloc(*n/2, sizeof(long long int));
    // add pairs, two at a time
    for (int i=0,j=0;j<*n;i++,j+=2) {
        add[i] = (*arr)[j] + (*arr)[j+1];
    }
    free(*arr);
    *arr = add; // replace with new one
    *n /= 2;
}

/**
 * multiadd(a[], n)
 * Continues applying the multiply and add operations to an array of integers
 * Until all elements are reduced into one final value
 * 
 * returns: the final value
 */
long long int multiadd(long long int a[], int n){
    // all values in the array are less or equal to n
    long long int *number_freq = calloc(n+1, sizeof(long long int));
    for (int i=0;i<n;i++) {
        number_freq[a[i]]++;
    }

    // now, we have an integer frequency array
    long long int *multi_init = malloc(n/2 * sizeof(long long int));
    int n1=0,n2=0;
    for (int i=0,j=0;i<n/2;i++) { // O(n)
        // find the first number with frequency
        while (number_freq[j] == 0) j++; // only increments, does not change complexity
        number_freq[j]--;
        n1=j; // set this as our first number
        
        // if there's more of that number
        // do it again, if not, move on
        while (number_freq[j] == 0) j++;
        number_freq[j]--;
        n2=j; // our second number
        
        multi_init[i] = n1 * n2; // multiply them
    }
    free(number_freq);

    // We now have a fully sorted ascending array
    // That also went through step 1
    n /= 2;
    while (n > 1) { // O(n) + O(n/2) + O(n/4) + ... = O(n)
        add(&multi_init, &n); // O(prev/2)
        if (n==1) break;
        multi(&multi_init, &n); // O(prev/4)
    }
    // one element left
    long long int res = multi_init[0];
    free(multi_init); // free the final allocation
    return res;
}

/*
int main(void){
    long long int a[8] = {1,4,3,6,5,3,2,8};
    assert(748 == multiadd(a,8));
    long long int b[16] = {0};
    assert(0 == multiadd(b,16));
    long long int c[16] = {1,6,5,8,6,7,5,4,8,9,10,2,12,14,1,1};
    assert(27498 == multiadd(c,16));
    long long int d[32] = {29, 30, 30, 21, 15, 27, 5, 1, 25, 21, 11, 21, 28, 10, 20, 19, 26, 20, 17, 26, 30, 21, 21, 24, 11, 16, 29, 32, 32, 0, 27, 9};
    assert(2695906912431 == multiadd(d,32));
    
    return 0;
}
*/
