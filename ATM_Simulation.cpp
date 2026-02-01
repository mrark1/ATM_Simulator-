#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

/* ===================== ACCOUNT CLASS ===================== */
class Account {
public:
    int accNo;
    string name;
    int pin;
    double balance;

    Account(int a, string n, int p, double b) {
        accNo = a;
        name = n;
        pin = p;
        balance = b;
    }
};

/* ===================== GLOBAL VECTOR ===================== */
vector<Account> accounts;

/* ===================== LOAD ACCOUNTS ===================== */
void loadAccounts() {
    accounts.clear();
    ifstream file("accounts.txt");

    int acc, pin;
    string name;
    double bal;

    while (file >> acc >> name >> pin >> bal) {
        accounts.push_back(Account(acc, name, pin, bal));
    }
    file.close();
}

/* ===================== SAVE ACCOUNTS ===================== */
void saveAccounts() {
    ofstream file("accounts.txt");
    int i;
    for (i = 0; i < accounts.size(); i++) {
        file << accounts[i].accNo << " "
             << accounts[i].name << " "
             << accounts[i].pin << " "
             << accounts[i].balance << endl;
    }
    file.close();
}

/* ===================== LOG TRANSACTIONS ===================== */
void logTransaction(int acc, string type, double amount) {
    ofstream file("transactions.txt", ios::app);
    file << "Account: " << acc
         << " | " << type
         << " | Amount: " << amount << endl;
    file.close();
}

/* ===================== FIND ACCOUNT ===================== */
int findAccount(int accNo) {
    int i;
    for (i = 0; i < accounts.size(); i++) {
        if (accounts[i].accNo == accNo)
            return i;
    }
    return -1;
}

/* ===================== ATM MENU ===================== */
void atmMenu(int index) {
    int choice;

    do {
        cout << "\n========== ATM MENU ==========\n";
        cout << "1. Balance Inquiry\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Fund Transfer\n";
        cout << "5. Change PIN\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Current Balance: Rs. "
                 << fixed << setprecision(2)
                 << accounts[index].balance << endl;
        }

        else if (choice == 2) {
            double amt;
            cout << "Enter amount to deposit: ";
            cin >> amt;

            if (amt > 0) {
                accounts[index].balance += amt;
                logTransaction(accounts[index].accNo, "Deposit", amt);
                cout << "Deposit Successful!\n";
            } else {
                cout << "Invalid Amount!\n";
            }
        }

        else if (choice == 3) {
            double amt;
            cout << "Enter amount to withdraw: ";
            cin >> amt;

            if (amt > 0 && amt <= accounts[index].balance) {
                accounts[index].balance -= amt;
                logTransaction(accounts[index].accNo, "Withdrawal", amt);
                cout << "Please collect your cash.\n";
            } else {
                cout << "Insufficient Balance or Invalid Amount!\n";
            }
        }

        else if (choice == 4) {
            int targetAcc;
            double amt;

            cout << "Enter target account number: ";
            cin >> targetAcc;
            cout << "Enter amount: ";
            cin >> amt;

            int tIndex = findAccount(targetAcc);

            if (tIndex != -1 && amt > 0 && amt <= accounts[index].balance) {
                accounts[index].balance -= amt;
                accounts[tIndex].balance += amt;

                logTransaction(accounts[index].accNo, "Transfer Sent", amt);
                logTransaction(targetAcc, "Transfer Received", amt);

                cout << "Transfer Successful!\n";
            } else {
                cout << "Transfer Failed!\n";
            }
        }

        else if (choice == 5) {
            int newPin;
            cout << "Enter new 4-digit PIN: ";
            cin >> newPin;

            if (newPin >= 1000 && newPin <= 9999) {
                accounts[index].pin = newPin;
                cout << "PIN Changed Successfully!\n";
            } else {
                cout << "Invalid PIN!\n";
            }
        }

    } while (choice != 6);

    saveAccounts();
}

/* ===================== MAIN FUNCTION ===================== */
int main() {
    loadAccounts();

    /* Create default accounts if file is empty */
    if (accounts.size() == 0) {
        accounts.push_back(Account(1001, "Arpit", 1234, 5000));
        accounts.push_back(Account(1002, "User", 4321, 8000));
        saveAccounts();
    }

    int accNo, pin;
    cout << "========== WELCOME TO ATM ==========\n";
    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter PIN: ";
    cin >> pin;

    int index = findAccount(accNo);

    if (index != -1 && accounts[index].pin == pin) {
        cout << "\nLogin Successful! Welcome "
             << accounts[index].name << endl;
        atmMenu(index);
    } else {
        cout << "\nInvalid Account Number or PIN!\n";
    }

    cout << "\nThank you for using ATM.\n";
    return 0;
}

