#include <stdlib.h>
#include <stdio.h>

struct Record {
    int id;
    int value;
};

/***
 * Allocates new array on the heap of pointers to struct Record
 * Containing only records whose value is greater than or equal to threshold
 * Stores address of this new array in *filtered
 * Returns the number of records that meet the condition
 * If no records meet the condition, the function returns 0 and sets *filtered to NULL
 * No new memory allocated
 * The function must not modify or free the original array of the original struct Record objects
 */
int filter_and_count(struct Record **records, int n, int threshold, struct Record ***filtered) {
    // Initialize the memory for the filtered array
    *filtered = malloc(sizeof(struct Record *) * n);

    // Loop through every record
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (records[i]->value >= threshold) {
            // If this value is higher than threshold
            // Visit the filtered array at that index
            (*filtered)[index] = malloc(sizeof(struct Record)); // we need to allocate memory for every filter
            // for each pointer in the array, set the to the pointer to the pointer to struct
            (*filtered)[index]->value = records[i]->value;
            (*filtered)[index]->id = records[i]->id;
            index++;
        }
    }
    if (index == 0) {
        // Then we don't need the filter memory
        free(*filtered);
        *filtered = NULL;
        return 0;
    }
    return index;
}

int main(void) {
    int n = 5;
    struct Record *records[5];
    for (int i = 0; i < n; i++) {
        records[i] = malloc(sizeof(struct Record));
        records[i]->id = i + 1;
        records[i]->value = i * 10; // values: 0, 10, 20, 30, 40
    }
    struct Record **filtered = NULL;
    int count = filter_and_count(records, n, 15, &filtered);
    printf("Number of records >= 15: %d\n", count);

    for (int i = 0; i < count; i++) {
        printf("Record %d -> id: %d, value: %d\n", i, filtered[i]->id, filtered[i]->value);
    }
    for (int i = 0; i < count; i++) {
        free(filtered[i]);
    }
    free(filtered);
    for (int i = 0; i < n; i++) {
        free(records[i]);
    }
    return 0;
}
