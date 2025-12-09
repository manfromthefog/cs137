// Our goal is to determine the number of pizzas required
// Simple stoichiometry tells me the number of pizzas required is the number of people x number of slices per person / number of slices per pizza
// Again, if fully divisible, return the quotient
// If not, round up (away from zero) since we can't order a fraction of a pizza

#include <stdio.h>

int main() {
    // take all 3 inputs
    int num_people, slices_per_pizza, slices_each;
    scanf("%d %d %d", &num_people, &slices_per_pizza, &slices_each);

    // if there are no leftovers, great! return the slices per pizza (which naturally rounds down)
    if ((num_people * slices_each) % slices_per_pizza == 0) {
        printf("%d\n", (num_people * slices_each) / slices_per_pizza);
        return 0;
    }
    // otherwise just add 1 to the rounded down number
    else {
        printf("%d\n", (num_people * slices_each) / slices_per_pizza + 1);
    }
    return 0;
}
