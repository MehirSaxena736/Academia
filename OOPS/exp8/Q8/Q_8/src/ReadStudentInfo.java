import java.io.FileReader;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ReadStudentInfo {
    public static void main(String[] args) {
        try {
            FileReader fileReader = new FileReader("student.txt");
            Scanner fileScanner = new Scanner(fileReader);
            
            while (fileScanner.hasNextLine()) {
                String line = fileScanner.nextLine();
                System.out.println(line);
            }
            
            fileScanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("Error: File not found. Please ensure the file exists.");
        }
    }
}
