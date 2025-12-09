#include <stdio.h>
#include <stdbool.h>

int singleNumber(int* nums, int numsSize) {
    for (int i=0;i<numsSize;i++) {
        if (nums[i] > 0) {
            bool pair = false;
            for (int j=i+1;j<numsSize;j++) {
                if (nums[j] == nums[i]) {
                    pair = true;
                    nums[j] = -1;
                }
            }
            if (!pair) {
                return nums[i];
            }
        }
    }
    return -1;
}

int main() {
    int nums[5] = {2, 2, 1, 1, 3};
    printf("%d\n", singleNumber(nums, 5));
}