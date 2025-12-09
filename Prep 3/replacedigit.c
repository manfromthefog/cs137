// Online C compiler to run C program online
#include <stdio.h>

int replacedigit(int num, int olddigit, int newdigit) {
    int rem = num % 10;
    if (olddigit == newdigit) return num;
    if (rem == olddigit) {
        return replacedigit(num /= 10, olddigit, newdigit) * 10 + newdigit;
    }
    if (num / 10 == 0) return rem;
    return replacedigit(num /= 10, olddigit, newdigit) * 10 + rem;
}

int main() {
    printf("%d", replacedigit(101001001, 1, 7));
    return 0;
}