import java.util.Scanner;

class BankAccount {
    long accountNumber;
    String accountType;
    String depositorName;
    double balance;

    // Parameterized Constructor
    BankAccount(String depositor, long accNumber, String accType) {
        depositorName = depositor;
        accountNumber = accNumber;
        accountType = accType;

        System.out.println("New "+accountType+" Account : " + accountNumber + " is logged");
    }

    //Method to Initial Balance    
    void initialbalance(double amount) {
        if (amount > 0) {
            balance = amount;;
            System.out.println("Account Created with Rs.: " + amount + "\n");
        } else {
            System.err.println("Invalid deposit amount!\n");
        }
    }

    // Method to deposit amount
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: " + amount + "\n");
        } else {
            System.err.println("Invalid deposit amount!\n");
        }
    }

    // Method to withdraw amount
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawn: " + amount + "\n");
        } else if (amount > balance) {
            System.err.println("Insufficient balance!\n");
        } else {
            System.err.println("Invalid withdrawal amount!\n");
        }
    }

    // Method to display account details
    void balanceEnquiry() {
        System.out.println("Depositor Name: " + depositorName);
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Account Type: " + accountType);
        System.out.println("Current Balance: " + balance);
    }
}

public class Bank {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Create a bank account
        System.out.println("Enter depositor's name:");
        String depositorName = sc.nextLine();
        System.out.println("Enter account type (Savings/Current):");
        String accountType = sc.nextLine();
        System.out.println("Enter account number:");
        long accountNumber = sc.nextLong();
        System.out.println("Enter initial balance:");
        double initialBalance = sc.nextDouble();

        BankAccount account = new BankAccount(depositorName, accountNumber, accountType);

        account.initialbalance(initialBalance);
        System.out.println("How much you want to deposit ?");
        double depositAmt = sc.nextDouble();
        account.deposit(depositAmt);

        System.out.println("How much you want to WithDraw ?");
        double withdrawAmt = sc.nextDouble();
        account.withdraw(withdrawAmt);

        sc.close();
        account.balanceEnquiry();        
    }
}

