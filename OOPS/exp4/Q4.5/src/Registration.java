public class Registration {  
    String coursename;  
    int coursecode;

    
    public Registration() {  
        this.coursename = "unknown";
        this.coursecode = 0;
    }


    public Registration(String coursename, int coursecode) {  
        this.coursename = coursename; 
        this.coursecode = coursecode;  
    }


    public void displayDetails() {  
        System.out.println("Course Name: " + coursename);
        System.out.println("Course Code: " + coursecode);
    }

    
    public static void main(String[] args) {  
        Registration reg = new Registration();  
        System.out.println("Using default constructor:");
        reg.displayDetails();

        Registration rege = new Registration("JAVA", 31);
        System.out.println("Course Details:");
        rege.displayDetails();
    }
}
