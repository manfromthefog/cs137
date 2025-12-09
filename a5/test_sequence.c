// This is a very poor test client for the sequence module

// You are strongly recommended to build your own test client
// note: sequence_print is not tested

#include <assert.h>
#include "sequence.h"

int main(void) {
  // struct sequence s1 = {0};
  struct sequence s1 = sequence_init();
  s1 = sequence_insert_at(s1, 0, 1);
  sequence_print(s1); 

  // struct sequence s2 = {0};
  struct sequence s2 = sequence_init();
  sequence_print(s2); 
  s2 = sequence_insert_at(s2, 0, 1);
  sequence_print(s2); 
  
  assert(sequence_equiv(s1, s2));
  
  assert(sequence_length(s1) == 1);
  s1 = sequence_remove_at(s1, 0);
  assert(sequence_length(s1) == 0);
  struct sequence s_append = sequence_append(s2, s2);
  sequence_print(s_append); 
  assert(sequence_length(s_append) == 2);

  // struct sequence s3 = {0};
  struct sequence s3 = sequence_init();
  sequence_print(s3); 
  s3 = sequence_insert_at(s3, 0, -11);
  sequence_print(s3); 
  s3 = sequence_insert_at(s3, 0, -11);
  sequence_print(s3); 
  s3 = sequence_insert_at(s3, 0, 22);
  sequence_print(s3); 
  s3 = sequence_insert_at(s3, 0, 3);
  sequence_print(s3); 
  s3 = sequence_insert_at(s3, 0, 0);
  sequence_print(s3); 
  s3 = sequence_insert_at(s3, 3, 5);
  sequence_print(s3); 
  assert(sequence_length(s3) == 6);
  s3 = sequence_append(s3, s3);
  sequence_print(s3); 
  assert(sequence_length(s3) == 12);
  struct sequence s4 = sequence_init();
  s4 = sequence_remove_dups(s3);
  sequence_print(s4);
  assert(sequence_length(s4) == 5);
  s4 = sequence_remove_dups(s4);
  assert(sequence_length(s4) == 5);
  
  return 0;
}
