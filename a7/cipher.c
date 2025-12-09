#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse the entire string
void reverseString(char *str) {
    int str_len = strlen(str);
    char *reversed_str = malloc(str_len * sizeof(char) + 1); // +1 for the null character
    int i = 0;
    while (str[i] != '\0') {
        // The reverse index is opposite of the forward index
        // Hence reversing the string
        reversed_str[str_len - i - 1] = str[i];
        i++;
    }
    // Add the null character!
    reversed_str[str_len] = '\0';
    // Copy the reversed string to our string
    strcpy(str, reversed_str);
    free(reversed_str);
}
 
// Function to replace each vowel with the next consonant
void replaceVowels(char *str) {
    for (;*str;str++) {
        // Did we find a vowel?
        if (*str == 'A' || *str == 'E' || *str == 'I' || *str == 'O') {
            // If yes, shift it to the next consonant
            // Do this by adding 1 to the ascii character
            *str += 1;
        }
        else if (*str == 'U') *str = 'B'; // special conversion rule
    }
}
 
// Function to shift each consonant to the right by a number of positions
// equal to its ASCII value modulo 10
void shiftConsonants(char *str) {
   for (;*str;str++) {
        // All the vowels are gone
        // Aside from spaces, everything should be a consonant
        if (*str != ' ') {
            // First, we calculate the shift
            int shift = (*str) % 10;
            // Then we perform the shift with a modulo in case we exceed the alphabet
            // Then we add A back
            (*str) = (char)(((*str) - 'A' + shift) % 26  + 'A');
        }
   }
}
 
// DO NOT CHANGE MAIN
int main(void) {
    char inputString[101];
 
    // Read the input string
    printf("Enter a string (uppercase letters and spaces only): ");

    scanf("%100[^\n]s", inputString);
   
    // Reverse the entire string
    reverseString(inputString);
    printf("Reversed String: %s\n", inputString);
    
    // Replace vowels with the next consonant
    replaceVowels(inputString);
    printf("Replaced Vowels String: %s\n", inputString);
    
    // Shift consonants to the right
    shiftConsonants(inputString);
    // Print the final result
    printf("Ciphered String: %s\n", inputString);
 
    return 0;
}