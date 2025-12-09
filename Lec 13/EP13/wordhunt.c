#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// https://www.programiz.com/online-compiler/4Hh3VDMR9Lg5s

int main() {
    // Write C code here
    char matrix[5][5] = {
        {'h','e','l','l','o'},
        {'o','z','b','w','i'},
        {'w','h','i','y','l'},
        {'d','f','g','h','j'},
        {'y','v','n','m','k'}
    };
    
    int m = 5;
    int n = 5;
    char t[20];
    scanf("%[^\n]%*c", t);
    
    // check rows
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            for (;matrix[i][j] != t[0] && (j<=n);j++);
            char *r = malloc((n+1)*sizeof(char));
            for (int k=j;k<n;k++) {
                r[k-j] = matrix[i][k];
                r[k-j+1] = '\0';
                if (strcmp(r,t)==0) {
                    free(r);
                    printf("FOUND!");
                    return 0;
                }
            }
            free(r);
        }
    }
    
    // check columns
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            for (;matrix[j][i] != t[0] && (j<m);j++);
            char *c = malloc((n+1)*sizeof(char));
            for (int k=j;k<m;k++) {
                c[k-j] = matrix[k][i];
                c[k-j+1] = '\0';
                if (strcmp(c,t)==0) {
                    free(c);
                    printf("FOUND!");
                    return 0;
                }
            }
            free(c);
        }
    }
    
    printf("Nowhere found.\n");
    return 0;
}