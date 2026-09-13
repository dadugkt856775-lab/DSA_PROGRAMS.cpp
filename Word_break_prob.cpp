#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    unordered_set<string> dictionary;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        dictionary.insert(word);
    }

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < i; j++) {
            string word = s.substr(j, i - j);

            if (dp[j] && dictionary.count(word)) {
                dp[i] = true;
                break;
            }
        }
    }

    if (dp[s.size()])
        cout << "Can be segmented";
    else
        cout << "Cannot be segmented";

    return 0;
}
