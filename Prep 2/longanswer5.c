#include <stdio.h>
#include <math.h>
/***
 * We notice here that the entire program involves grabbing a number, removing the tail digit and
 * reprinting it again.
 * When we hit zero, we have to reprint all the way back. I think the way we do this is by
 * printing to one, and then using a separate for loop to print back.
 * 
 * The above method actually doesn't work, we need to recongize a very neat trick.
 */

void funprint(long long int num) {
    if (num == 0){
        return;
    }

    // A very valuable lesson on recursion: the recursive call happens WHERE IT IS CALLED. In this case we can quite literally sandwich our output.
    printf("%lld\n", num);
    funprint(num / 10);
    printf("%lld\n", num);

}

int main(void) {
    long long int n;
    scanf("%lld", &n);
    funprint(n);
}