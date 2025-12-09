#include "vlinteger.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "vlinteger.h"
#include <stdlib.h>
#include <stdio.h>

struct linteger *vlintegerCreate(void){
	struct linteger *t1 = malloc(sizeof(struct linteger));
	t1->arr = NULL;
	t1->length = 0;	// no values in t1.
	return t1;
}

void vlintegerDestroy(struct linteger *t1){
	if (t1)	{
		free(t1->arr);	// free the inside array first
		free(t1);	// then free the structure
	}
}

void vlintegerRead(struct linteger *t1){
	int digit;
	//printf("Enter the digits separated by a space: ");
	while (scanf("%d", &digit) == 1)	{
		int newSize = t1->length + 1;
		// alocate the new size of array
		int *newArr = malloc(newSize * sizeof(int));
		for (int i = 0; i < t1->length; ++i)		{
			//copy the data from the old storage to the new storage
			newArr[i] = t1->arr[i];
		}
		newArr[t1->length] = digit;
		++t1->length;
		free(t1->arr);	// free the old array
		t1->arr = newArr;	// make arr point to the new array
	}

}

void vlintegerPrint(struct linteger *t1){
	printf("length=%d\n", t1->length);
	for (int i = 0; i < t1->length; ++i)	{
		printf("%d", t1->arr[i]);
	}
	printf("\n");
}

struct linteger *vlintegerAdd(struct linteger *t1, struct linteger *t2) {
	// First free some memory
	struct linteger *sum = malloc(sizeof(struct linteger));

	// what this means is choose the longer of the two lengths to be our result length
	int max_len = t1->length > t2->length ? t1->length : t2->length;
	sum->arr = malloc((max_len + 1) * sizeof(int)); // +1 for possible carry

	int digit_sum, unit, carry = 0; // vars in the addition algorithm
	for (int i = max_len - 1; i >= 0; i--) {
		// In addition we align number from the right
		// Array indicies start from the left, not the right
		// max_len - t.length accounts for length differences
		int i_t1 =  i - (max_len - t1->length);
		int i_t2 =  i - (max_len - t2->length);

		// when we add a long number to a short number, we assume zero if we reach the
		// end of the short number, otherwise add the aligned unit digits at that position
		int digit1 = 0, digit2 = 0;
		if (i_t1 >= 0 && i_t1 < t1->length) digit1 = t1->arr[i_t1];
		if (i_t2 >= 0 && i_t2 < t2->length) digit2 = t2->arr[i_t2];

		// we add the digits and the carry in the addition algorith,
		digit_sum = digit1 + digit2 + carry;
		// then we calculate the actual number at that unit
		unit = digit_sum % 10;
		// and calculate the carry (if it exists)
		carry = digit_sum / 10;

		*(sum->arr + i + 1) = unit; // store unit at current position
	}
	// In some cases, when we're adding two numbers of equal length
	// There's a final carry digit we didn't account for
	if (carry) {
		// The first element is carry
		sum->arr[0] = carry;
		// The true length is one more than our lengths due to carry
		sum->length = max_len + 1;
	} else {
		// We need to shift the entire array over by one (no zeros to the left)
		for (int j = 0; j < max_len; j++) {
			*(sum->arr + j) = *(sum-> arr + j + 1); 
		}
		// No final carry implies the max len is our sum length
		sum->length = max_len;
		// Realloc the mem which assumed there was a carry
		sum->arr = realloc(sum->arr	, max_len*sizeof(int));
	}
	return sum;
}

int main(void){
	struct linteger *int1 = vlintegerCreate();
	printf("Enter the digits separated by a space: \n");
	vlintegerRead(int1);
	vlintegerPrint(int1);
	// assert(int1->arr[0] !=0);

	char c;
	scanf("%c", &c);
	struct linteger *int2 = vlintegerCreate();
	printf("Enter the digits separated by a space: \n");
	vlintegerRead(int2);
	vlintegerPrint(int2);
	// assert(int2->arr[0] !=0);

	scanf("%c", &c);
	struct linteger *add = vlintegerAdd(int1, int2);
	printf("addition\n");
	vlintegerPrint(add);
	// assert(add->arr[0] !=0);

	vlintegerDestroy(int1);
	vlintegerDestroy(int2);
	vlintegerDestroy(add);	
}

/*

More Tests: small numbers and big numbers with carry forward.

*/