#include <stdio.h>

int main(void) {
    /**
     * Boolean Expressions
     * If true -> an action -> rest of the program
    */
    printf("Enter an integer: -5\n");
    int a;
    a = -5;
    //scanf("%d", &a);
    if (a < 0) {
        a *= -1;   
    }
    printf("|a| = %d\n", a);

    /**
     * If, Else
     * Else will activate if the if condition is false.
     * This means logic can be cascaded.
    */
    int grade;
    char score;
    printf("Enter your grade between 0-100: \n");
    grade = 67;
    //scanf("%d", &grade);
    if (grade >= 90) {
        score = 'A';
    } else if (grade >= 80) { // if 1 is false
        score = 'B';
        } else if (grade >= 70) { // both if 1 and if 2 are false
            score = 'C';
            } else if (grade >= 60) { // if 1, if 2 and if 3 are false
                score = 'D';
                } else { // all previous ifs are false
                    score = 'F';
                    }
    printf("Your score is %c\n", score);

    // A nested if statement exercise
    // The output is -2
    int x = 5, y = 3;
    int ans = 0;

    if (x > y)
        ans = y - x;
    else if (x == 5)
        ans = y;
    else
        ans = 100;
    
    printf("%d\n", ans);

    // Exercise #2
    x = 6;
    y = 3;
    ans = 0;
    if (x > y)
        ans = 10;
    if (x == 5)
        ans -= 1;
    else
        ans += 1;
    printf("%d\n", ans);
    
    /**
     * Nested If Statements
     * 
     * Many more tests are required to gurantee the same result as nested if statements
     * Enter nested if statements when the logic is hierarchical
     * 
     * !!! Nested if statements can be rewritten as a series of if, else if, else statements. !!!
     */
    x = 5;
    // scanf("%d", &x);
    if (x < 10) {
        if (x > 5) 
            printf("Small \n");
        else 
            printf("Very Small \n");
    } 
    else {
        printf ("Large \n");
    }

    // A rewrite of the above program without nested if statements
    if (x < 10 && x > 5) {
        printf("Small \n");
    } 
    else if (x <= 5) {
        printf("Very Small \n");
    } 
    else {
        printf("Large \n");
    }

    // Exercise #3
    // Very tricky, the else is associated with the nearest if hence the program outputs nothing
    // This is also why brackets are necessary with if else statements otherwise nobody knows what you're saying
    // !!! INDENTATION MEANS NOTHING IN C !!!
    int i = 3;
    if (i % 2 == 0)
        if (i == 0)
            printf(" zero \n");
    else
        printf("how odd \n");


    /**
     * Ternary Condtional Operators
     * expr ? expr1 : expr2 means if expr1 is true, this conditional statement returns the value of expr2. otherwise, it returns the value of expr3.
     * Shorthand for if else statements.
     * 
     * You can have any number of case statements within a switch.
     * The constant expression for a case must be the same data type as the variable in the switch.
     * When the variable switched on is equal to a case, the statements following that case will execute until a break statement is reached.
     * When a break statement is reached, the switch terminates, and the control flow jumps to the next line following the switch statement
     */
    
    // An example of the grade program using a ternary conditional operator
    printf("Enter your grade between 0-100: %d\n", grade);
    switch (grade) {
        case 'A' : printf("Excellent\n"); 
            break;
        case 'B' : printf("Well Done\n");
            break;
        case 'C' : printf("Good\n");
            break;
        case 'D' : printf("You passed\n");
            break;
        case 'F' : printf("Better try again\n");
            break;
        default : printf("Invalid grade\n");
    }
    printf("Thank you.\n");
    

    // A devious exercise
    if (-5) { // Anything non-zero is true
        printf("a");
        printf("b");
    }
    else
        printf("c");
        printf("d"); // This line is not part of the else statement hence the output is "abd"
    

    // Another version of the above exercise

    if (-5) { // ; The semicolon ends the if statement hence the output is an error
        printf("a");
        printf("b");
    }
    else {
        printf("c");
        printf("d");
    }
    
    a = 7; 
    int b = 5;
    switch (a = a % b) {
        case 1 : a = a - b; // 2
        case 2 : a = a + b; // 7
        case 3 : a = a * b; // 35
        case 4 : a = a / b ; // 7
        default:
            printf("%d\n", a); // prints 7
    }
    printf("%d\n", b); // prints 5
    return 0;
}