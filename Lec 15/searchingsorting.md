# Linear Search

```C
// Post : Returns index of the first occurrence
// of value in a if found , -1 otherwise

int lin_search(int a[], int n, int value){
    for (int i = 0; i < n; i++){
        if (a[i] == value) // we found what we are looking for
            return i; // stop and return the index of the first occurrence
    }
    return -1; // value not found
}
```

The best case running time is O(1), worst case is O(n). This is the base case where the first list element is the element is we are looking for, so there is no loop.

# Binary Search

Two pointers that indicate the first index and the last index. Search for your id, then shrink your bounds. You don't need pointers for this, but it's a very efficient way to search. Works only on sorted arrays.

```C
int bin_search(int a[], int n, int value){
    int lo = 0, hi = n - 1;
    while (hi >= lo){
        // Note int m = (hi +lo)/2 is equivalent to m = lo + (hi - lo) / 2
        // but may overflow.
        int m = lo + (hi - lo) / 2;
        if (a[m] == value)
            return m;
        if (a[m] < value) // if the value is higher than my value, move the low bound right below
            lo = m + 1; 
        if (a[m] > value) // else, move the high bound to right below the midpoint
            hi = m - 1;
    }
    return -1; // value not found
}
```

The best case running time is O(1) and worst case O(log2(n)). Unless explicitly asked, the general time complexity is O(log2(n)).

An interesting case is when one of the indexes fall on the value. Then, the midpoint will be one below our desired value, our low will be moved to our high, and what this means is the new midpoint will be equal to the value we want!

Visit [this visualization](https://www.cs.usfca.edu/~galles/visualization/Search.html) of binary search.

# Selection Sort

Find the smallest element. Swap with the first element in the iteration. Repeat.

```C
void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) { // O(n)
        // Find the index of the minimal value
        int min = i;
        for (int j = i + 1; j < n; j++) // O(n)
            if (a[j] < a[min]) min = j; // O(1)
        
        // Swap
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}
```

## Tracing

Let's trace with the array [20, 12, 10, 15, 2].

1. (i = 0) The index of the minimum is 4.
2. temp = value @ 4 = 2 (min)
3. a[4] = a[0] -> [20, 12, 10, 15, 20]
4. a[0] = a[4] -> [2, 12, 10, 15, 20]
5. (i = 1) The index of the minimum is 2.
6. temp = value @ 2 = 10 (min)
7. a[2] = a[1] -> [20, 12, 10, 15, 20]
8. a[1] = temp -> [2, 10, 12, 15, 20]
9. (i = 2) The index of the minimum is 2.
10. temp = value @ 2 = 12 (min)
11. a[2] = a[2] -> [2, 10, 12, 15, 20]
12. a[2] = temp -> [2, 10, 12, 15, 20]
13. (i = 3) The index of the minimum is 3.
14. temp = value @ 3 = 15 (min)
15. a[15] = a[15] -> [2, 10, 12, 15, 20]
16. a[15] = temp -> [2, 10, 12, 15, 20]
17. We are guranteed a sorted array. The final sorted array is [2, 10, 12, 15, 20].

## Running Time

The worst case of selection sort is O(n<sup>2</sup>). Notice the outer loop runs `n` times, the inner loop runs `n` times. No matter what, both loops run to completion, hence the best case scenario is equal to the worst case scenario.

You can also derive this computationally using summation.

## Improvements

We notice a significant flaw, where even if the array is sorted, the worst case still runs. Therefore we will introduce a new sorting algorithm, called insertion sort.

# Insertion Sort

```C
void insertion_sort(int *arr, int n) {
    int i, j, x;
    // the first element is already sorted by itself
    for (i=1;i<n;i++) {
        x=a[i];
        // Moves the value down until
        // 1. it's the first element of the array
        // 2. it's lower than the element to its right
        for (j=i;j>0 && x<a[j-1];j--) {
            a[j] = a[j-1];
        }
        a[j]=x;
    }
}
```

## Tracing

For `{ -10, 2, 14, -7, 11, 38 }`, what is the array after the fifth iteration?

# Merge Sort

A recursive sorting algorithm that divides a large, unsorted list into a sorted list.

![diagram](https://upload.wikimedia.org/wikipedia/commons/e/e6/Merge_sort_algorithm_diagram.svg)

This sounds like a complicated program, but there are two core concepts, splitting and merging.

```C
void merge_sort(int a[], int t[], int n) {
    if (n <= 1) return; // one element is our base case
    int mid = (n+1)/2;

    // pointers to the halved arrays
    int *lower = a;
    int *upper = a + mid;

    // repeat merge sort on the halves
    // 2T(n/2), calling itself with half the data
    merge_sort(lower,t,mid);
    merge_sort(upper,t,n-mid);

    // the rest of the code is about merging them back
    int i=0;
    int j=mid;
    int k=0;

    // O(n) merging logic

    while (i<mid && j<n) {
        if (a[i] <= a[j])
            t[k++] = a[i++];
        else
            t[k++] = a[j++];
    } // gurantees our array is done

    // copy any remaining elements in the arrays
    // all elements should end up in t[]
    while (i<mid)
        t[k++] = a[i++];
    while (j<n)
        t[k++] = a[j++];

    // this is essential that we are copying the sorted versions back to the original array
    for (i=0;i<n;i++)
        a[i] = t[i];
}
```

## Tracing

![mergesort](https://www.runoob.com/wp-content/uploads/2018/09/Merge-sort-example-300px.gif)

# The qsort() Command

C includes an inbuilt `qsort()` command in `<strlib.h>`. The command inputs many arguments including a strange (*compare) operator which is designed so the command can sort __any__ data structure.

For arrays, qsort() sorts type (int) but you can also sort structs if you feed in the right arguments, like `student->id` or `student->grade`.

Here's an example, just to show how versatile the function is. You can have custom comparisons.

```C
#include <stdio.h>
#include <stdlib.h>

struct student{
    unsigned int id;
    double avg;
};

int compare1(const void *a, const void *b){
    unsigned int p = ((const struct student *)a)->id;
    unsigned int q = ((const struct student *)b)->id;

    if (p < q) return -1;
    else if (p == q)return 0;
    else return 1;
}

int compare2(const void *a, const void *b){
    int p = *(const int*)a;
    int q = *(const int*)b;

    if (p < q) return -1;
    else if (p == q) return 0;
    else return 1;
}

int main(void) {
    struct student st[3]= {
        {333,86.7},
        {111,90.7},
        {222, 80}
    };
    qsort(st, 3, sizeof(struct student), compare1);
    for (int i = 0; i < 2; i++){
        printf("%d, ", st[i].id);
    }
    printf("%d\n", st[2].id);
    // Output: 111, 222, 333

    int a[] = { -10, 2, 14, -7, 11, 38 };
    const int n = sizeof(a) / sizeof(a[0]);
    qsort(a, n, sizeof(int), compare2);
    for (int i = 0; i < n - 1; i++){
        printf("%d, ", a[i]);
    }
    printf("%d\n", a[n - 1]);
    // Output: -10, -7, 2, 11, 14, 38
    return 0;
}
```

What else can we do with qsort? qsort() is a function that takes in a null function. Take a look at its declaration in the interface file. `void qsort(void *base, size_t n, size_t size, int (*compare)(const void *a, const void *b))`.

That `int (*compare)(const void *a, const void *b))` asks the user to pass a comparison function of a and b which returns -1 if a is smaller, 0 if equal, 1 if a is larger.

Take a look at `sortdemo.c`.