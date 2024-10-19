#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedStr {
private:
    Node* head;

public:
    LinkedStr() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void removeFirst() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void removeLast() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void remove(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->data == value) {
            removeFirst();
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value " << value << " not found in the list." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    void display() {
        Node* temp = head;
        cout << "Values in the linked list are: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedStr list;

    for (int i = 10; i >= 1; --i) {
        list.insert(i);
    }

    list.display();

    list.removeFirst();
    list.removeLast();
    cout << "After removing first and last element: ";
    list.display();

    list.remove(5);
    cout << "After removing the 5 element: ";
    list.display();

    return 0;
}
