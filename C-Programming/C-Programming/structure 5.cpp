#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[50];
    int id;
    struct Date birthday; 
    float salary;
};

int main() {
    
    struct Employee employee;

    printf("Enter employee name: ");
    scanf("%s", employee.name);

    printf("Enter employee ID: ");
    scanf("%d", &employee.id);

    printf("Enter date of birth (day month year): ");
    scanf("%d %d %d", &employee.birthday.day, &employee.birthday.month, &employee.birthday.year);

    printf("Enter employee salary: ");
    scanf("%f", &employee.salary);

    printf("\nEmployee Information:\n");
    printf("Name: %s\n", employee.name);
    printf("ID: %d\n", employee.id);
    printf("Date of Birth: %d/%d/%d\n", employee.birthday.day, employee.birthday.month, employee.birthday.year);
    printf("Salary: $%.2f\n", employee.salary);

return 0;
}
