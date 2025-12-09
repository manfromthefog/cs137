// A module for an int sequence Struct (with a maximum length)
#include <stdbool.h>

// DO NOT CHANGE
extern const int SEQUENCE_MAXLEN; // define as 1024 in your .c file

struct sequence {
  int len;
  int maxlen;
  int data[1024];
};

// sequence_init() creates and returns an initialized seq to be empty
//   with maximum capacity SEQUENCE_MAXLEN
struct sequence sequence_init();

// sequence_length(seq) returns the number of items in seq
int sequence_length(const struct sequence seq);

// sequence_item_at(seq, pos) returns the item in seq at position pos
// requires: 0 <= pos < sequence_length(seq)
int sequence_item_at(const struct sequence seq, int pos);

// sequence_insert_at(seq, pos, val) inserts(adds) a new item with value val
//   at position pos in seq
// note: changes the position of items that were at position >= pos
// requires: 0 <= pos <= sequence_length(seq) < SEQUENCE_MAXLEN
struct sequence sequence_insert_at(struct sequence seq, int pos, int val);

// sequence_remove_at(seq, pos) removes the item at position pos in seq
//   and returns the updated sequence
// note: changes the position of items that were at position > pos
// requires: 0 <= pos < sequence_length(seq)
struct sequence sequence_remove_at(struct sequence seq, int pos);

//////////////////////////////////////////////////////////////////////////
// The above are the typical operations (functions) for a Sequence Struct. //
// You must also complete the following "Advanced" operations.          //
//////////////////////////////////////////////////////////////////////////

// sequence_equiv(seq1, seq2) determines if seq1 and seq2 are equivalent
//   (they both have the same length and have identical sequences of items)
bool sequence_equiv(const struct sequence seq1, const struct sequence seq2);

// sequence_print(seq) prints out the items in seq
//   using the format: "[item_0,item_1,...,item_last]\n"
//   or "[empty]\n"
// examples: [1,3,7]
//           [42]
//           [empty]
// effects: produces output
void sequence_print(const struct sequence seq);


// sequence_append(seq1, seq2) returns a new sequence with all items from seq1 
//     followed by all items from seq2
// requires: sequence_length(seq1) + sequence_length(seq2) <= SEQUENCE_MAXLEN
struct sequence sequence_append(struct sequence seq1, const struct sequence seq2);

// sequence_remove_dups(seq) creates a new copy of seq after removeing all duplicates from seq
//   (keeping each first occurrence)
// examples: [1,3,7] => [1,3,7]
//           [1,1,3,1,7,1,3] => [1,3,7]
struct sequence sequence_remove_dups(struct sequence seq);
