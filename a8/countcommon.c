#include <stdio.h>
#include <assert.h>

/**
 * count_common(a[],n1,b[],n2)
 * Finds the number of common elements between two arrays of integers, excluding duplicates.
 */
int count_common(long long int a[], long long int n1, long long int b[], long long int n2) {
    // We need to initialize indicies for both arrays
    int i = 0, j = 0, c = 0;
    // Because they are sorted, we can use a "highest" variable to strike out duplicates
    // IDK if "natural numbers" includes 0 or not
    int highest = -1;
    
    while (i < n1 && j < n2) { // O(max(n1, n2)) = O(n)
        if (a[i] == b[j]) { // O(1)
            // Equal, but we accounted for them already
            if (a[i] != highest && b[j] != highest) // O(1)
                c++;
            
            // We account for the most recent equality we had
            // If this happens again we know to not account for it
            highest = a[i++];
        }
        // Move forward on the array with the smaller value until it "catches up"
        // This gurantees full coverage of all possible duplicate values
        else if (a[i] > b[j]) // O(1)
            j++;
        else if (a[i] < b[j]) // O(1)
            i++;
    }
    return c;
}

/*
int main(void){
    long long int a1[4] = {1,1,1,1};
    long long int b1[8] = {1,1,1,1,1,1,1,1};
    assert(1 == count_common(a1,4,b1,8));
    long long int a2[8] = {1,3,3,4,5,8,9,100};
    long long int b2[7] = {4,4,8,15,20,40,100};
    assert(3 == count_common(a2,8,b2,7));
    long long int a3[12] = {2,4,4,6,6,6,8,10,10,10,10,10};
    long long int b3[12] = {2,2,2,2,2,4,6,8,8,8,8,10};
    assert(5 == count_common(a3,12,b3,12));
   
    return 0;
}
*/
