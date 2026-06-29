#include <stdio.h>

struct Employee {
    char name[50];
    char address[100];
    int age;
    double salary;
};

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    
    for (int i = 0; i < n; ++i) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Address: ");
        scanf("%s", employees[i].address);
        printf("Age: ");
        scanf("%d", &employees[i].age);
        printf("Salary: ");
        scanf("%lf", &employees[i].salary);
    }

    
    double totalSalary = 0;
    for (int i = 0; i < n; ++i) {
        totalSalary += employees[i].salary;
    }

    double averageSalary = totalSalary / n;

    printf("Average Salary: %lf\n", averageSalary);

return 0;
}
