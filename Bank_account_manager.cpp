#include <iostream>
#include <unordered_map>
using namespace std;

struct Account {
    string name;
    double balance;
};

int main() {
    unordered_map<int, Account> accounts;
    int choice;

    while (true) {
        cout << "\n===== BANK SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Display Accounts\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int acc;
            string name;
            double balance;

            cout << "Account number: ";
            cin >> acc;
            cout << "Name: ";
            cin >> name;
            cout << "Initial balance: ";
            cin >> balance;

            accounts[acc] = {name, balance};
            cout << "Account created.\n";
        }

        else if (choice == 2) {
            int acc;
            double amount;

            cout << "Account number: ";
            cin >> acc;
            cout << "Deposit amount: ";
            cin >> amount;

            if (accounts.find(acc) != accounts.end()) {
                accounts[acc].balance += amount;
                cout << "Deposit successful.\n";
            } else {
                cout << "Account not found.\n";
            }
        }

        else if (choice == 3) {
            int acc;
            double amount;

            cout << "Account number: ";
            cin >> acc;
            cout << "Withdraw amount: ";
            cin >> amount;

            if (accounts.find(acc) != accounts.end()) {
                if (accounts[acc].balance >= amount) {
                    accounts[acc].balance -= amount;
                    cout << "Withdrawal successful.\n";
                } else {
                    cout << "Insufficient balance.\n";
                }
            } else {
                cout << "Account not found.\n";
            }
        }

        else if (choice == 4) {
            int acc;
            cout << "Account number: ";
            cin >> acc;

            auto it = accounts.find(acc);

            if (it != accounts.end())
                cout << "Balance = ₹" << it->second.balance << endl;
            else
                cout << "Account not found.\n";
        }

        else if (choice == 5) {
            for (auto &a : accounts) {
                cout << "Account: " << a.first
                     << " | Name: " << a.second.name
                     << " | Balance: ₹" << a.second.balance
                     << endl;
            }
        }

        else if (choice == 6) {
            break;
        }
    }

    return 0;
}
