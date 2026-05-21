#include <iostream>
#include <string>
using namespace std;

double balance = 1000;
string transactions[100];
int transactionCount = 0;

void depositMoney() {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;

        transactions[transactionCount] = "Deposited: money added";
        transactionCount++;

        cout << "Deposit successful.\n";
    } else {
        cout << "Invalid amount.\n";
    }
}

void withdrawMoney() {
    double amount;

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount <= balance && amount > 0) {
        balance -= amount;

        transactions[transactionCount] = "Withdrawn: money removed";
        transactionCount++;

        cout << "Withdrawal successful.\n";
    } else {
        cout << "Insufficient balance or invalid amount.\n";
    }
}

void checkBalance() {
    cout << "Current balance: " << balance << endl;
}

void viewTransactions() {
    cout << "\nTransaction History:\n";

    if (transactionCount == 0) {
        cout << "No transactions yet.\n";
        return;
    }

    for (int i = 0; i < transactionCount; i++) {
        cout << i + 1 << ". " << transactions[i] << endl;
    }
}

int main() {
    int pin = 1234;
    int enteredPin;
    int attempts = 0;

    while (attempts < 3) {
        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (enteredPin == pin) {
            cout << "Login successful.\n";
            break;
        } else {
            cout << "Incorrect PIN.\n";
            attempts++;
        }
    }

    if (attempts == 3) {
        cout << "Too many attempts. Access denied.\n";
        return 0;
    }

    int choice;

    do {
        cout << "\n===== ATM MENU =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. View Transactions\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance();
                break;

            case 2:
                depositMoney();
                break;

            case 3:
                withdrawMoney();
                break;

            case 4:
                viewTransactions();
                break;

            case 5:
                cout << "Thank you for using ATM.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
