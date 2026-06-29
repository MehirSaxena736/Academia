// Abstract class with abstract methods
abstract class Employee {
    protected String name;
    protected String role;

    // Constructor
    public Employee(String name, String role) {
        this.name = name;
        this.role = role;
    }

    // Abstract methods (to be implemented by subclasses)
    abstract double calculateSalary();
    abstract void displayDetails();
}
// Subclass Manager extends Employee
class Manager extends Employee {
    private double fixedSalary;

    // Constructor
    public Manager(String name, double fixedSalary) {
        super(name, "Manager");
        this.fixedSalary = fixedSalary;
    }

    // Overriding calculateSalary method
    @Override
    double calculateSalary() {
        return fixedSalary; // Fixed monthly salary
    }

    // Overriding displayDetails method
    @Override
    void displayDetails() {
        System.out.println("Employee Name: " + name);
        System.out.println("Role: " + role);
        System.out.println("Salary: $" + calculateSalary());
    }
}
// Subclass Developer extends Employee
class Developer extends Employee {
    private double hourlyRate;
    private int hoursWorked;

    // Constructor
    public Developer(String name, double hourlyRate, int hoursWorked) {
        super(name, "Developer");
        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
    }

    // Overriding calculateSalary method
    @Override
    double calculateSalary() {
        return hourlyRate * hoursWorked; // Salary based on hours worked
    }

    // Overriding displayDetails method
    @Override
    void displayDetails() {
        System.out.println("Employee Name: " + name);
        System.out.println("Role: " + role);
        System.out.println("Hourly Rate: $" + hourlyRate);
        System.out.println("Hours Worked: " + hoursWorked);
        System.out.println("Salary: $" + calculateSalary());
    }
}
public class Main {
    public static void main(String[] args) {
        // Creating a Manager object
        Employee manager = new Manager("Alice Johnson", 7000);

        // Creating a Developer object
        Employee developer = new Developer("Bob Smith", 50, 160);

        // Displaying details
        System.out.println("Manager Details:");
        manager.displayDetails();

        System.out.println("\nDeveloper Details:");
        developer.displayDetails();
    }
}
