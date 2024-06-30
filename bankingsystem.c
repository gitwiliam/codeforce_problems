#include <stdio.h>

// Function prototypes
//void checkBalance(double balance);
void depositMoney(double *balance);
void withdrawMoney(double *balance);

int main() {
    double balance = 0.0;
    int choice;

    do {
        // Display menu
        printf("===== Banking System Menu =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("===============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            case 1:
                printf("Your current balance is: $%.2f\n", balance);
                break;
            case 2:
                depositMoney(&balance);
                break;
            case 3:
                withdrawMoney(&balance);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function definitions
void depositMoney(double *balance) {
    double amount;
    printf("Enter the amount to deposit: $");
    scanf("%lf", &amount);
    *balance += amount;
    printf("Deposit of $%.2f successful. New balance is: $%.2f\n", amount, *balance);
}

void withdrawMoney(double *balance) {
    double amount;
    printf("Enter the amount to withdraw: $");
    scanf("%lf", &amount);
    if (amount > *balance) {
        printf("Insufficient funds. Withdrawal cancelled.\n");
    } else {
        *balance -= amount;
        printf("Withdrawal of $%.2f successful. New balance is: $%.2f\n", amount, *balance);
    }
}
