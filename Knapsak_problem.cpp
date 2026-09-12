#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<int> weight(n), value(n);

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    for (int i = 0; i < n; i++)
        cin >> value[i];

    vector<int> dp(capacity + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = capacity; w >= weight[i]; w--) {
            dp[w] = max(dp[w],
                        dp[w - weight[i]] + value[i]);
        }
    }

    cout << "Maximum Value = " << dp[capacity];

    return 0;
}
