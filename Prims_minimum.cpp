#include <bits/stdc++.h>
using namespace std;

int main() {
    int V;
    cin >> V;

    vector<vector<pair<int, int>>> graph(V);

    int E;
    cin >> E;

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> key(V, INT_MAX);
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0});

    int cost = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        cost += weight;

        cout << "Selected: " << u
             << " Weight: " << weight << "\n";

        for (auto [v, w] : graph[u]) {
            if (!visited[v] && w < key[v]) {
                key[v] = w;
                pq.push({w, v});
            }
        }
    }

    cout << "Minimum Cost = " << cost;

    return 0;
}
