
 public class University {
    static String universityName = "UPES";  // Static variable
    String studentName;  // Non-static 

    
    public University(String studentName) {
        this.studentName = studentName;
    }

    
    static void displayUniversityName() {
        System.out.println("University Name: " + universityName);
    }

    
    void displayStudentInfo() {
        System.out.println("Student Name: " + studentName + ", University: " + universityName);
    }
    
    public static void main(String[] args) {
        
        University.displayUniversityName();

        
        University student1 = new University("Alice");
        University student2 = new University("Bob");

    
        student1.displayStudentInfo();
        student2.displayStudentInfo();

        
        University.universityName = "Delhi University";
        System.out.println("\nAfter changing university name:");
        University.displayUniversityName();
        student1.displayStudentInfo();
        student2.displayStudentInfo();
    }
}



