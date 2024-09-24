#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Account class: This is for encapsulating account operations
class Account {
protected:
    double balance;

public:
    Account() : balance (0.00) {}
    
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << "\nNew Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
        
    }

    virtual void withdraw (double amount) = 0;
    virtual void checkBalance() const {
    	cout << "--------------------------------" << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

// Savings Account class with a minimum balance requirement
class SavingsAccount : public Account {
private:
    const double minimumBalance = 1000.00;

public:
    void withdraw(double amount) override {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl; 
		
		} else if (amount > balance) {
            cout << "Insufficient funds." << endl;
		
		} else if (balance - amount < minimumBalance) {
            cout << "Cannot withdraw...\nMinimum balance of " << minimumBalance << " must be maintained." << endl;
            
		} else {
            balance -= amount;
            cout << "Withdrew: " << amount << "\nNew Balance: " << balance << endl;
        }
    }
};

// Current Account class with no minimum balance requirement
class CurrentAccount : public Account {
public:
    void withdraw(double amount) override {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: " << amount << "\nNew Balance: " << balance << endl;
        }
    }
};

// Menu Class: Displays the various menus for user interaction
class Menu {
public:
    void showMainMenu() {
        cout << "\nMAIN MENU: \n1. Savings Account\n2. Current Account\n3. Exit\nChoose [1/2/3]: ";
        if (cin.fail()) {
 					    cin.clear(); cin.ignore(512, '\n');
					}
        
    }

    void showSubMenu() {
    	cout << "--------------------------------";
        cout << "\nSUB MENU: \n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Back\nChoose [1/2/3/4]: ";
        if (cin.fail()) {
 					    cin.clear(); cin.ignore(512, '\n');
					}
    }
};

int main() {
    Menu menu;
    int mainOption, subOption;
    SavingsAccount savings;
    CurrentAccount current;
	cout << "[B A N K  S Y S T E M]" << endl;
    do {
        menu.showMainMenu();
        cin >> mainOption;

        switch (mainOption) {
            case 1: {  // Savings Account
                do {
                    menu.showSubMenu();
                    cin >> subOption;
                    
                    if (subOption == 1) {
                        double amount;
                        cout << "--------------------------------" << endl;
                        cout << "Enter deposit amount: "; cin >> amount;
                        savings.deposit(amount);
                    if (cin.fail()) {
 					    cin.clear(); cin.ignore(512, '\n');
  					    cout << "--Not a number--" << endl;
					}
					
                    } else if (subOption == 2) {
                        double amount;
                        cout << "--------------------------------" << endl;
                        cout << "Enter withdrawal amount: "; cin >> amount;
                        savings.withdraw(amount);
                    if (cin.fail()) {
 					    cin.clear(); cin.ignore(512, '\n');
  					    cout << "--Not a number--" << endl;
					}
					
                    } else if (subOption == 3) {
                        savings.checkBalance();
                    }
                } while (subOption != 4);
                break;
            }
            case 2: {  // Current Account
                do {
                    menu.showSubMenu();
                    cin >> subOption;
                    if (subOption == 1) {
                        double amount;
                        cout << "--------------------------------" << endl;
                        cout << "Enter deposit amount: "; cin >> amount;
                        current.deposit(amount);
                    if (cin.fail()) {
 					    cin.clear(); cin.ignore(512, '\n');
  					    cout << "--Not a number--" << endl;
					}
					
                    } else if (subOption == 2) {
                        double amount;
                        cout << "--------------------------------" << endl;
                        cout << "Enter withdrawal amount: "; cin >> amount;
                        current.withdraw(amount);
                    if (cin.fail()) {
 					    cin.clear(); cin.ignore(512, '\n');
  					    cout << "--Not a number--" << endl;
					}
					
                    } else if (subOption == 3) {
                        current.checkBalance();
                    }
                } while (subOption != 4);
                break;
            }
            case 3: {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid option. Try again." << endl;
        }
    } while (mainOption != 3);

    return 0;
}
