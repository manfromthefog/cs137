#include <stdio.h>
#include <assert.h>

// The following function uses a recursive DFS algorithm to determine whether there exists a path in the array that moves right and down to reach the target cell at (m, n). If such a path does not exist then there does not exist a monotone path.
int DFS(int h, int w, int y, int x, int a[h][w]) {
    // Make sure everything is within bounds and we are on a path
    if ((y < h) && (x < w) && (a[y][x] == 1)) {
        // If we are already at the visited cell, we are done
        // This is also our base case
        if ((x == w - 1) && (y == h - 1)) {
            return 1;
        }

        // Mark each cell as visited (i.e. the next recursion will not consider this cell)
        a[y][x] = 0;

        // Recursive call to check if moving right is valid
        if (DFS(h, w, y, x + 1, a)) {
            return 1;
        }
        // Identical call to check if moving down is valid
        if (DFS(h, w, y + 1, x, a)) {
            return 1;
        }

        // The DFS helper will continue moving right and down, checking all possibilities until there is a possible continuous path from (0,0) to (m,n).

        // Example call for array a in main
            // DFS(w, h, x + 1, y, a) will first check x + 1 and y are in bounds, which they are. The coords are also equal to 1 at (x + 1, y)
            // Now we check, are we at (m, n)? Nope! Let's set the cell as zero and keep checking (x + 2, y) and (x + 1, y + 1)... and so on.
            // By induction, eventually we'll reach (m, n) if a monotone path exists
    }
    return 0;
}

// This function uses the DFS helper to determine if a mxn matrix has a monotone path
int monotonePath(int m, int n, int a[m][n]) {
    // Initializes width as m, width as n, and we start at (0, 0) as required
    return DFS(m, n, 0, 0, a);
};

/*
int main(void) {
    int m = 10;
    int n = 12;
    int a[][12] = {
        {1,1,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,0,0,0,0,0,0},
        {0,0,1,0,0,1,0,0,0,0,0,0},
        {0,1,1,0,0,1,1,0,0,0,0,0},
        {0,1,0,0,0,0,1,0,0,0,0,0},
        {0,1,1,0,0,0,1,1,1,0,0,0},
        {0,0,1,0,0,0,0,0,1,0,0,0},
        {0,0,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,1,1}
    };
    
    // a, but with one entry switched eliminating the monotone path
    int b[10][12] = {
        {1,1,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,0,1,0,0,0,0,0,0},
        {0,0,1,0,0,1,0,0,0,0,0,0},
        {0,1,1,0,0,1,1,0,0,0,0,0},
        {0,1,0,0,0,0,1,0,0,0,0,0},
        {0,1,1,0,0,0,1,1,1,0,0,0},
        {0,0,1,0,0,0,0,0,1,0,0,0},
        {0,0,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,1,1},
    };
    
    assert(monotonePath(m, n, a));
    assert(!monotonePath(m, n, b));

    return 0;
}
*/
