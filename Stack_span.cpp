#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> price(n);
    for (int &x : price)
        cin >> x;

    vector<int> span(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {

        while (!st.empty() &&
               price[st.top()] <= price[i]) {
            st.pop();
        }

        if (st.empty())
            span[i] = i + 1;
        else
            span[i] = i - st.top();

        st.push(i);
    }

    for (int x : span)
        cout << x << " ";

    return 0;
}
