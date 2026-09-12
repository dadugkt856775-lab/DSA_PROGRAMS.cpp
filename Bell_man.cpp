#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);

    for (auto &e : edges)
        cin >> e.u >> e.v >> e.w;

    int source;
    cin >> source;

    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (auto e : edges) {
            if (dist[e.u] != INT_MAX &&
                dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    for (auto e : edges) {
        if (dist[e.u] != INT_MAX &&
            dist[e.u] + e.w < dist[e.v]) {
            cout << "Negative cycle detected";
            return 0;
        }
    }

    for (int i = 0; i < V; i++) {
        cout << i << " -> " << dist[i] << "\n";
    }

    return 0;
}
