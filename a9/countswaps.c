#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/**
 * count_merge_steps(target, t, n, acc)
 * Sorts a target array of length n, and counts the number 
 * of adjacent swaps needed to achieve the same result.
 * 
 * requires: the target array is strictly whole numbers 0,1,2,...,n,
 *           not necessarily in that order
 */
void count_merge_swaps(int *target, int *t, int n, int *acc) {
    // We solve the problem using merge sort

    // Base case
    if (n <= 1) return;

    int mid = (n+1)/2;
    int *lower = target;
    int *upper = target + mid;

    count_merge_swaps(lower, t, mid, acc);
    count_merge_swaps(upper, t, n-mid, acc);

    int i=0, j=mid;
    int k=0;

    while (i < mid && j < n) {
        if (target[i] <= target[j])
            t[k++] = target[i++];
        else { 
            t[k++] = target[j++];
            // this is the critical line (explaination below)
            /**
             * For a "merge" operation, suppose we merge
             * 1,3 and 0,2 (arr)
             * 
             * The merge would be 0123
             * 
             * If we had 1302, how do sort by swaps? The only reason 
             * why we need to "swap" is when there's elements in the 
             * lower list larger than the upper element you are merging
             * 
             * upper 0
             * 1032 (swap 1)
             * 0132 (swap 2)
             * 
             * upper 2
             * 0123 (swap 3)
             * 
             * We notice, we need 3 swaps because there are 2 lower elements>0
             * and 1 lower element>2.
             * 
             * total swaps = 2 + 1 = 3
             * 
             * Let's run through a full exmaple.
             * 43201 (arr4)
             * 
             * Merge sort is powerful because we break the swap sequence down.
             * 
             * Left
             * 4 3 -> 3 4 (1 swap)
             * 3 4 2 -> 2 3 4 (2 swaps, since 3>2 and 4>2)
             * 
             * Right
             * 0 1 -> 0 1 (no swaps)
             * 
             * Final Merge
             * 2 3 4 0 1 -> (6 swaps, since 2,3,4>0 and 2,3,4>1)
             * 
             * total swaps = 1+2+6 = 9
             */
            (*acc) += (mid - i);
        }
    }

    while (i < mid)
        t[k++] = target[i++];
    while (j < n)
        t[k++] = target[j++];
    for (int i=0;i<n;i++)
        target[i]=t[i];
}

/**
 * count_min_steps(target, arr, n)
 * Counts the minimum number of adjacent swaps need to transform a starting array into a target array.
 * 
 * requires: all integers
 */
int count_min_swaps(int* target, int* arr, int n) { // ~O(n^2)
    int acc = 0;
    int *t = malloc(n * sizeof(int));
    int *target_index = malloc(n * sizeof(int));

    // O(n^2) here bad time complexity
    // Since the elements <= 1000 we can also hash map this for O(n)
    int *used = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        // Turn target into an array of indicies based on
        // the target element's position in arr
        int v = target[i];
        int found = 0;
        // Linear search on arr
        for (int j = 0; j < n; j++) {
            // during the actual assignment you forgot to do this (-2 marks)
            // a8 passed due to coincidence
            if (!used[j] && arr[j] == v) {
                used[j] = 1;              // mark this arr[j] as used
                target_index[i] = j;      // map target[i] → next available arr[j]
                found = 1;
                break;                    // IMPORTANT: stop so duplicates preserve order
            }
        }

        // if we didn't found an element swaps are impossible
        if (!found) {
            // you forgot to free during the actual assignment (-2 marks)
            free(t);
            free(target_index);
            free(used);
            return -1;
        }
    }
    count_merge_swaps(target_index, t, n, &acc); // O(nlogn)
    free(t);
    free(target_index);
    return acc;
}

int main(void) {
   
    int target[] = {2, 4, 1, 3};
    int arr[] = {1, 2, 3, 4};
    int n = 4;
    assert(count_min_swaps(target, arr, n) == 3);

    int target2[] = {7};
    int arr2[] = {7};
    int n2 = 1;
    assert(count_min_swaps(target2, arr2, n2) == 0);

    int target2b[] = {3, 9, 1, 2, 6, 8};
    int arr2b[] = {2, 1, 6, 8, 9, 3};
    int n2b = 6;
    assert(count_min_swaps(target2b, arr2b, n2b) == 10);

    int target4[] =  {1, 3, 5, 9, 7};
    int arr4[] = {9, 7, 5, 3, 1};
    int n4 = sizeof(target4) / sizeof(target4[0]);
    assert(count_min_swaps(target4, arr4, n4) == 9);
    
    int target5[] = {1, 2, 3};
    int arr5[] = {1, 2, 3};
    int n5 = sizeof(target5) / sizeof(target5[0]);
    assert(count_min_swaps(target5, arr5, n5) == 0); 

    int target6[] = {6};
    int arr6[] = {7};
    int n6 = 1;
    assert(count_min_swaps(target6, arr6, n6) == -1);

    int target7[] = {2, 4, 2, 6, 8, 6, 5};
    int arr7[] = {6, 2, 4, 6, 5, 8, 2};
    int n7 = 7;
    printf("%d\n", count_min_swaps(target7, arr7, n7));

    int target8[] = {1, 2, 2, 2, 1, 2};
    int arr8[] = {1, 1, 2, 2, 2, 2};
    int n8 = 6;
    printf("%d\n", count_min_swaps(target8, arr8, n8));

    return EXIT_SUCCESS;
}

