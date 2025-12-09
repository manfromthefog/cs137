#include <stdio.h>

void findMaxMin(int arr[], int n, int *max, int *min) {
    // Both pointers are pointing at the first element in the array
    *max = arr[0];
    *min = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > *max) *max = arr[i];
        if (arr[i] < *min) *min = arr[i];
    }
}

void arrThing(int n, int arr[n], int x) {
    int max, min;
    findMaxMin(arr, n, &max, &min);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) { 
            arr[i] = max;
        }
    }
}

int main(void) {
    int arr[] = {1, 2, 3};
    arrThing(3, arr, 2);

    for (int i = 0; i < 3; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}