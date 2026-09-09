#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, pair<string, int>> products;

    int n;
    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int id, quantity;
        string name;

        cout << "\nProduct ID: ";
        cin >> id;
        cout << "Product name: ";
        cin >> name;
        cout << "Quantity: ";
        cin >> quantity;

        products[id] = {name, quantity};
    }

    int searchId;
    cout << "\nEnter ID to search: ";
    cin >> searchId;

    auto it = products.find(searchId);

    if (it != products.end()) {
        cout << "Product: " << it->second.first << endl;
        cout << "Quantity: " << it->second.second << endl;
    } else {
        cout << "Product not found.";
    }

    return 0;
}
