// A program to calculate the minimum score needed on the final exam to pass CS137
// In general the odds are looking grim
// Take the three inputs and weight them accourdingly
// Calculate the final score needed based on the rearranged inequalities
// Keep everything as floats until output
// There are two conditions we need to obey, take the higher of the two
#include <stdio.h>

int main() {
    // Take three inputs
    int grades, assignments, midterm;
    scanf("%d %d %d", &grades, &assignments, &midterm);
    
    // Calculate the weighted score so far
    float weighted = 0.05 * (float)grades + (float)0.20 * assignments + (float)0.3 * midterm;
    
    // Calculation based on inequality 1
    float condition1 = (50 - weighted) / 0.45;
    // Calculation based on inequality 2
    float condition2 = (37.5 - 0.3 * midterm) / 0.45;
    
    // Take the higher of the two conditions
    if (condition1 > condition2) {
        printf("%d\n", (int)condition1);
    }
    else {
        printf("%d\n", (int)condition2);
    }
    return 0;
}
