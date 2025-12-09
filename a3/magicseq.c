#include <stdio.h>

// We need three parser functions for S,G,H
// We need to read inputs one by one using scanf()
// The only way we can read more inputs is using scanf() inside the recursive functions

// Each S,G,H function is recursive
// 1. Reads the next integer
// 2. Checks the next integer using the conversion rules
// 3. If the next integer is valid, it stops or calls the next function (S,G,H)

// We need to think of what letter we need and what digit we need to form the letter
// This is also called a "recursive descent parser"

// Example for S -> 1 G 5
// Read one integer. If it's not 1, fail. Call parseG(). Read one integer. If it's not 5, fail. If everything is passed, return success.

// Let's break down parseG() as well
// If the next input is 2, we need to do parseH() and parseG()
// If the next input is 3, we return success immediately
// If the next input is 4, we need to do parseG()

// Let's finally break down parseh()
// If the next input is 5, we return success immediately
// If the next input is 6H, we call parseH() again

// Give the problem to the function itself
// Very simple and lazy

int parseH() {
    int next;
    if (scanf("%d", &next) != 1) return 0;
    
    if (next == 5) {
        return 1;
    }    
    else if (next == 6) {
        if (!parseH()) {
            return 0;
        }
        return 1;
    } 
    else {
        return 0;
    }
}

int parseG() {
    int next;
    if (scanf("%d", &next) != 1) return 0;
    if (next == 2) {
        if (!parseH()) {
            return 0;
        }
        if (!parseG()) {
            return 0;
        }
        return 1;
    } 
    else if (next == 3) {
        return 1;
    } 
    else if (next == 4) {
        if (!parseG()) {
            return 0;
        }
        return 1;
    } 
    else {
        return 0;
    }
}

int parseS() {
    int x, y;
    if (scanf("%d", &x) != 1) return 0;
    if (x != 1) {
        return 0;
    }
    if (!parseG()) {
        return 0;
    }
    if (scanf("%d", &y) != 1) return 0;
    if (y != 5) {
        return 0;
    }
    return 1;
}

// The main magicSeqeunce function is super simple with the above parsers
// Call parseS() and check if we have reached the end of input

// Today, I learned that C takes inputs because the terminal first stores your input in a buffer, which scanf procedurally reads from
// Very interesting input scheme, different from Python's input() function

int magicSequence() {
    if (parseS()) {
        int next;
        if (scanf("%d", &next) != 1) {
            return 1; // Successfully reached the end of input
        } 
        else {
            // Stops the program if there are extra inputs after a valid sequence
            return 0; 
        }
    } 
    else {
        return 0;
    }
}
