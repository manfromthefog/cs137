#include <stdio.h>


#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    int age;
    double salary;
};

/***
 * inputEmployees() sets the information for n employees
 * requires: employees and input n are valid
 */
void inputEmployees(struct Employee employees[], int n) {
    printf("Enter the details of %d employees:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Age: ");
        scanf("%d", &employees[i].age);
        printf("Salary: ");
        scanf("%lf", &employees[i].salary);
    }
}

/***
 * displayEmployees() displays the information for all employees
 */
void displayEmployees(struct Employee employees[], int n) {
    printf("Employee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: %d\n", employees[i].id);
        printf("Age: %d\n", employees[i].age);
        printf("Salary: %.2lf\n", employees[i].salary);
    }
}

/***
 * averageSalaray() computes the average salary for all employees
 */
double averageSalary(struct Employee employees[], int n) {
    // Sum the salaries of all workers
    double salary_sum = 0;
    for (int i = 0; i < n; i++) {
        salary_sum += employees[i].salary;
    }
    // Divide by the total number of employees
    return salary_sum / n;
}

/***
 * youngestEmployee() prints the info of the youngest employee
 * assumes: there is only one youngest employee
 */
void youngestEmployee(struct Employee employees[], int n) {
    // We have to find the minimum
    int youngest_id = 0, youngest_age = 0;
    double youngest_salary;
    for (int i = 0; i < n; i++) {
        if (i == 0) youngest_age = employees[i].age;
        // If we find a new youngest employee update variables
        if (employees[i].age <= youngest_age) {
            youngest_id = employees[i].id;
            youngest_age = employees[i].age;
            youngest_salary = employees[i].salary;
        }
    }

    printf("Youngest Employee:\n");
    printf("ID: %d\n", youngest_id);
    printf("Age: %d\n", youngest_age);
    printf("Salary: %.2lf\n", youngest_salary);
}

/***
 * salaryInRange() returns the number of employee salaries in a certain range
 * requires: minSalary < maxSalary
 */
int salaryInRange(struct Employee employees[], int n, double minSalary, double maxSalary) {
    // Make a counter
    int employee_in_range = 0;
    for (int i = 0; i < n; i++) {
        // If both bounds are satisfied then the salary is in bounds, inclusive
        if ((employees[i].salary >= minSalary) && (employees[i].salary <=  maxSalary)) {
            employee_in_range += 1;
        }
    }
    return employee_in_range;
}

/***
 * salaryRaise() updates all the salaries of the employees by a certain percent
 */
void salaryRaise(struct Employee employees[], int n, double increase) {
    for (int i = 0; i < n; i++) {
        employees[i].salary *= (1 + increase);
    }
}

/***
int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int n;
    
    printf("Enter the number of employees (up to %d): ", MAX_EMPLOYEES);
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_EMPLOYEES) {
        printf("Invalid number of employees.\n");
        return 1;
    }
    
    inputEmployees(employees, n);
    displayEmployees(employees, n);
    
    double avgSal = averageSalary(employees, n);
    printf("Average Salary: %.2lf\n", avgSal);
    
    youngestEmployee(employees, n);
    
    double minSalary, maxSalary;
    printf("Enter the salary range:\n");
    printf("Minimum Salary: ");
    scanf("%lf", &minSalary);
    printf("Maximum Salary: ");
    scanf("%lf", &maxSalary);
    
    int count = salaryInRange(employees, n, minSalary, maxSalary);
    printf("Number of employees in the given salary range: %d\n", count);

    salaryRaise(employees, n, 0.05);
    displayEmployees(employees, n);
    
    return 0;
}
***/
