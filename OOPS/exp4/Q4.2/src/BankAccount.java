public class BankAccount {
    public double balance; 

    
    public BankAccount(double initialBalance) {
        if (initialBalance >= 0) {
            this.balance = initialBalance;
        } else {
            System.out.println("Initial balance cannot be negative.");
            this.balance = 0;
        }
    }


    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: $" + amount);
        } else {
            System.out.println("Deposit amount must be positive.");
        }
    }

    
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawn: $" + amount);
        } else {
            System.out.println("Invalid withdrawal amount.");
        }
    }


    void checkBalance() {
        System.out.println("Current Balance: $" + balance);
    }

    public static void main(String[] args) {
        
        BankAccount myAccount = new BankAccount(500); 
        
        myAccount.deposit(200);  

        
        myAccount.checkBalance(); 

    
        myAccount.withdraw(100);  // ERROR: Cannot access protected method

        
        System.out.println(myAccount.balance);  // ERROR: balance has private access
    }
}

