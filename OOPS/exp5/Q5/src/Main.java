
class Employee {
    protected String name;
    protected int empId;
    protected double salary;

    public Employee() { // Default constructor
        this.name = "Unknown";
        this.empId = 0;
        this.salary = 0.0;
    }

    public Employee(String name, int empId, double salary) { // Parameterized constructor
        this.name = name;
        this.empId = empId;
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public void increaseSalary(double percentage) {
        salary += salary * (percentage / 100);
    }
}

// Manager.java
class Manager extends Employee {
    private String department;

    public Manager(String name, int empId, double salary, String department) {
        super(name, empId, salary);
        this.department = department;
    }

    public String getDepartment() {
        return department;
    }
}

// Main.java
public class Main {
    public static void main(String[] args) {
        Employee emp = new Employee("John Doe", 101, 50000);
        System.out.println("Employee Salary Before Raise: " + emp.getSalary());
        emp.increaseSalary(10);
        System.out.println("Employee Salary After 10% Raise: " + emp.getSalary());

        Manager mgr = new Manager("Alice Smith", 102, 80000, "IT");
        System.out.println("Manager Name: " + mgr.getName());
        System.out.println("Manager Department: " + mgr.getDepartment());
        System.out.println("Manager Salary Before Raise: " + mgr.getSalary());
        mgr.increaseSalary(15);
        System.out.println("Manager Salary After 15% Raise: " + mgr.getSalary());
    }
}

