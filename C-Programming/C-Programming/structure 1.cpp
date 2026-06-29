#include <stdio.h>


struct student {
    char name[50];
    int roll_no;
    float mark;
};

int main() {

    struct student s;

    printf("Enter name: ");
    scanf("%s", s.name);

    printf("Enter roll number: ");
    scanf("%d", &s.roll_no);

    printf("Enter mark: ");
    scanf("%f", &s.mark);


    printf("\nStudent Details:\n");
    printf("Name: %s\n", s.name);
    printf("Roll number: %d\n", s.roll_no);
    printf("Mark: %.2f\n", s.mark);

return 0;
}
