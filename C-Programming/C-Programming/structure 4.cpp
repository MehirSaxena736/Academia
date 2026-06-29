#include <stdio.h>
#include <string.h>

struct Employee {
    char name[50];
    char address[100];
    float salary;
};
void swap(struct Employee *a, struct Employee *b) {
    struct Employee temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(struct Employee arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void displayEmployees(struct Employee arr[], int n) {
    printf("Employee Details in Alphabetical Order of Name:\n");
    printf("Name\t\tAddress\t\tSalary\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s %.2f\n", arr[i].name, arr[i].address, arr[i].salary);
    }
}

int main() {
    
    const int n = 5;

    struct Employee employees[n];
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);  
        printf("Address: ");
        scanf("%s", employees[i].address);  
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }


    bubbleSort(employees, n);

    displayEmployees(employees, n);

return 0;
}
