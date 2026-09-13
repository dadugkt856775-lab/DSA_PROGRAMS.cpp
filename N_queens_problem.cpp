#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<string>> solutions;

bool safe(vector<string>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return false;
    }

    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void solve(vector<string>& board, int row) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (safe(board, row, col)) {
            board[row][col] = 'Q';
            solve(board, row + 1);
            board[row][col] = '.';
        }
    }
}

int main() {
    cin >> n;

    vector<string> board(n, string(n, '.'));

    solve(board, 0);

    cout << "Number of Solutions = "
         << solutions.size() << "\n";

    if (!solutions.empty()) {
        for (string row : solutions[0])
            cout << row << "\n";
    }

    return 0;
}
