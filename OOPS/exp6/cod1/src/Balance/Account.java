package Balance;

public class Account {
    private double balance;

    // Constructor
    public Account(double balance) {
        this.balance = balance;
    }

    // Method to display balance
    public void Display_Balance() {
        System.out.println("Account Balance: $" + balance);
    }
}
