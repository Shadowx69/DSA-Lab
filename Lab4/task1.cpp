#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> myQueue;

    for (int i = 1; i <= 10; ++i) {
        myQueue.push(i);
        cout << "After inserting " << i << ":\n";
        cout << "Front element: " << myQueue.front() << endl;
        cout << "Back element: " << myQueue.back() << endl;
    }

    cout << "\n--- Removing and printing numbers ---\n";

    while (!myQueue.empty()) {
        cout << "Front element before removal: " << myQueue.front() << endl;
        cout << "Back element before removal: " << myQueue.back() << endl;

        cout << "Removing: " << myQueue.front() << endl;
        myQueue.pop();
    }

    return 0;
}
