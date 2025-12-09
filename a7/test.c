#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

/***
 * int substring_at_index()
 * Returns true if the word contains a the start to a substring at an index, else false.
 * 
 * @param const char *substring
 * @param const char *word
 * @param int index
 */
bool substring_at_index(const char *substring, const char *word, int index) {
    int substr_len = strlen(substring);
    for (int i = 0; i < substr_len; i++) {
        // We compare the sequence of characters
        // If there is a discrepency, no match
        if (substring[i] != word[i + index]) {
            return false;
        }
    }
    return true;
}

/***
 * int substring_at_index()
 * Removes substr_len characters right of position index 
 * 
 * @param int substr_len
 * @param const char *word
 * @param int index
 * 
 * requires: index is not out of bounds
 */
void remove_substring(int substr_len, char *word, int index) {
    int word_len = strlen(word);
    // Shift the entire string left by substr_len units
    // The characters from index to substr_len get overwritten
    for (int i = index; i < word_len - substr_len + 1; i++) {
        // The final character copied will be the null character
        word[i] = word[i + substr_len];
    }
}

/***
 * lookBehind()
 * Removes all instances of a substring from from a word preceded by another substring.
 * 
 * @param const char* check
 * @param const char* s_sub
 * @param char* word
 */
void lookBehind(const char* check, const char* s_sub, char* word) {
    int len_check = strlen(check);
    int substr_len = strlen(s_sub);

    // We loop through every letter in the whole word
    for (int i = 0; word[i] != '\0'; i++) {
        // Did we find our check?
        if (substring_at_index(check, word, i)) {
            // Now we have our lower bound, we check for s_sub
            int lower_bound = i + len_check;
            // We check that "sub-word" for the substring
            while (word[lower_bound] != ' ' && word[lower_bound] != '\0') {
                // Did we find a substring?
                if (substring_at_index(s_sub, word, lower_bound)) {
                    // Remove it!
                    remove_substring(substr_len, word, lower_bound);
                } else {
                    // We didn't find the substring, keep searching.
                    lower_bound++;
                }
            }
        }
    }
}

int main(void) {
    char word[] = "CS137137";

    lookBehind("CS", "137", word);
    int i = 0;
    while (word[i] != '\0') {
        printf("%c", word[i]);
        i++;
    }
    printf("\n");
}