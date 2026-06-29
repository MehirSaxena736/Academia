import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class WriteStudentInfo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter student's name: ");
        String name = scanner.nextLine();
        System.out.print("Enter roll number: ");
        String rollNumber = scanner.nextLine();
        System.out.print("Enter grade: ");
        String grade = scanner.nextLine();

        try (FileWriter writer = new FileWriter("student.txt", true)) {
            writer.write("Name: " + name + ", Roll Number: " + rollNumber + ", Grade: " + grade + "\n");
            System.out.println("Student information written to file.");
        } catch (IOException e) {
            System.out.println("Error: Unable to write to file. " + e.getMessage());
        }

        scanner.close();
    }
}
