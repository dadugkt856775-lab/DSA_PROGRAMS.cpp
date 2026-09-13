#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, amount;
    cin >> n >> amount;

    vector<int> coins(n);
    for (int &x : coins)
        cin >> x;

    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[amount] == INT_MAX)
        cout << "Not Possible";
    else
        cout << "Minimum Coins = " << dp[amount];

    return 0;
}
