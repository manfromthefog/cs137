#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#define MAX 10000;

/***
 * find_subintervals(midpoint, a, l, nume)
 * Finds if it is possible to have partitions of a[] such that the sum of any partition is less than `midpoint`.
 * If midpoint is equal to a partition, returns the value of the sum of that partition only if all other partitions
 * are less than `midpoint`.
 * 
 * requires: a is sorted from low to high
 */
int find_subintervals(int midpoint, int a[], int l, int nume) {
    int sum = 0, largest_matching_sum = 0;
    int test_partition = 1; // by default we have 1 partition i.e. the whole array

    for (int i = 0; i < l; i++) { // O(n) b.c. only thing that scales
		// 1. is any element is higher than our midpoint -> invalid
		if (a[i] > midpoint) return 0;
		
		// 2. sum the array
		sum += a[i];

		// 3. we add elements until the sum exceeds
		// midpoint -> we found a partition
		if (sum > midpoint) {
			// 4. start adding again, but from a[i]
			test_partition++;
			sum = a[i];
		}
		// we found a partition that happens to equal to midpoint !?
		if (sum == midpoint) 
		    largest_matching_sum = sum;
    }
    //printf("%d %d\n", largest_matching_sum, test_partition);
    if (test_partition <= nume) {
		// if all partitions are lower than our value
        if (largest_matching_sum)
            // returns partition(s) that equal our value (if they exist)
			return largest_matching_sum;
		return 1;
    }
	// if we have more partitions than required
	// our midpoint is too low
	return 0;
}

/***
 * findTasks(tasks, n, numempl)
 * Given an array of task time in ascending order, returns the maximum number of minutes assigned to an employee
 * if the minutes assigned to all employees is a minimum.
 * 
 * requires: tasks gives time in ascending order
 * assumes: variables n, numempl are elements of the naturals
 */
int findTasks(int tasks[], int n, int numempl) { 
	// the optimal sum is between the max element of the array and the total sum

	// the array is already sorted =)
	int start = tasks[n - 1];
	int end = 0;
	for (int i=0;i<n;i++) 
		end += tasks[i];
	
	// O(log m) binary search
	while (start <= end) {
		int mid = start + (end - start) / 2;
		// "is this higher or lower than the answer" ->
		// can there be task partitions s.t. all are lower / one is higher than mid?

		// I made a function to answer that quetion, find_subintervals()
		int search_direction = find_subintervals(mid, tasks, n, numempl); // O(n)

		if (search_direction == 1) {
			end = mid - 1;
		}
		else if (search_direction == 0) {
			start = mid + 1;
		}
		else {
			return search_direction;
		}
	}
	return 0;
	// Time complexity is O(nlogm) as required
} 
 
/*
int main(void) {
	int arr[] = { 120, 340, 670, 900 };
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(1130 == findTasks(arr, n, 2));

	int arr1[] = { 1, 2, 3, 4 };
	n = sizeof(arr1) / sizeof(arr1[0]);
	assert(6 == findTasks(arr1, n, 2));
	assert(4 == findTasks(arr1, n, 4));

	int arr2[] = { 22, 34, 70, 80, 88, 96, 100 };
	n = sizeof(arr2) / sizeof(arr2[0]);
	assert(196 == findTasks(arr2, n, 3));
	assert(168 == findTasks(arr2, n, 4));
	assert(126 == findTasks(arr2, n, 5));
	assert(100 == findTasks(arr2, n, 6));

	int arr3[] = { 80, 100 };
	n = sizeof(arr3) / sizeof(arr3[0]);
	assert(180 == findTasks(arr3, n, 1));
	assert(100 == findTasks(arr3, n, 2));
	
	int arr4[] = { 22, 34, 70, 80, 88, 96, 100, 120, 130, 140, 141, 155, 200, 210, 330, 500 };
	n = sizeof(arr4) / sizeof(arr4[0]);
	assert(2416 == findTasks(arr4, n, 1));
	assert(1240 == findTasks(arr4, n, 2));
	assert(846 == findTasks(arr4, n, 3));
	assert(740 == findTasks(arr4, n, 4));
	assert(540 == findTasks(arr4, n, 5));
	assert(500 == findTasks(arr4, n, 6));
	assert(500 == findTasks(arr4, n, 7));
	assert(500 == findTasks(arr4, n, n));
    
	return 0;
}
*/
