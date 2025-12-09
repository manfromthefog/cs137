#include <stdio.h>
#include <stdbool.h>

void printa(int a[], int n) {
    for (int i=0;i<n;i++)
        printf("%d\n", a[i]);
}

bool sudokuvalidity(int sudokuboard[9][9]) {
    for (int i=0;i<9;i++) {
        int colf[10] = {0};
        int rowf[10] = {0};

        for (int j=0;j<9;j++) {
            if (sudokuboard[i][j]) {
                // duplicate value in row
                if (rowf[sudokuboard[i][j]]) {
                    return false;
                }
                else
                    rowf[sudokuboard[i][j]]++;
            }
            if (sudokuboard[j][i]) {
                // dupe value in column
                if (colf[sudokuboard[j][i]]) {
                    return false;
                }
                else
                    colf[sudokuboard[j][i]]++;
            }
                
        }
    }
    
    // Now we check for each 3x3 grid (corners)
    for (int a=0;a<9;a+=3) {
        for (int b=0;b<9;b+=3) {
            int squaref[10] = {0};
            for (int c=a;c<3;c++) {
                for (int d=b;d<3;d++) {
                    if (sudokuboard[c][d]) {
                        if (squaref[sudokuboard[c][d]]) {
                            return false;
                        }
                        else
                            squaref[sudokuboard[c][d]]++;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int grid1[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };

    int grid2[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 4, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 2, 8, 9}  // Note: this row has two 8s
    };

    printf("%d\n", sudokuvalidity(grid1));
    printf("%d\n", sudokuvalidity(grid2));
}