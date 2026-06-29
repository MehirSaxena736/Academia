#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to store student information
struct Student {
    char name[50];
    int roll;
    int attendance;
};

// Function prototypes
void markAttendance(struct Student students[], int studentCount);
void displayAttendance(struct Student students[], int studentCount);

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printf("\nStudent Attendance System Menu\n");
        printf("1. Mark Attendance\n");
        printf("2. Display Attendance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                markAttendance(students, studentCount);
                break;
            case 2:
                displayAttendance(students, studentCount);
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to mark attendance for a student
void markAttendance(struct Student students[], int studentCount) {
    if (studentCount < MAX_STUDENTS) {
        printf("\nEnter student name: ");
        scanf("%s", students[studentCount].name);
        printf("Enter roll number: ");
        scanf("%d", &students[studentCount].roll);
        printf("Enter attendance (1 for present, 0 for absent): ");
        scanf("%d", &students[studentCount].attendance);
        studentCount++;
        printf("Attendance marked successfully!\n");
    } else {
        printf("Maximum student limit reached!\n");
    }
}

// Function to display attendance for all students
void displayAttendance(struct Student students[], int studentCount) {
    if (studentCount == 0) {
        printf("No students registered yet!\n");
        return;
    }

    printf("\nAttendance Report:\n");
    printf("Name\tRoll\tAttendance\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s\t%d\t%s\n", students[i].name, students[i].roll, 
               students[i].attendance ? "Present" : "Absent");
}
}

