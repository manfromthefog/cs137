#include <stdio.h>

typedef struct {
    int x;
    int y;
} point;

int sqrDistance(point a, point b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

point find() {
    point max_point = {0, 0};
    point zero = {0, 0};

    int max_distance = 0;
    point curr_point;

    int x, y;

    while (scanf("%d %d", &x, &y) == 2) {
        curr_point.x = x;
        curr_point.y = y;

        if (sqrDistance(curr_point, zero) >= max_distance) {
            max_distance = sqrDistance(curr_point, zero);
            max_point = curr_point;
        }
    }
    return max_point;
}

int main(void) {
    point max = find();
    printf("%d, %d\n", max.x, max.y);
    return 0;
}