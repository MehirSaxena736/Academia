#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int role;
    char first_name[50];
    char last_name[50];
    // Add more fields as needed
};

struct Student students[MAX_STUDENTS];
int student_count = 0;

void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("Cannot add more students. Limit reached.\n");
        return;
    }
    
    struct Student new_student;
    printf("Enter role: ");
    scanf("%d", &new_student.role);
    printf("Enter first name: ");
    scanf("%s", new_student.first_name);
    printf("Enter last name: ");
    scanf("%s", new_student.last_name);
    
    students[student_count++] = new_student;
    printf("Student added successfully.\n");
}

void findStudentByRole() {
    int role;
    printf("Enter role to find: ");
    scanf("%d", &role);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].role == role) {
            printf("Student found:\n");
            printf("Role: %d\n", students[i].role);
            printf("Name: %s %s\n", students[i].first_name, students[i].last_name);
            return;
        }
    }
    
    printf("Student with role %d not found.\n", role);
}

void findStudentByFirstName() {
    char first_name[50];
    printf("Enter first name to find: ");
    scanf("%s", first_name);
    
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].first_name, first_name) == 0) {
            printf("Student found:\n");
            printf("Role: %d\n", students[i].role);
            printf("Name: %s %s\n", students[i].first_name, students[i].last_name);
            return;
        }
    }
    
    printf("Student with first name %s not found.\n", first_name);
}

void countStudents() {
    printf("Total number of students: %d\n", student_count);
}

void deleteStudent() {
    int role;
    printf("Enter role of student to delete: ");
    scanf("%d", &role);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].role == role) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student with role %d deleted successfully.\n", role);
            return;
        }
    }
    
    printf("Student with role %d not found.\n", role);
}

void updateStudent() {
    int role;
    printf("Enter role of student to update: ");
    scanf("%d", &role);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].role == role) {
            printf("Enter new first name: ");
            scanf("%s", students[i].first_name);
            printf("Enter new last name: ");
            scanf("%s", students[i].last_name);
            printf("Student information updated successfully.\n");
            return;
        }
    }
    
    printf("Student with role %d not found.\n", role);
}

int main() {
    int choice;
    
    do {
        printf("\nSchool Management System\n");
        printf("1. Add Student\n");
        printf("2. Find Student by Role\n");
        printf("3. Find Student by First Name\n");
        printf("4. Count Students\n");
        printf("5. Delete Student\n");
        printf("6. Update Student\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                findStudentByRole();
                break;
            case 3:
                findStudentByFirstName();
                break;
            case 4:
                countStudents();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                updateStudent();
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
return 0;
}
