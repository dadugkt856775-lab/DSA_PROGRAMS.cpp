#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[100], rankk[100];

int findSet(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]);
}

void unite(int a, int b) {
    a = findSet(a);
    b = findSet(b);

    if (a != b) {
        if (rankk[a] < rankk[b])
            swap(a, b);
        parent[b] = a;

        if (rankk[a] == rankk[b])
            rankk[a]++;
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (auto &e : edges)
        cin >> e.u >> e.v >> e.w;

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.w < b.w;
         });

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rankk[i] = 0;
    }

    int cost = 0;

    cout << "MST Edges:\n";

    for (auto e : edges) {
        if (findSet(e.u) != findSet(e.v)) {
            unite(e.u, e.v);
            cout << e.u << " - " << e.v
                 << " : " << e.w << "\n";
            cost += e.w;
        }
    }

    cout << "Minimum Cost = " << cost;

    return 0;
}
