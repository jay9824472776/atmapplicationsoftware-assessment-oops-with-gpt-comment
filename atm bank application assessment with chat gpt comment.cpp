#include <iostream>
#include <ctime>      // To display current date and time
using namespace std;

class ATM {
private:
    int pin;
    double balance;
    string accountHolderName;
    string accountNumber;
    string branchName;
    string address;

public:
    // Constructor to initialize balance, PIN, and account information
    ATM() : balance(20000), pin(12345), accountHolderName("John Doe"), accountNumber("1234567890"), 
            branchName("Main Branch"), address("123 Main Street, Cityville") {}

    // Display Welcome Screen with current date and time
    displayWelcomeScreen() {
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "==============================\n";
        cout << "     WELCOME TO ATM SYSTEM     \n";
        cout << "==============================\n";
        cout << "Current Date and Time: " << dt << endl;
    }

    // Display the options before entering PIN
     displayInitialMenu() {
        cout << "\n====== ATM Initial Menu ======\n";
        cout << "1. Enter PIN\n";
        cout << "2. Help\n";
        cout << "==============================\n";
    }

    // Display Help information
    displayHelp() {
        cout << "\n===== ATM Help =====\n";
        cout << "For assistance, please contact your bank's customer service.\n";
        cout << "Ensure you have your account number ready.\n";
        cout << "====================\n";
    }

    // Display Account Holder information after correct PIN
    displayAccountInfo() {
        cout << "\nAccount Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Branch: " << branchName << endl;
        cout << "Address: " << address << endl;
    }

    // Menu after successful login
    displayMenu() {
        cout << "\n====== ATM Menu ======\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "======================\n";
    }

    // Pin verification function (one attempt allowed)
    bool verifyPin(int enteredPin) {
        if (enteredPin == pin) {
            return true;
        } else {
            cout << "Incorrect PIN! You have only one attempt. Exiting...\n";
            return false;  // Exiting if PIN is incorrect
        }
    }

    // Deposit function
     deposit(double amount) {
        balance += amount;
        cout << "Successfully deposited Rs. " << amount << endl;
        displayBalance();
    }

    // Withdraw function
    withdraw(double amount) {
        if (amount > balance) {
            cout << "Unsuccessful withdrawal! Insufficient balance.\n";
            displayBalance();
        } else {
            balance -= amount;
            cout << "Successfully withdrawn Rs. " << amount << endl;
            displayBalance();
        }
    }

    // Display balance
     displayBalance() const {
        cout << "Current balance: Rs. " << balance << endl;
    }
};

int main() {
    ATM atm;
    int choice, enteredPin;
    double amount;
    
    atm.displayWelcomeScreen();  // Display welcome screen

    while (true) {
        atm.displayInitialMenu();  // Display initial menu
        cout << "Select an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter your PIN (only one attempt): ";
            cin >> enteredPin;

            // Check if PIN is correct (one attempt allowed)
            if (!atm.verifyPin(enteredPin)) {
                return 0;  // Exiting if PIN is incorrect
            }

            // Display account holder info after correct PIN
            atm.displayAccountInfo();

            // Display Menu after correct PIN
            while (true) {
                atm.displayMenu();
                cout << "Select an option: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        atm.displayBalance();
                        break;
                    case 2:
                        cout << "Enter amount to deposit: Rs. ";
                        cin >> amount;
                        atm.deposit(amount);
                        break;
                    case 3:
                        cout << "Enter amount to withdraw: Rs. ";
                        cin >> amount;
                        atm.withdraw(amount);
                        break;
                    case 4:
                        cout << "Thank you for using the ATM! Exiting...\n";
                        return 0;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                }
            }
        } else if (choice == 2) {
            atm.displayHelp();  // Display help information
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
    
    }

