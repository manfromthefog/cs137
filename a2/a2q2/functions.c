#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

void square(int w) {
    for (int i = 1; i <= w * w; i++) {
        printf("%d ", i);
        if (i % w == 0) {
            printf("\n");
        }
    }
}

void spiral(int w) {
    /**
    Using the square() function I observed some very intereting properties about spirals and how cycles are repeated.
    
    Let's take an exmaple, let's say w = 5. Let's construct an algorithm that goes like this.
    
    We have: 
    
    Cycle 1 
    1 2 3 4 5 (right) 
    10 15 20 25 (down) 
    24 23 22 21 (left) 
    
    Cycle 2
    16 11 6 (up) 
    7 8 9 (right) 
    
    Cycle 3 
    14 19 (down) 
    18 17 (left) 

    Cycle 4 
    12 (up) 
    13 (left) 
    
    Output is 1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13

    We summarize the observed patterns.
    1. The first cycle has 2 direction changes. All others have 1.
    2. For every cycle, the amount of repetitions in a certain direction decreases by 1.
    3. While the number of steps is greater than 0, we can keep going.
    4. The total number of cycles appears to be w - 1.

    We implement the above algorithm but initializing four variables.

    val takes care of the actual value
    reps takes care of the amount we move in a direction
    dir takes care of our current direction
    cycle takes care of how many directions we have taken

    - We set the condition reps >= 0, and then start looping
    - The first cycle will have 3 cycles, that's normal and a part of our algorithm
    - Direction can be dealt with using mod 4
    - Rotate after a direction is finished and add to the cycle count
    - Decrease the reps every 2 cycles
    **/

    int val = 0;             // Start from 1
    int cycle = 0;           // Count how many directions we have taken
    int dir = 0;             // 0 = right, 1 = down, 2 = left, 3 = up
    int reps = w;            // Steps to take in current direction

    while (reps >= 0) {
        // Move in the current direction
        for (int i = 0; i < reps; i++) {
            if (dir == 0) {        // right
                val++;
            } else if (dir == 1) { // down
                val += w;
            } else if (dir == 2) { // left
                val--;
            } else if (dir == 3) { // up
                val -= w;
            }
            printf("%d ", val);
        }

        dir = (dir + 1) % 4; // rotate direction
        cycle++;

        // Every two directions, reduce the cycle size (because the spiral is shrinking)
        if (cycle % 2 == 1) {
            reps--; 
        }
    }
    printf("\n"); // End in breakline
}

void rotation(int w) {
    /**
    I remind myself when I see these things.
    Chaos is order in disguise.

    1 2 3 
    4 5 6 
    7 8 9

    1 3 9 7
    2 6 4 8

    5

    --
    w = 4
    1  2  3  4 
    5  6  7  8 
    9  10 11 12 
    13 14 15 16 

    1 4  16 13
    2 8  15 9
    3 12 14 5

    6 7 10 11

    --
    w = 5
    1  2  3  4  5 
    6  7  8  9  10 
    11 12 13 14 15 
    16 17 18 19 20 
    21 22 23 24 25 

    1 5  25 21
    2 10 24 16
    3 15 23 11
    4 20 22 6

    7 9  19 17
    8 14 18 12

    13

    --
    w = 6
    1  2  3  4  5  6 
    7  8  9  10 11 12 
    13 14 15 16 17 18 
    19 20 21 22 23 24 
    25 26 27 28 29 30 
    31 32 33 34 35 36

    1 6 36 31 
    2 12 35 25 
    3 18 34 19 
    4 24 33 13 
    5 30 32 7
    
    8  11 29 26
    9  17 28 20 
    10 23 27 14
    
    15 16 22 21

    --

    From these examples we can conclude an algorithm.

    1. Figure out the "corner numbers." For w = 6, the corner numbers are 1, 6, 36, 31 for layer 1 and 8, 11, 29, 26 for layer 2 and 15, 16, 22, 21.
    2. Realize that that each layer of corner numbers can be calculated using the previous layer.
    2. Realize that the next rotation can be calculated using the previous set of corner numbers.
    3. Realize that the first for loop is w - 1, and the second for loop is w - 3 for as long as w >= 1.
    4. Implement.
    **/

    int c1 = 1;
    int c2 = w;
    int c3 = w * w;
    int c4 = c3 - c2 + 1;

    int cycle = w;
    while (cycle > 0) {
        int t1 = c1;
        int t2 = c2;
        int t3 = c3;
        int t4 = c4;
        
        for (int i = 0; i < cycle - 1; i++) {
            printf("%d %d %d %d ", t1, t2, t3, t4);
            t1++;
            t2 += w;
            t3--;
            t4 -= w;
        }
        
        cycle -= 2;
        c1 += (w + 1);
        c2 += (w - 1);
        c3 -= (w + 1);
        c4 -= (w - 1);
    }

    // If w is an odd number then we have missed the central element. Just print it at the very end for good measure, and of course end on a newline.
    if (w % 2 == 1) {
        int mid = (w / 2) * (w + 1) + 1;
        printf("%d", mid);
    }
    printf("\n");
}