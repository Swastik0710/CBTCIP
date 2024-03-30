#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a bank account
struct BankAccount {
    int accountNumber;
    char accountType[20];
    float balance;
    float interestRate;
};

// Function prototypes
void createAccount(struct BankAccount *accounts, int *numAccounts);
void deposit(struct BankAccount *accounts, int numAccounts);
void withdraw(struct BankAccount *accounts, int numAccounts);
void checkBalance(struct BankAccount *accounts, int numAccounts);
void calculateInterest(struct BankAccount *accounts, int numAccounts);

int main() {
    struct BankAccount accounts[50];  // Maximum 50 accounts
    int numAccounts = 0;
    int choice;

    do {
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Calculate Interest\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                deposit(accounts, numAccounts);
                break;
            case 3:
                withdraw(accounts, numAccounts);
                break;
            case 4:
                checkBalance(accounts, numAccounts);
                break;
            case 5:
                calculateInterest(accounts, numAccounts);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to create a new bank account
void createAccount(struct BankAccount *accounts, int *numAccounts) {
    if (*numAccounts >= 50) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &accounts[*numAccounts].accountNumber);
    printf("Enter account type (Savings/Current): ");
    scanf(" %[^\n]", accounts[*numAccounts].accountType);
    printf("Enter initial balance: ");
    scanf("%f", &accounts[*numAccounts].balance);

    if (strcmp(accounts[*numAccounts].accountType, "Savings") == 0) {
        accounts[*numAccounts].interestRate = 5.0;  // 5% interest rate for Savings account
    } else if (strcmp(accounts[*numAccounts].accountType, "Current") == 0) {
        accounts[*numAccounts].interestRate = 0.0;  // 0% interest rate for Current account
    } else {
        printf("Invalid account type. Please choose Savings or Current.\n");
        return;
    }

    (*numAccounts)++;
    printf("Account created successfully.\n");
}

// Function to deposit funds into an account
void deposit(struct BankAccount *accounts, int numAccounts) {
    int accNum;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accNum);

    int index = -1;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    accounts[index].balance += amount;
    printf("Amount deposited successfully. Updated balance: %.2f\n", accounts[index].balance);
}

// Function to withdraw funds from an account
void withdraw(struct BankAccount *accounts, int numAccounts) {
    int accNum;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accNum);

    int index = -1;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > accounts[index].balance) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[index].balance -= amount;
    printf("Amount withdrawn successfully. Updated balance: %.2f\n", accounts[index].balance);
}

// Function to check balance of an account
void checkBalance(struct BankAccount *accounts, int numAccounts) {
    int accNum;

    printf("Enter account number: ");
    scanf("%d", &accNum);

    int index = -1;
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Current balance: %.2f\n", accounts[index].balance);
}

// Function to calculate interest for Savings accounts
void calculateInterest(struct BankAccount *accounts, int numAccounts) {
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountType, "Savings") == 0) {
            float interest = (accounts[i].balance * accounts[i].interestRate) / 100;
            accounts[i].balance += interest;
            printf("Interest calculated for account %d. Updated balance: %.2f\n", accounts[i].accountNumber, accounts[i].balance);
        }
    }
}