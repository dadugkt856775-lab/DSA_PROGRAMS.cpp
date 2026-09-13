#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            lps[i] = ++len;
            i++;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            i++;
        }
    }

    return lps;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    vector<int> lps = buildLPS(pattern);

    int i = 0, j = 0;

    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == pattern.size()) {
            cout << "Pattern found at index "
                 << i - j << "\n";
            j = lps[j - 1];
        } else if (i < text.size() &&
                   text[i] != pattern[j]) {
            if (j > 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return 0;
}
