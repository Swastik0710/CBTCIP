#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_CATEGORY_LENGTH 20

// Structure to represent an expense
struct Expense {
    char category[MAX_CATEGORY_LENGTH];
    float amount;
};

// Function prototypes
void recordExpense(struct Expense *expenses, int *numExpenses);
void generateReport(struct Expense *expenses, int numExpenses);

int main() {
    struct Expense expenses[MAX_EXPENSES];  // Maximum 50 expenses
    int numExpenses = 0;
    int choice;

    do {
        printf("\nExpense Tracker\n");
        printf("1. Record Expense\n");
        printf("2. Generate Report\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                recordExpense(expenses, &numExpenses);
                break;
            case 2:
                generateReport(expenses, numExpenses);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to record a new expense
void recordExpense(struct Expense *expenses, int *numExpenses) {
    if (*numExpenses >= MAX_EXPENSES) {
        printf("Cannot record more expenses. Maximum limit reached.\n");
        return;
    }

    printf("Enter expense category: ");
    scanf(" %[^\n]", expenses[*numExpenses].category);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*numExpenses].amount);

    (*numExpenses)++;
    printf("Expense recorded successfully.\n");
}

// Function to generate and display expense report
void generateReport(struct Expense *expenses, int numExpenses) {
    if (numExpenses == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\nExpense Report\n");
    printf("------------------\n");
    printf("Category\tAmount\n");
    printf("------------------\n");

    float totalAmount = 0;
    for (int i = 0; i < numExpenses; i++) {
        printf("%s\t\t%.2f\n", expenses[i].category, expenses[i].amount);
        totalAmount += expenses[i].amount;
    }

    printf("------------------\n");
    printf("Total\t\t%.2f\n", totalAmount);
}