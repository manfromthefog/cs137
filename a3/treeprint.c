#include <stdio.h>

// The question did not say I needed tree() to be recursive
// I will have no for loops in any of my helper functions
// I will ONLY be using recursion with numbers
// Apparently we are allowed as many helper functions as we want
// Therefore I will make as many as I want

// Recursion is horrible, I need to somewhat think of it as mathematical induction
// One base case, and one recursive case that leads into the next case
// Hence all cases will be covered

// Fortunately all the instances of recursion in this program are trivial
// No hard thinking required, but we need a LOT of helper functions

// I will be ABUSING tail recursion to make my life easier

// And I will be plagiarizing my own work from a1/a1q1/division.c


int width_helper (int n) {
    int width = (n % 2 == 0) ? n / 2 : (n + 1) / 2;
    if (width % 2 == 0) {
        width += 1;
    }
    if (width == 0) {
        width = 1;
    }

    return width;
}

void print_dots(int n) {
    if (n <= 0) 
        return;
    printf(".");
    print_dots(n - 1);
}
void print_spaces(int n) {
    if (n <= 0) 
        return;
    printf(" ");
    print_spaces(n - 1);
}
void print_stars(int n) {
    if (n <= 0) 
        return;
    printf("*");
    print_stars(n - 1);
}
void print_plus (int n) {
    if (n <= 0) 
        return;
    printf("+");
    print_plus(n - 1);
}

void print_space (int row, int n) {
    int width = 2 * n + 1;
    int center = width / 2;

    print_dots(1);

    print_spaces(center - row - 1);

    if (row == 0) {
        print_stars(1);
    } else {
        print_plus(1);
        print_spaces(2 * row - 1);
        print_plus(1);
    }

    print_spaces(center - row - 1);

    print_dots(1);
    printf("\n");
}

void print_base (int n) {
    print_stars(1);
    print_plus(2 * n - 1);
    print_stars(1);
    printf("\n");
}

void print_triangle (int row, int n) {
    if (row == n) {
        print_base(n);
        return;
    }
    print_space(row, n);
    print_triangle(row + 1, n);
} 

// We still need to print one part of the trunk
// And we need to print the trunk printer recursively
void print_trunk_helper (int n) {
    int total = 2 * n + 1;
    int width = width_helper(n);
    int margin = (total - width - 1) / 2;

    print_dots(1);
    print_spaces(margin);
    if (width == 1) {
        printf("|");
    }
    else {
        printf("|");
        print_spaces(width - 2);
        printf("|");
    }
    
    print_spaces(margin);
    print_dots(1);
    printf("\n");
}

void print_trunk (int n, int height) {
    if (height <= 0) 
        return;
    print_trunk_helper(n);
    print_trunk(n, height - 1);
}

// With all the helper functions, the main tree function is cheese
void tree(int n) {
    if (n <= 0) {
        return;
    }

    print_triangle(0, n);
    print_trunk(n, n);
}

int main(void) {
    tree(7);
}
