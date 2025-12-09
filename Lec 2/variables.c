/**
 * A variable is a name given to a storage area that programs can change.
 * Each variable in C has a specific type, which determines the size and layout of the      variable's memory.
 * 
 * Rules
 * 1. Must begin with a letter or underscore
 * 2. After the first letter, it can be letters, numbers or underscores
 * 3. Vars are case sensitive
 * 4. Cannot be keywords (int, while, for)
 * 
 * The TAs will manually determine the quality of your submission based on your comments and the quality of your code.
*/

#include <stdio.h>

int main(void) {
    // Convention (data_type name)
    /**
     * long _ -> allows the assignment of large numbers
     * unsigned -> non-negative numbers
     * 
     * eg. unsigned long long int -> value range of [0, 1.84e19 - 1], storage size of 8 bytes, and numeric of [0, 2^64 - 1]
     * 
     * The compiler will assign specific memory stacks to hold the variable and even more. Initatilizing the variable assigns it some random memory which means nothing.
     */

    int num = 1;
    char word = 'A';
    float decimal = 0.5;

    /**
     * printf(string, argument(s));
     * 
     * string -> what is displayed
     * argument(s) -> values that are displayed as placeholders in the string
     * 
     * Placeholders
     * 1. %d for signed integer
     * 2. %c for characters
     * 3. %u for unsigned character
     * 4. %f for floats
    */
    
    int z = 3;
    printf("1 + 2 = %d and %d + %d = 9\n ", z, z, z * 2);

    /**
     * Mathematical Operations
     * (), %, *, /, +, -
     * Left associative operations.
     * No exponent.
    */

    int x = 3;
    int y = 5;
    printf("%d\n", ((5 % 3) * 5));

    /**
     * Assignment Operators
     * 
     * Right-associative operation. Evaluable everything to the right first, then assign the value.
     * variable = expr for an initialized variable
     * variable operation= expr where the operation is mathematical is also valid
     * 
     * eg. a += 2; means a = a + 2;
     *     a *= b + c is not equal to a = a*b + c due to mssing brackets. If a is an object with other side effects, the operations 
     *     will not be the same!
     * 
     * !!! a += 2 is not the same as a =+ 2 !!!
    */

    int c = 5;
    int d = 3;

    printf("%d\n", 3 * d % c / 2);

    /**
     * Increments and Decrements
     * ++a means increment first, then use a
     * --a
     * 
     * a++ means use a first, then increment a by one
     * a--
    */

    int n = 3, m = 1;
    m += n++ +2; // means m = m + n + 2, then n = n + 1
    printf("%d and %d \n", m, n);

    /**
     * Nested Print Statements
     * 
     * !!! printf prints before returning a value !!!
     * printf("%d ", i) prints 10 and returns 3 (the number of characters printed)
     * printf("%d %d\n", printf("%d ", i), i * 4) becomes printf("%d %d\n", 3, 40), which prints 3 40\n and returns 5 (the number of characters printed)
     * Then printf("%d\n", j) prints 5\n.
     * 
     * 10 3 40
     * 5
    */
    int i = 10;
    //                        (      3       )  ( 40 )
    int j = printf("%d %d\n", printf("%d ", i), i * 4);
    printf("%d\n", j);

    /**
     * 
     * Logical Operators
     * 
     * ! -> NOT is right-associative and has the same precedence as unary + or -
     * && -> AND is left-associative and has higher precedence than ||
     * || -> OR is left-associative and has the lowest precedence of all logical operators
     * Relational operators <, >,<=,>= take lower precedence than arithmeticand are left-associative
     * Equality operators ==, != (note the double equal sign!) take lower precedence than relational operators and are left-associative
     */

    int k = 0;
    k != 0 && 4/k > 2; // is a safe operation because a != 0 is false, so the right side is not evaluated

    /**
     * De Morgan's Theorem in C
     * !(A && B) is equivalent to !A || !B
     * !(A || B) is equivalent to !A && !B
     * 
     * !!! A common error in C !!!
    */

    int a = 10, b = 15;
    a += ++b; 
    printf("%d\n", a);
    a = 10, b = 15;
    a += b++;
    printf("%d\n", a);
    a = 10, b = 15;
    a += --b;
    printf("%d\n", a);

    /**
     * Bitwise Operators
     * 
     * At the smallest scale, info is stored in bits and bytes.
     * A bit can assme either of two values, 0 and 1
     * A byte consists of eight bits.
     * All computer data is represented using binary.,
    */

    /**
     * User Input - scanf()
     * 
     * scanf("%d", &a);
     * 1. Looks for the standard input (stdin) to read an integer.
     * 2. The integer read will be stored in the memory address of a.
     * 3. If the input is not an integer, the value of a will not be changed. 
     * 4. If the user doesn't enter an integer, the previous value of a will remain.
     * 5. The & refers to the memory address of a. Don't doubt it for now.
     * 6. scanf()  ignores all whitespace and newline characters.
     */

    /**
     * The above code will look for user input of fractions of the form num/denom and store the numerator and denominator in the appropriate variables.
     * This idea will work not just for / but for any particular type of inputted format.
     * The inputted format, however, must match exactly to work.
     * This includes white spaces in the matching.
    */

    int o,p,q;
    printf("Enter an integers: \n");
    scanf("%d", &o);
    printf("Enter a fraction in the form x / y: \n");
    scanf("%d / %d", &p, &q);
    printf("______________________________________");
    printf("%d %d %d", o, p, q);
    return 0;
    return 0;
}