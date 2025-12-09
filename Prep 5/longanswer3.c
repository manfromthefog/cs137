#include <stdio.h>
#include <string.h>
#include <assert.h>

void remove_white_spaces(char *s) {
    int i = 0, j = 0;
    while(s[i] != '\0') {
        if (s[i] != ' ') {
            s[j++] = s[i];
        }
        i++;
    }
    s[j] = '\0';
}

void remove_chars(char *s, const char chars[], int len) {
    // Convert the chars array 
    int i = 0, k = 0;
   
    while (s[i] != '\0') {
        // Now we check for any possibility of matching
        int match = 0;
        for (int j = 0; j < len; j++) {
            if (s[i] == chars[j]) {
                match = 1;
                break;
            }
        }
        if (!match) {
            s[k++] = s[i];
        }
        i++;
    }
    s[k] = '\0';
}

int main(void)
{
    char ans1[] = "Ni ce Wor k !";
    remove_white_spaces(ans1);
    assert(strcmp(ans1, "NiceWork!") == 0);
    char ans2[] = "C S 1 37 ";
    remove_white_spaces(ans2);
    assert(strcmp(ans2, "CS137") == 0);
    char ans3[] = "aPwer fe ctx!";
    char remove[] = "!wa x";
    remove_chars(ans3, remove, 5);
    assert(strcmp(ans3,"Perfect")==0);
    return 0;
}
