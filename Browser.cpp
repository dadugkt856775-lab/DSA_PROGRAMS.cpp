#include <iostream>
#include <list>
using namespace std;

int main() {
    list<string> tabs;
    int choice;

    while (true) {
        cout << "\n===== BROWSER TAB MANAGER =====\n";
        cout << "1. Open Tab\n";
        cout << "2. Close Tab\n";
        cout << "3. Display Tabs\n";
        cout << "4. Count Tabs\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            string site;
            cout << "Enter website: ";
            cin >> site;

            tabs.push_back(site);
            cout << "Tab opened.\n";
        }

        else if (choice == 2) {
            string site;
            cout << "Enter website to close: ";
            cin >> site;

            auto it = find(tabs.begin(), tabs.end(), site);

            if (it != tabs.end()) {
                tabs.erase(it);
                cout << "Tab closed.\n";
            } else {
                cout << "Tab not found.\n";
            }
        }

        else if (choice == 3) {
            cout << "\nOpen Tabs:\n";

            for (auto &site : tabs)
                cout << site << endl;
        }

        else if (choice == 4) {
            cout << "Open tabs = " << tabs.size() << endl;
        }

        else if (choice == 5) {
            break;
        }
    }

    return 0;
}
