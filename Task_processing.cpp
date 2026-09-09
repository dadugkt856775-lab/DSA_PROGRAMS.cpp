#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<string> tasks;

    tasks.push_back("Coding");
    tasks.push_back("Testing");
    tasks.push_front("Planning");
    tasks.push_back("Deployment");

    cout << "Tasks:\n";

    for (string task : tasks)
        cout << task << endl;

    cout << "\nCompleted: " << tasks.front() << endl;
    tasks.pop_front();

    cout << "Last task removed: " << tasks.back() << endl;
    tasks.pop_back();

    cout << "\nRemaining tasks:\n";

    for (string task : tasks)
        cout << task << endl;

    return 0;
}
