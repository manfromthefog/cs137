#include <stdio.h>

void zigzag(int w) {
    /**
    The algorithm here is easy to understand but hard to implement.

    For any number sequence, we have a difference between numbers that decreases by 2 every time. Here is an example for w = 7.

    1           13 -> 13 - 1 = 12 (0, 11, 0)
      2       12   -> 12 - 2 = 10 (2, 7, 2)
        3   11     -> 11 - 3 = 8  (4, 3, 4)
          4        -> The middle element is always the previous one / 2, print it if w is odd.
                      Padding of the middle element is (5)
        9   5      -> 9 - 5 = 4   (4, 3, 5)
      8       6    -> 8 - 6 = 2   (2, 7, 3)
    7           7  -> 7 - 7 = 0   (0, 11, 0)

    Note that after the middle, which we can keep track in our for loop, the operation switches from + to -. Our numbers are set.

    We also realize that to stylize our outputs into a zig-zag, we need to apply the correct amount of spacing. This is the difficult part.

    We need three variables. Spacing, padding, and cycle. The previous two variables stylize the zig-zag, and "cycle" produces the right output for even and odd numbers.

    Based on our calculations of left padding, spacing, and right padding, we discover that the left padding starts from 0 and increases by 2; and then falls back down after the middle.

    The spacing decreases by increments of 4 and starts out as w * 2 - 3. Then, it falls back down after the middle just like spacing.

    To implement, we need two for loops that respectively deal with the top half and the bottom half. The bottom half in principle flips the top half's operations.

    To deal with the middle we use an if statement to output a single central element and remove the erroneous output that follows by doing cycle++.

    The rest is direct implementation.
    **/
    int t1, t2, dif, spacing, padding, cycle;
    dif = w * 2 - 2;
    spacing = dif - 1;
    cycle = w / 2 + 1;

    // Padding is an interesting edge case because depending on the number of digits, does the the zig-zag have to change its spacing and padding. 
    // Our >1 test cases involve 2 digit numbers, which means padding increases by 2
    // If we had 4-digit zig-zags (in case such a test case exists) then the padding increases by 4?
    // Asked on Piazza, awaiting response
    padding = 0;
    int pdiff = 2; // countdigits(w * 2);
    
    for (int i = 1; i <= w / 2; i++) {
        t1 = i;
        t2 = t1 + dif;
        
        for (int a = 0; a < padding; a++) {
            printf(" ");
        } 
        printf("%d", t1);
        for (int j = 0; j < spacing; j++) {
            printf(" ");
        }
        printf("%d\n", t2);

        padding += pdiff;
        spacing -= 4;
        dif -= 2;
    }
    if (w % 2 == 1) {
        for (int a = 0; a < padding; a++) {
            printf(" ");
        }
        printf("%d\n", dif / 2 + 1);
        
        cycle++;
        dif -= 2;
    }
    
    for (int i = cycle; i <= w; i++) {
        t2 = i;
        t1 = t2 + dif;
        padding -= pdiff;
        
        for (int a = 0; a < padding; a++) {
            printf(" ");
        }
        
        spacing += 4;
        printf("%d", t1);
        for (int j = 0; j < spacing; j++) {
            printf(" ");
        }
        printf("%d\n", t2);
        dif -= 2;
    }
}