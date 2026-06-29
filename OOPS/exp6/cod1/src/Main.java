import Balance.Account;

public class Main {
    public static void main(String[] args) {
        // Creating an Account object with a balance.
        Account myAccount = new Account(5000.75);
        
        // Calling the Display_Balance method
        myAccount.Display_Balance();
    }
}
