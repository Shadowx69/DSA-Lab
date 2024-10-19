#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to insert an element at the end of the list
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;  // Insert as the first element
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to delete an element from the list
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        // if the value to delete is at the head
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << value << " from the list." << endl;
            return;
        }

        // search for the node to delete
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
        cout << "Deleted " << value << " from the list." << endl;
    }

    // Function to display the linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to search an element in the list
    void search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Value " << value << " found in the list." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Value " << value << " not found in the list." << endl;
    }
};
int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert an element\n";
        cout << "2. Delete an element\n";
        cout << "3. Display the list\n";
        cout << "4. Search for an element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insert(value);
                break;

            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;

            case 3:
                list.display();
                break;

            case 4:
                cout << "Enter the value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
