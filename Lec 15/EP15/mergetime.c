#include <stdio.h>
// https://www.programiz.com/online-compiler/9puBOfX2IYLFC

int merge_time(int a[][2], int n) {
    if (n<2) return n;
    int i=0;
    
    while (i+1<n) {
        int s1 = a[i][0];
        int t1 = a[i][1];
        int s2 = a[i+1][0];
        int t2 = a[i+1][1];
        
        if (s2 < t1) {
            a[i][0] = (s1<s2) ? s1 : s2;
            a[i][1] = (t2>t1) ? t2 : t1;
            
            for (int j=i+1;j+1<n;j++) {
                a[j][0] = a[j+1][0];
                a[j][1] = a[j+1][1];
            }
            n--;
        }
        else {
            i++;
        }
    }
    return n;
}

int main() {
    // Write C code here
    int times[4][2] = {
        {3,5},
        {2,6},
        {8,16},
        {15,18}
    };
    
    int n = 4;
    int m = merge_time(times, n);
    printf("[");
    for (int i=0;i<m;i++) {
        printf("[%d,%d]", times[i][0], times[i][1]);
    }
    printf("]");
    return 0;
}