#include <stdio.h>
#include <stdbool.h>
/***
 * We need to consider keeping track of what digits we have seen using a boolean mask.
 * Then we check the indicies of the mask to check if a digit has existed or not.
 * 
 * The hard part is breaking down a number into its digits, but that isn't really too difficult.
 */

int main(void) {
    int n;
    bool digits[10] = {false};
    while (scanf("%d", &n) >= 1) {
        if (n == 0) {
            break;
        }
        int temp = n;
        int isvalid = false;
        while (temp > 0) {
            int d = temp % 10;
            if (!digits[d]) {
                digits[d] = true;
                isvalid = true;
            }
            temp /= 10;
        }
        if (isvalid) printf("%d ", n);
    }
    printf("\n");
    return 0;
}