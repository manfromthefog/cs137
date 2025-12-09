#include <stdio.h>

struct tod {
    int hours;
    int minutes;
};

void todPrint(struct tod when) {
    printf("%0.2d : %0.2d\n", when.hours, when.minutes);
}