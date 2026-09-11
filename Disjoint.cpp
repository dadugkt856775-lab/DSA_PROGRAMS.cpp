#include <iostream>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rankValue;

public:
    DSU(int n) {
        parent.resize(n);
        rankValue.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (rankValue[a] < rankValue[b])
            swap(a, b);

        parent[b] = a;

        if (rankValue[a] == rankValue[b])
            rankValue[a]++;
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    int n, operations;

    cout << "Enter number of elements: ";
    cin >> n;

    DSU dsu(n);

    cout << "Enter number of connections: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        int a, b;

        cout << "Connect: ";
        cin >> a >> b;

        dsu.unite(a, b);
    }

    int a, b;

    cout << "Check connection between: ";
    cin >> a >> b;

    if (dsu.connected(a, b))
        cout << "They are connected.";
    else
        cout << "They are not connected.";

    return 0;
}
