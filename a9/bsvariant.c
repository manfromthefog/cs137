#include <assert.h>

// Finds the first occurance of a value in a list using
// binary sort
int first_occurrence(int a[], int n, int value) {
    int start = 0, end = n;
    
    // Base case: the first element is what we are looking for
    if (a[0] == value) return 0;

    while (start <= end) {
        int mid = end + (start - end) / 2;
        if (a[mid] == value && a[mid-1] != a[mid])
            return mid;
        else if (a[mid] < value)
            start = mid + 1;
        // Either a[mid] == value and it is not the first
        // or our cur val is larger than the value
        // in either case we search down!
        else
            end = mid - 1;
    }
    return -1;
}

// Finds the last occurance of a value in a list using
// binary sort
int last_occurrence(int a[], int n, int value) {
    int start = 0, end = n;
    
    // Base case: the last element is what we are looking for
    if (a[n-1] == value) return n-1;

    while (start <= end) {
        int mid = end + (start - end) / 2;
        if (a[mid] == value && a[mid+1] != a[mid])
            return mid;
        else if (a[mid] > value)
            end = mid - 1;
        // Either a[mid] == value and it is not the last
        // or our cur val is smaller than the value
        // in either case we search up!
        else
            start = mid + 1;
    }
    return -1;
}

// Finds the element in a list closest to a value
// using binary sort
int closest_value(int a[], int n, int value) {
    int start = 0, end = n;
    // base cases, value > a[n-1] and value < a[0]
    if (value > a[n-1]) 
        return a[n-1];
    if (value < a[0])
        return a[0];
    
    // else the value is in range of the array
    while (start <= end) {
        int mid = end + (start - end) / 2;
        if (a[mid] <= value && a[mid+1] > value) {
            // at some point we have a value switch
            if (a[mid+1] - value < value - a[mid]) 
                return a[mid+1];
            else
                return a[mid];
        }
        else if (a[mid] > value)
            end = mid - 1;
        else
            start = mid + 1;
    }
}

/*
int main(void) {
    int a[] = { -10, -2, -2, 3, 3, 3, 5, 7, 9, 9 };
    const int len = sizeof(a) / sizeof(a[0]);
    assert(-1 == first_occurrence(a, len, 0));
    assert(0 == first_occurrence(a, len, -10));
    assert(3 == first_occurrence(a, len, 3));
    assert(8 == first_occurrence(a, len, 9));
    assert(-1 == last_occurrence(a, len, 0));
    assert(0 == last_occurrence(a, len, -10));
    assert(5 == last_occurrence(a, len, 3));
    assert(9 == last_occurrence(a, len, 9));
    assert(-2 == closest_value(a, len, 0));
    assert(-10 == closest_value(a, len, -11));
    assert(9 == closest_value(a, len, 10));
    assert(3 == closest_value(a, len, 2));
    assert(-10 == closest_value(a, len, -20));
    assert(3 == closest_value(a, len, 4));
    assert(7 == closest_value(a, len, 8));
    
    return 0;
}
*/
