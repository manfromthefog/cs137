#include "sequence.h"
#include <stdbool.h>

const int SEQUENCE_MAXLEN = 1024;

struct sequence sequence_init() {
    struct sequence seq;
    seq.len = 0;
    seq.maxlen = SEQUENCE_MAXLEN;
    return seq;
}

int sequence_length(const struct sequence seq) {
    return seq.len;
}

int sequence_item_at(const struct sequence seq, int pos) {
    return seq.data[pos];
}

struct sequence sequence_insert_at(struct sequence seq, int pos, int val) {
    // what we first do is shift everything to the right by one unit
    for (int i = sequence_length(seq) - 1; i > pos - 1; i--)
        seq.data[i + 1] = seq.data[i];
    // Then we set the new spot to "val"
    seq.data[pos] = val;
    seq.len++; // increment the length b.c. we added an element
    return seq;
}

struct sequence sequence_remove_at(struct sequence seq, int pos) {
    // This time we shift left, naturally overwriting the element at "pos"
    for (int i = pos; i < seq.len - 1; i++)
        seq.data[i] = seq.data[i + 1];
    seq.data[seq.len - 1] = 0; // Good hygiene
    seq.len--; // decremeent the length b.c. we removed an element
    return seq;
}

bool sequence_equiv(const struct sequence seq1, const struct sequence seq2) {
    // Have checks for length and items
    if (sequence_length(seq1) != sequence_length(seq2))
        return false;
    int len = sequence_length(seq1);
    for (int i = 0; i < len; i++) {
        if (sequence_item_at(seq1, i) != sequence_item_at(seq2, i))
            return false;
    }
    return true;
}

void sequence_print(const struct sequence seq) {
    printf("[");
    // If empty, print "empty"
    if (sequence_length(seq) == 0) printf("empty");
    else {
        // Print all the values in between
        for (int i = 0; i < sequence_length(seq) - 1; i++) {
            printf("%d,", seq.data[i]);
        }
        // For the last value we do not end in a comma
        printf("%d", seq.data[sequence_length(seq) - 1]);
    }
    printf("]\n");
}

struct sequence sequence_append(struct sequence seq1, const struct sequence seq2) {
    // Initialize our appended array
    struct sequence result;
    // Add their lengths
    result.len = seq1.len + seq2.len;

    // Copy seq1's elements
    for (int i = 0; i < seq1.len; i++) {
        result.data[i] = seq1.data[i];
    }
    // Copy seq2's elements
    for (int j = 0; j < seq2.len; j++) {
        // We start counting from where seq1 ended
        result.data[seq1.len + j] = seq2.data[j];
    }
    return result;
}

struct sequence sequence_remove_dups(struct sequence seq) {
    // Nested for loops to strike out duplicates
    for (int i = 0; i < seq.len; i++) {
        // We will check all the elements starting from "j+1"
        for (int j = i + 1; j < seq.len;) {
            // We do not increment during removal. 
            // If we increase "j" as we decrease "len" and check "j+1"
            // Then we will skip over element "j"
            if (seq.data[j] == seq.data[i]) {
                seq = sequence_remove_at(seq, j);
            } 
            else { 
                // We only increment j if no match was found
                // Then we can properly check the next element
                j++;
            }
        } 
    }
    return seq;
}
