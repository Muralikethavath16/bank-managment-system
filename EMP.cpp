#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bank {
    int acc_no;
    char name[50];
    float balance;
};

struct Bank customers[100];
int count = 0;

// Function to create new account
void createAccount() {
    printf("\nEnter Account Number: ");
    scanf("%d", &customers[count].acc_no);
    printf("Enter Name: ");
    scanf(" %[^\n]", customers[count].name);
    printf("Enter Initial Balance: ");
    scanf("%f", &customers[count].balance);
    count++;
    printf("\n? Account Created Successfully!\n");
}

// Function to display all accounts
void displayAccounts() {
    if (count == 0) {
        printf("\nNo accounts found.\n");
        return;
    }
    printf("\n---- All Account Details ----\n");
    for (int i = 0; i < count; i++) {
        printf("\nAccount No: %d", customers[i].acc_no);
        printf("\nName: %s", customers[i].name);
        printf("\nBalance: %.2f\n", customers[i].balance);
    }
}

// Function to deposit money
void depositMoney() {
    int acc;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc);
    for (int i = 0; i < count; i++) {
        if (customers[i].acc_no == acc) {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            customers[i].balance += amount;
            printf("\n? Amount Deposited Successfully!\n");
            return;
        }
    }
    printf("\n? Account Not Found!\n");
}

// Function to withdraw money
void withdrawMoney() {
    int acc;
    float amount;
    printf("\nEnter Account Number: ");
    scanf("%d", &acc);
    for (int i = 0; i < count; i++) {
        if (customers[i].acc_no == acc) {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);
            if (amount > customers[i].balance) {
                printf("\n? Insufficient Balance!\n");
                return;
            }
            customers[i].balance -= amount;
            printf("\n? Withdrawal Successful!\n");
            return;
        }
    }
    printf("\n? Account Not Found!\n");
}

// Function to search an account
void searchAccount() {
    int acc;
    printf("\nEnter Account Number to Search: ");
    scanf("%d", &acc);
    for (int i = 0; i < count; i++) {
        if (customers[i].acc_no == acc) {
            printf("\nAccount Found!\n");
            printf("Account No: %d\n", customers[i].acc_no);
            printf("Name: %s\n", customers[i].name);
            printf("Balance: %.2f\n", customers[i].balance);
            return;
        }
    }
    printf("\n? Account Not Found!\n");
}

// Main Function
int main() {
    int choice;
    while (1) {
        printf("\n========== BANK MANAGEMENT SYSTEM ==========\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Search Account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: displayAccounts(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: searchAccount(); break;
            case 6: printf("\nThank you for using our bank system!\n"); exit(0);
            default: printf("\nInvalid Choice! Try Again.\n");
        }
    }
    return 0;
}


