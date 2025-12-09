#include <assert.h>
#include <stdio.h>
#include <math.h>

// This function counts the frequency of each digit in a number and returns the frequency as an array
void digitcounter(long long int n, int *a) {
    for(int i = 0; i < 10; i++) {
        a[i] = 0;
    }
    // Go through each digit of the number and add it to the corresponding index in the array
    while (n > 0) {
        ++a[n % 10];
        n /= 10;
    }
}

// This function removes the largest digits from a number k n times, and then returns the smallest possible integer arrangement of the remaining digits.
long long int removekdigits(long long int n, int k) {
    int digits[10];
    long long int res = 0;
    digitcounter(n, digits); // We create the digit frequency counter
    
    // The remainder is the amount of times we should subtract from a certain index
    // This is because we subtract from the index of the largest digit, and if we remove all of them then we move onto the next largest digit (remainder)
    int remainder = k;
    int subtracted;
    int base = 0;
    
    for (int i = 9; i >= 0; i--) {
        if (digits[i]) {
            // We don't want to be subtracting from a negative number
            subtracted = (digits[i] - remainder) > 0 ? remainder : digits[i];
            remainder -= subtracted;

            // Set the new digit frequency
            int freq = digits[i] - subtracted;
            if (freq) {
                // If the digit still exists, multiply it by its magnitude and add it to res
                for (int j = 0; j < freq; j++) {
                    // printf("%d\n", i * (int)pow(10, base));
                    res += i * (int)pow(10, base);
                    base++;
                }
            }
        }
    }
    return res;
}

/*
int main(void) {
    assert(removekdigits(345267,3)==234);
    assert(removekdigits(0,0)==0);
    assert(removekdigits(9,1)==0);
    assert(removekdigits(871,0)==178);
    assert(removekdigits(9898989,2)==88899);
    return 0;
}
*/
