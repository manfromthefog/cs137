#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int concat(int x, int y) {
    char str1[20];
    char str2[20];

    sprintf(str1,"%d",x);
    sprintf(str2,"%d",y);

    strcat(str1,str2);
    return atoi(str1);
}

int main(void) {
    int a = 12, b = 111, c = 1;

    int a_number = printf("%d", a);
    int b_number = printf("%d", b);
    int c_number = printf("%d", c);

    printf("\n");

    int Final = a_number;
    if (Final < b_number) {
        Final = b_number;
    }
    if (Final < c_number) {
        Final = c_number;
    }
         
    printf("%d\n", concat(concat(a, b), c));
}