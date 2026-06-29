#include <stdio.h>
#include <string.h>

struct Student {
    int rollNumber;
    char firstName[50];
    char lastName[50];
};

void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].rollNumber > arr[j + 1].rollNumber) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void displayStudents(struct Student arr[], int n) {
    printf("Student Details in Ascending Order of Roll Number:\n");
    
    printf("Roll Number\tFirst Name\tLast Name\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d %s %s\n", arr[i].rollNumber, arr[i].firstName, arr[i].lastName);
    }
}

int main() {
    
    const int n = 5;

    struct Student students[n];


    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("First Name: ");
        scanf("%s", students[i].firstName);  
        printf("Last Name: ");
        scanf("%s", students[i].lastName);   
    }

    bubbleSort(students, n);

    displayStudents(students, n);

return 0;
}

