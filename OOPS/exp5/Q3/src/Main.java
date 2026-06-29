  
class Worker {
    protected String name;
    protected double salaryRate;
    public Worker(){
    
    }

    public Worker(String name, double salaryRate) {
        this.name = name;
        this.salaryRate = salaryRate;
    }

    public double computePay(int hours) {
        return 0; 
    }
}


class DailyWorker extends Worker {
    public DailyWorker(String name, double salaryRate) {
        super(name, salaryRate);
    }

    @Override
    public double computePay(int hours) {
        int daysWorked = hours / 8;
        return daysWorked * salaryRate;
    }
}

class SalariedWorker extends Worker {
    public SalariedWorker(String name, double salaryRate) {
        super.name=name;
        super.salaryRate=salaryRate;
    }

    @Override
    public double computePay(int hours) {
        return salaryRate * 40;
    }
}


public class Main {
    public static void main(String[] args) {
        Worker dWorker = new DailyWorker("John", 500);
        Worker sWorker = new SalariedWorker("Alice", 600);

        System.out.println("Daily Worker Pay: " + dWorker.computePay(40)); 
        System.out.println("Salaried Worker Pay: " + sWorker.computePay(50)); 
    }
}

