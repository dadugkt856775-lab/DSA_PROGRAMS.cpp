#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> occupied;
    int totalSlots;

    cout << "Enter total parking slots: ";
    cin >> totalSlots;

    int choice;

    while (true) {
        cout << "\n===== PARKING SYSTEM =====\n";
        cout << "1. Park Vehicle\n";
        cout << "2. Remove Vehicle\n";
        cout << "3. Check Slot\n";
        cout << "4. Display Occupied Slots\n";
        cout << "5. Available Slots\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int slot;
            cout << "Enter slot number: ";
            cin >> slot;

            if (slot < 1 || slot > totalSlots) {
                cout << "Invalid slot.\n";
            }
            else if (occupied.count(slot)) {
                cout << "Slot already occupied.\n";
            }
            else {
                occupied.insert(slot);
                cout << "Vehicle parked successfully.\n";
            }
        }

        else if (choice == 2) {
            int slot;
            cout << "Enter slot number: ";
            cin >> slot;

            if (occupied.erase(slot))
                cout << "Vehicle removed.\n";
            else
                cout << "Slot is already empty.\n";
        }

        else if (choice == 3) {
            int slot;
            cout << "Enter slot number: ";
            cin >> slot;

            if (occupied.count(slot))
                cout << "Slot occupied.\n";
            else
                cout << "Slot available.\n";
        }

        else if (choice == 4) {
            cout << "Occupied slots: ";

            for (int slot : occupied)
                cout << slot << " ";

            cout << endl;
        }

        else if (choice == 5) {
            cout << "Available slots: ";

            for (int i = 1; i <= totalSlots; i++) {
                if (!occupied.count(i))
                    cout << i << " ";
            }

            cout << endl;
        }

        else if (choice == 6) {
            break;
        }
    }

    return 0;
}
