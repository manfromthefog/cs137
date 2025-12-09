#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***
 * naturalIntToString()
 * Converts a natural number to a string.
 * 
 * @param int n
 * requires: the input is a natural number (strictly positive integer)
 */
char* naturalIntToString(int n) {
    // First, figure out how much memory we need to allocate
    int len = 0, n_temp = n;
    while (n_temp != 0) {
        len++;
        n_temp /= 10;
    }
    
    // Reset n_temp for our next objective
    n_temp = n;
    char *result = malloc(len * sizeof(char) + 1); // +1 for null char

    // Now, for each digit, we assign it to resulting string as a character
    for (int i = len - 1; i >= 0; i--) {
        result[i] = (char)(n_temp % 10 + '0');
        n_temp /= 10;
    }
    result[len] = '\0';
    return result;
}

char *trueConcat(char *dest, char *append) {
    char *concat = malloc((strlen(dest) + strlen(append) + 1) * sizeof(char));
    strcpy(concat, dest);
    strcat(concat, append);
    return concat;
}

char* compressString(const char* str) {
    char *compressed_str = malloc(strlen(str) * sizeof(char) * 2 + 1);

    int i = 0, j = 0;
    while (str[i] != '\0') {
        // Find the current character
        char current = str[i];
        int frequency = 0;

        // Count the number of times it takes to get to the next character
        // That's our frequency for the current character
        while (str[i + frequency] == current) {
            frequency++;
        }

        // We convert our frequency to a string
        char *letter_frequency = naturalIntToString(frequency);

        // We now copy our compressed values over to our result string
        compressed_str[j++] = current;
        // Puts the letter frequency to the right of the character
        strcpy(compressed_str + j, letter_frequency);
        
        // Now we shift the indexes to get our next character
        i += frequency;
        // j count the true length of our current compression
        j += strlen(letter_frequency);

        // And free letter frequency
        free(letter_frequency);
    }
    compressed_str[j] = '\0';
    compressed_str = realloc(compressed_str, j + 1);
    return compressed_str;
}

// Initialize some memory
char* decompressString(const char* str) {
    int i = 0;
    char *result = malloc(sizeof(char));
    result[0] = '\0';
    while (str[i] != '\0') {
        char current = str[i];

        // Figure out the length of the frequency as a string
        int id = 1, frequency = 0;
        while (str[i + id] >= '0' && str[i + id] <= '9') {
            // And then, using this recurrence relation, convert it into an integer
            frequency = (frequency + (int)(str[i + id] - '0')) * 10;
            id++;
        }
        // we over multipled by an extra 10
        frequency /= 10;

        // We need to decompress each character
        char *decompressed_substr = malloc(frequency * sizeof(char) + 1);
        // Copy
        for (int k = 0; k < frequency; k++) {
            decompressed_substr[k] = current;
        }
        decompressed_substr[frequency] = '\0';

        // In each iteration, we free the result from the previous iteration
        // Update with our updated decompressed string
        char *updated_decompression = trueConcat(result, decompressed_substr);

        // During our final loop we still have one result unfreed, that will be
        // freed in main()
        free(result);
        result = updated_decompression;

        // Free the substring we appended
        free(decompressed_substr);
        i += id;
    }
    return result;
}

/*
int main() {
    char* compressedStr = compressString("AAAABBBBBTUuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuGHHHK   HH");
    printf("Compressed String: %s\n", compressedStr);

    char* decompressedStr = decompressString(compressedStr);
    printf("Decompressed String: %s\n", decompressedStr);

    free(compressedStr);
    free(decompressedStr);
    return 0;
}
*/
