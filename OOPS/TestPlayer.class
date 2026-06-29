// Interface defining banking operations
interface Bank {
    void deposit(double amount);
    void withdraw(double amount);
}
// Account class implementing Bank interface
class Account implements Bank {
    private double balance;

    // Constructor
    public Account(double initialBalance) {
        this.balance = initialBalance;
    }

    // Overriding deposit method
    @Override
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: $" + amount);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    // Overriding withdraw method
    @Override
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawn: $" + amount);
        } else {
            System.out.println("Insufficient balance or invalid amount.");
        }
    }

    // Method to display balance
    public void displayBalance() {
        System.out.println("Current Balance: $" + balance);
    }
}
public class BankDemo {
    public static void main(String[] args) {
        // Creating an Account object with an initial balance
        Account myAccount = new Account(1000);

        // Performing transactions
        myAccount.displayBalance();
        myAccount.deposit(500);
        myAccount.withdraw(300);
        myAccount.withdraw(1500); // Should fail due to insufficient balance
        myAccount.displayBalance();
    }
}
