#include <iostream>
using namespace std;

struct Node {
    Node* child[26];
    bool isEnd;

    Node() {
        isEnd = false;

        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* current = root;

        for (char c : word) {
            int index = c - 'a';

            if (current->child[index] == nullptr)
                current->child[index] = new Node();

            current = current->child[index];
        }

        current->isEnd = true;
    }

    bool search(string word) {
        Node* current = root;

        for (char c : word) {
            int index = c - 'a';

            if (current->child[index] == nullptr)
                return false;

            current = current->child[index];
        }

        return current->isEnd;
    }
};

int main() {
    Trie trie;

    int n;
    cout << "Enter number of words: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        trie.insert(word);
    }

    string searchWord;

    cout << "Enter word to search: ";
    cin >> searchWord;

    if (trie.search(searchWord))
        cout << "Word found.";
    else
        cout << "Word not found.";

    return 0;
}
