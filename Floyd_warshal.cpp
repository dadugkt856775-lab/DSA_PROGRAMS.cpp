#include <bits/stdc++.h>
using namespace std;

int main() {
    int V;
    cin >> V;

    const int INF = 1e9;

    vector<vector<int>> dist(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> dist[i][j];

            if (dist[i][j] == -1)
                dist[i][j] = INF;
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF &&
                    dist[k][j] != INF) {
                    dist[i][j] =
                        min(dist[i][j],
                            dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    cout << "Shortest Path Matrix:\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
