public class Student {
    String name;  
    int age;

    
    public Student() {
        this.name = "unknown";
        this.age = 0;
    }

    
    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    
    public void displayDetails() {
        System.out.println("Student name: " + name);
        System.out.println("Student age: " + age);
    }

    public static void main(String[] args) {
        Student student1 = new Student();
        System.out.println("Using default constructor:");
        student1.displayDetails();

        Student student2 = new Student("Giyan", 20); 
        System.out.println("Using parameterized constructor:");
        student2.displayDetails();
    }
}



