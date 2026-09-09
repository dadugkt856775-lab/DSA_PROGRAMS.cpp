#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Player {
    string name;
    int score;
};

int main() {
    vector<Player> players = {
        {"Aman", 78},
        {"Rahul", 95},
        {"Kiran", 88},
        {"Arjun", 91},
        {"Vijay", 72},
        {"Sameer", 99},
        {"Ravi", 84}
    };

    int top;
    cout << "Enter number of top players: ";
    cin >> top;

    if (top > players.size())
        top = players.size();

    partial_sort(
        players.begin(),
        players.begin() + top,
        players.end(),
        [](const Player& a, const Player& b) {
            return a.score > b.score;
        }
    );

    cout << "\n===== TOP PLAYERS =====\n";

    for (int i = 0; i < top; i++) {
        cout << i + 1 << ". "
             << players[i].name
             << " - " << players[i].score
             << endl;
    }

    return 0;
}
