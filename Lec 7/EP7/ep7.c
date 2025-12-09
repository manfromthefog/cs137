#include <stdbool.h>
#include <stdio.h>

int longest_sorted(int a[], int n) {
    int first = a[0], streaka = 1, streakb = 1;
    int maxstreak;
    for (int i=1;i<n;i++) {
        if (a[i] >= a[i-1]) {
            streaka++;
        }
        else {
            streaka = 1;
        }

        if (a[i] <= a[i-1]) {
            streakb++;
        }
        else {
            streakb = 1;
        }
        
        if (streaka > maxstreak || streakb > maxstreak) {
            maxstreak = (streaka > streakb) ? streaka : streakb;
        }
    }
    return maxstreak;
}

bool unique(int a[], int n) {
    for (int i=0;i<n;i++) {
        int cur = a[i];
        for (int j=i+1;j<n;j++)
            if (a[j] == cur)
                return false;
    }
    return true;
}

int main() {
    int a1[4] = {3, 2, 2, 1};
    int a2[5] = {5, 1, 3, 7, 2};

    printf("%d\n", longest_sorted(a1,4));
    printf("%d\n", unique(a1,4));

    printf("%d\n", longest_sorted(a2,5));
    printf("%d\n", unique(a2,5));
}