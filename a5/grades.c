#include <stdio.h>
#include <math.h>

/***
 * function standard_dev()
 * @param integer frequency array arr[] from 0 to 100
 * @param integer n
 *
 * @returns The mean / average of a frequency array of grades from 0 to 100
 * requires: n != 1
 */
double mean(int arr[], int n) {
    double sum = 0;
    for (int i = 0; i < 101; i++) {
        // Same idea, if arr[i] is non-zero, then we sum the value (index) multipled by the frequency.
        if (arr[i])
            sum += i * arr[i];
    }
    return sum / n;
}

/***
 * function standard_dev()
 * @param integer frequency array arr[] from 0 to 100
 * @param double avg
 * @param integer n
 *
 * @returns The standard deviation of a frequency array of grades from 0 to 100
 * requires: n != 1
 * requires: the data values are between 1 and 100
 */
double standard_dev(int arr[], double avg, int n) {
    // The numerator is the sum of the distance of each sample to the mean squared
    double sum_diff_squared = 0;
    for (int i = 0; i < 101; i++) {
        if (arr[i])
            // Multiply our result by the frequency
            sum_diff_squared += arr[i] * (i - avg) * (i - avg);
    }
    return sqrt(sum_diff_squared / (n - 1));
}

int main(void) {
    // Since all grades are between 0-100, initialize an array of length 101.
    int grades[101] = {0};
    int n;

    while (scanf("%d", &n) > 0) {
        ++grades[n];
    }

    // Find the first and last non-zero elements in the array.
    // The array frequency is the value at that index
    // Counting non-zero elements
    int max = 0, min = 0, max_freq = 0, min_freq = 0, failed = 0, len = 0; // len is the length of input
    
    for (int i = 0; i < 101; i++) {
        // First instance is the minimum.
        if (grades[i]) {
            min = i;
            min_freq = grades[i];
            break;
        }
    }
    for (int i = 0; i < 101; i++) {
        // Last instance is the maximum
        if (grades[i]) {
            len += grades[i];
            max = i;
            max_freq = grades[i];
        }
        // Failing is <50 grade
        if (i < 50) {
            failed += grades[i];
        }
    }

    // Use the average to calculate standard deviation
    double average = mean(grades, len);
    double std_dev = standard_dev(grades, average, len);
    
    printf("The maximal grade is: %d\n", max);
    printf("The number of students who received the maximal grade is %d\n", max_freq);
    printf("The minimal grade is: %d\n", min);
    printf("The number of students who received the minimal grade is %d\n", min_freq);
    printf("The course mean is: %0.3f\n", average);
    printf("The standard deviation is: %0.3f\n", std_dev);
    printf("The number of students who failed the course is: %d\n", failed);
    return 0;
}