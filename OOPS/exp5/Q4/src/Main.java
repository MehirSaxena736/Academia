// Call hierarchy
abstract class Call {
    protected double rate;

    public Call(double rate) {
        this.rate = rate;
    }

    public abstract double calculateCharge(int duration);
}

class OrdinaryCall extends Call {
    public OrdinaryCall() {
        super(2.0); // Rate per minute
    }

    @Override
    public double calculateCharge(int duration) {
        return duration * rate;
    }
}

class UrgentCall extends Call {
    public UrgentCall() {
        super(3.5);
    }

    @Override
    public double calculateCharge(int duration) {
        return duration * rate;
    }
}

class LightningCall extends Call {
    public LightningCall() {
        super(5.0);
    }

    @Override
    public double calculateCharge(int duration) {
        return duration * rate;
    }
}

// Employee hierarchy
class Employee {
    private String name;
    private int id;
    private double salary;
    
    public Employee(String name, int id, double salary) {
        this.name = name;
        this.id = id;
        this.salary = salary;
    }
    
    public double getSalary() { return salary; }
    public String getName() { return name; }
    public int getId() { return id; }
    
    public void increaseSalary(double percentage) {
        salary += salary * (percentage / 100);
    }
}

class Manager extends Employee {
    private String department;
    
    public Manager(String name, int id, double salary, String department) {
        super(name, id, salary);
        this.department = department;
    }
    
    public String getDepartment() { return department; }
}

// Main class
public class Main {
    public static void main(String[] args) {
        // Demonstrate Employee hierarchy
        System.out.println("--- Employee Demonstration ---");
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

        // Demonstrate Call hierarchy
        System.out.println("\n--- Call Charge Calculation ---");
        OrdinaryCall ordinary = new OrdinaryCall();
        UrgentCall urgent = new UrgentCall();
        LightningCall lightning = new LightningCall();
        
        int callDuration = 10; // minutes
        
        System.out.println("Ordinary call charge for " + callDuration + " minutes: $" + 
                          ordinary.calculateCharge(callDuration));
        System.out.println("Urgent call charge for " + callDuration + " minutes: $" + 
                          urgent.calculateCharge(callDuration));
        System.out.println("Lightning call charge for " + callDuration + " minutes: $" + 
                          lightning.calculateCharge(callDuration));
    }
}