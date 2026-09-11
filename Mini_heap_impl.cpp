#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

public:
    void insert(int value) {
        heap.push_back(value);

        int i = heap.size() - 1;

        while (i > 0) {
            int parent = (i - 1) / 2;

            if (heap[parent] <= heap[i])
                break;

            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    void removeMin() {
        if (heap.empty())
            return;

        heap[0] = heap.back();
        heap.pop_back();

        int i = 0;

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < heap.size() &&
                heap[left] < heap[smallest])
                smallest = left;

            if (right < heap.size() &&
                heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i)
                break;

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

    void display() {
        for (int x : heap)
            cout << x << " ";

        cout << endl;
    }
};

int main() {
    MinHeap h;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }

    cout << "Min Heap: ";
    h.display();

    h.removeMin();

    cout << "After removing minimum: ";
    h.display();

    return 0;
}
