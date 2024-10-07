#include <iostream>
#include <queue>

using namespace std;

void enqueue(queue<int>& q, int value) {
    q.push(value);
}

void dequeue(queue<int>& q) {
    if (!q.empty()) {
        q.pop();
    }
}

void reverseFirst10(queue<int>& q) {
    const int N = 10;

    if (q.size() < N) {
        cout << "Queue has less than 10 elements. Unable to reverse!" << endl;
        return;
    }

    // (store in array)
    int arr[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = q.front();
        dequeue(q);
    }

    // (reverse order(insert in rear of q))
    for (int i = N - 1; i >= 0; --i) {
        enqueue(q, arr[i]);
    }

    // (move the remaining elements to back of queue)
    int remainingElements = q.size() - N;
    for (int i = 0; i < remainingElements; ++i) {
        int frontElement = q.front();
        dequeue(q);
        enqueue(q, frontElement);
    }
}

void printQueue(queue<int>& q) {
    queue<int> temp = q;  //temporary queue
    while (!temp.empty()) {
        cout << temp.front() << " ";
        dequeue(temp);
    }
    cout << endl;
}

int main() {
    queue<int> q;

    for (int i = 1; i <= 16; ++i) {
        enqueue(q, i);
    }

    cout << "Original Queue: ";
    printQueue(q);

    // Reverse
    reverseFirst10(q);

    // Print
    cout << "Queue after reversing first 10 elements: ";
    printQueue(q);

    return 0;
}
