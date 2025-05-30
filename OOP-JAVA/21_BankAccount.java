public class BankAccount {
    // Instance variables
    private String depositorName;
    private String accountNumber;
    private String accountType;
    private double balance;

    public BankAccount(String depositorName, String accountNumber, String accountType, double initialBalance) {
        this.depositorName = depositorName;
        this.accountNumber = accountNumber;
        this.accountType = accountType;
        this.balance = initialBalance;
    }

    // Method to deposit an amount
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Successfully deposited Rs: " + amount + ". New balance: Rs: " + balance);
        } else {
            System.out.println("Deposit amount must be positive!");
        }
    }

    public void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                balance -= amount;
                System.out.println("Successfully withdrew Rs: " + amount + ". New balance: Rs: " + balance);
            } else {
                System.out.println("Insufficient balance. Withdrawal failed.");
            }
        } else {
            System.out.println("Withdrawal amount must be positive!");
        }
    }

    public void displayDetails() {
        System.out.println("Account Holder: " + depositorName);
        System.out.println("Account Balance: Rs: " + balance);
    }

    public static void main(String[] args) {
        BankAccount account = new BankAccount("Aashiq Rahaman", "123456789", "Savings", 5000.0);
        account.displayDetails();
        account.deposit(2000);
        account.withdraw(1500);
        account.withdraw(6000);
        account.displayDetails();
    }
}
