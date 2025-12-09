#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
 
// A structure for representing a single entry in the matrix.  This part is stored in the heap
struct MatrixEntry {
    int row;  // the row number of a specific entry
    int col;  // the col number of a specific entry
    int value;
    struct MatrixEntry* next; // Pointer to the next entry in the linked list
};

// A structure for representing the sparse matrix. This part is stored in the stack
struct SparseMatrix {
    int num_rows;  // the dimension of the matrix is
    int num_cols;  //  num_rows X num_cols
    struct MatrixEntry* head; // Pointer to the first entry of the linked list
};
 
// Define a function to insert a new entry into the front of the result matrix
// assume all arguments are valid
void insert_entry(struct SparseMatrix* result, int row, int col, int value) {
    // currently we have head -> m
    struct MatrixEntry* m = result->head;
    // we wish to insert a new entry
    struct MatrixEntry* new_entry = malloc(sizeof(struct MatrixEntry));
    
    // set vars for the new entry
    new_entry->col = col;
    new_entry->row = row;
    new_entry->value = value;

    // we have new_entry
    //               ↓
    //       head -> m
    new_entry->next = m;
    // and then we say head -> new_entry -> m completing the insertion
    result->head = new_entry;
}

// Find the value at a particular entry in a sparse matrix
int findValue(struct SparseMatrix* matrix, int row, int col) {
    struct MatrixEntry *m = matrix->head;
    while (m) {
        if (m->row == row && m->col == col) {
            return m->value;
        }
        m = m->next;
    }
    return 0;
}

// Replace the value at a particular entry in a sparse matrix
// If the value adds to zero, remove that entry
void addEntry(struct SparseMatrix* matrix, int row, int col, int new_val) {
    struct MatrixEntry *m = matrix->head;
    while (m) {
        if (m->row == row && m->col == col) {
            m->value += new_val;
            // Assuming the data is positive
            // No need to delete nodes that sum to zero
            break;
        }
        m = m->next;
    }
    return;
}

// Define a function that multiplies two sparse matrices with valid sizes
// Horrible time complexity ~ O(n^3)
struct SparseMatrix multiply_matrices(const struct SparseMatrix* matrix1, const struct SparseMatrix* matrix2) {
    struct SparseMatrix matrixprod;
    matrixprod.num_rows = matrix1->num_rows;
    matrixprod.num_cols = matrix2->num_cols;
    matrixprod.head = NULL;

    struct MatrixEntry *m1 = matrix1->head;
    struct MatrixEntry *m2 = matrix2->head;
    // rows of matrix product
    for (;m1;m1 = m1->next) {
        for (;m2;m2 = m2->next) {
            if (m1->col == m2->row) {
                // If that entry doesn't exist, initialize it
                if (!findValue(&matrixprod, m1->row, m2->col))
                    insert_entry(&matrixprod, m1->row, m2->col, m1->value * m2->value);
                else {
                    addEntry(&matrixprod, m1->row, m2->col, m1->value * m2->value);
                }
            }
            
        }
        m2 = matrix2->head;
    }
    return matrixprod;
}


// Function to free memory allocated for a sparse matrix
void free_sparse_matrix(struct SparseMatrix* matrix) {
    struct MatrixEntry *curnode = matrix->head;
    while (matrix->head) {
        matrix->head = matrix->head->next;
        free(curnode);
        curnode = matrix->head;
    }
}

// Function to print a sparse matrix
// Do not change this function

void print_sparse_matrix(const struct SparseMatrix* matrix) {
    for (struct MatrixEntry* entry = matrix->head; entry != NULL; entry = entry->next) {
        printf("(%d, %d): %d\n", entry->row, entry->col, entry->value);
    }
}
 
 
// for testing. Do not submit the main function
/*
int main(void) {
    // Create and initialize sparse matrices (matrix1 and matrix2)
       
    struct SparseMatrix matrix1;
    matrix1.num_rows = 3;
    matrix1.num_cols = 4;
    matrix1.head = NULL;
    // Initialize matrix1 with some entries
    insert_entry(&matrix1, 0, 0, 1);
    insert_entry(&matrix1, 1, 1, 2);
    insert_entry(&matrix1, 2, 2, 3);
    insert_entry(&matrix1, 0, 3, 4);
    printf("Matrix1 3x4:\n");
    print_sparse_matrix(&matrix1);
    
    struct SparseMatrix matrix2;
    matrix2.num_rows = 4;
    matrix2.num_cols = 3;
    matrix2.head = NULL;
 
    // Initialize matrix2 with some entries
    insert_entry(&matrix2, 0, 0, 4);
    insert_entry(&matrix2, 1, 1, 5);
    insert_entry(&matrix2, 2, 2, 6);
    insert_entry(&matrix2, 3, 2, 3);
    insert_entry(&matrix2, 3, 0, 1);

    assert(findValue(&matrix2, 3, 3) == 0);

    printf("Matrix2 4x3:\n");
    print_sparse_matrix(&matrix2);
    // Multiply matrices
    struct SparseMatrix result = multiply_matrices(&matrix1, &matrix2);
 
    // Print the result matrix
    printf("Result matrix1 x matrix2:\n");
    print_sparse_matrix(&result);
 
    // Free memory allocated for matrices and result
    free_sparse_matrix(&matrix1);
    free_sparse_matrix(&matrix2);
    free_sparse_matrix(&result);
 
    return 0;
}
*/
