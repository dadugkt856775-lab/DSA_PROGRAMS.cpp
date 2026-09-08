#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> history;
    stack<string> redoStack;

    int choice;

    while (true) {
        cout << "\n===== TEXT EDITOR =====\n";
        cout << "1. Add Text\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Show Current Text\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            string text;

            cout << "Enter text: ";
            cin >> text;

            history.push(text);

            while (!redoStack.empty())
                redoStack.pop();

            cout << "Text added.\n";
        }

        else if (choice == 2) {
            if (history.empty()) {
                cout << "Nothing to undo.\n";
            }
            else {
                redoStack.push(history.top());
                history.pop();

                cout << "Undo successful.\n";
            }
        }

        else if (choice == 3) {
            if (redoStack.empty()) {
                cout << "Nothing to redo.\n";
            }
            else {
                history.push(redoStack.top());
                redoStack.pop();

                cout << "Redo successful.\n";
            }
        }

        else if (choice == 4) {
            if (history.empty()) {
                cout << "No text available.\n";
            }
            else {
                cout << "Current text: ";

                stack<string> temp = history;

                while (!temp.empty()) {
                    cout << temp.top() << " ";
                    temp.pop();
                }

                cout << endl;
            }
        }

        else if (choice == 5) {
            break;
        }
    }

    return 0;
}
