#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Forget about this

int stringtoInt(char *s) {
    int sum = 0;
    for (;*s;s++) {
        sum = (sum + (int)(*s - '0')) * 10;
    }
    return sum/10;
}

bool isValidDate(char *date) {
    for (int i=0;i<4;i++) {
        if (!(date[i] > 47 && date[i] < 58))
            return false;
    }

    // months
    bool winter = true;
    bool febspecial = false;
    if (!(date[4]>47 && date[4]<51)) {
        return false;
    } else if (date[4] == '0') winter = false;

    if (winter)
        if (!(date[5]=='0' || date[5]=='1' || date[5]=='2'))
            return false;
    else {
        if (!(date[5]>='0' && date[5]<='9'))
            return false;
        else if (date[5] == '2') febspecial = true;
    }

    // dates
    bool thirty = false;
    
    if (!(date[6]>='0' && date[6]<='3'))
        return false;
    else if (date[6] == '3') thirty = true;

    if (thirty)
        if (!(date[7]==0 || date[7]==1)) return false;
    else
        if (!(date[7]>='0' && date[7]<='9')) {
            return false;
        }
    
    if (febspecial && (date[6]>='2' && date[7]>='8')) return false;
}

char *updateOldDate(char *olddate) {
    int n = strlen(olddate);
    char *r = malloc(n*2*sizeof(char));

    if (!isValidDate(olddate)) {
        printf("Invalid Date\n");
        return;
    }
}

int main() {
    // Write C code here
    char s[] = "20251204";

    return 0;
}