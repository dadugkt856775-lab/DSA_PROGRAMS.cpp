#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Product {
    string name;
    double price;
};

int main() {
    int n;

    cout << "Enter number of products: ";
    cin >> n;

    vector<Product> products(n);

    for (int i = 0; i < n; i++) {
        cout << "\nProduct name: ";
        cin >> products[i].name;

        cout << "Price: ";
        cin >> products[i].price;
    }

    sort(products.begin(), products.end(),
         [](const Product &a, const Product &b) {
             return a.price < b.price;
         });

    cout << "\n===== PRICE RANKING =====\n";

    for (int i = 0; i < products.size(); i++) {
        cout << i + 1 << ". "
             << products[i].name
             << " - ₹" << products[i].price
             << endl;
    }

    return 0;
}
