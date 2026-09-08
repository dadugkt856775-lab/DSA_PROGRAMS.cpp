#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main() {
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    map<int, int> lengthCount;

    string word;

    while (ss >> word) {
        lengthCount[word.length()]++;
    }

    cout << "\n===== WORD LENGTH ANALYSIS =====\n";

    for (auto &x : lengthCount) {
        cout << "Length " << x.first
             << " -> " << x.second
             << " word(s)\n";
    }

    return 0;
}
