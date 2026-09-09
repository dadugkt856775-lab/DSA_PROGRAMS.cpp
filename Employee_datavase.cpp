#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
    vector<tuple<int, string, double>> employees;

    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int id;
        string name;
        double salary;

        cout << "\nID: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Salary: ";
        cin >> salary;

        employees.push_back({id, name, salary});
    }

    sort(employees.begin(), employees.end(),
         [](const auto& a, const auto& b) {
             return get<2>(a) > get<2>(b);
         });

    cout << "\n===== EMPLOYEE RANKING =====\n";

    for (auto &e : employees) {
        cout << "ID: " << get<0>(e)
             << " | Name: " << get<1>(e)
             << " | Salary: ₹" << get<2>(e)
             << endl;
    }

    return 0;
}
