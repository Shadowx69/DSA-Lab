#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

template <typename T>
class Polynomial {
private:
    struct Node {
        T coeff;
        int degree;
        Node* next;
        Node(T c, int d) {
            coeff = c;
            degree = d;
            next = nullptr;
        }

    };
    Node* head;

public:
    Polynomial() {
        head = nullptr;
    }
    //file reader
    void readFromFile(const string& filename) {
        ifstream infile(filename);
        if (!infile) {
            cerr << "Error: Unable to open file '" << filename << "'" << endl;
            return;
        }
        T coeff;
        int degree;
        while (infile >> coeff >> degree) {
            insertTerm(coeff, degree);
        }
        infile.close();
    }

    //insert terms into the polynomial
    void insertTerm(T coeff, int degree) {
        if (coeff == 0) return;
        Node* newTerm = new Node(coeff, degree);
        if (!head || head->degree > degree) {
            newTerm->next = head;
            head = newTerm;
        } else {
            Node* curr = head;
            Node* prev = nullptr;
            //traversing
            while (curr && curr->degree < degree) {
                prev = curr;
                curr = curr->next;
            }
            if (curr && curr->degree == degree) {
                curr->coeff += coeff;
                delete newTerm;
            } else {
                prev->next = newTerm;
                newTerm->next = curr;
            }
        }
    }

    Polynomial<T> add(const Polynomial<T>& other) const {
        Polynomial<T> result;
        Node* p1 = head;
        Node* p2 = other.head;
        while (p1 || p2) {
            if (p1 && (!p2 || p1->degree < p2->degree)) {
                result.insertTerm(p1->coeff, p1->degree);
                p1 = p1->next;
            } else if (p2 && (!p1 || p2->degree < p1->degree)) {
                result.insertTerm(p2->coeff, p2->degree);
                p2 = p2->next;
            } else {
                result.insertTerm(p1->coeff + p2->coeff, p1->degree);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return result;
    }

    // Multiply two polynomials
    Polynomial<T> multiply(const Polynomial<T>& other) const {
        Polynomial<T> result;
        for (Node* p1 = head; p1; p1 = p1->next) {
            for (Node* p2 = other.head; p2; p2 = p2->next) {
                result.insertTerm(p1->coeff * p2->coeff, p1->degree + p2->degree);
            }
        }
        return result;
    }

    T evaluate(T x) const {
        T result = 0;
        for (Node* p = head; p; p = p->next) {
            result += p->coeff * pow(x, p->degree);
        }
        return result;
    }

    void display() const {
        if (!head) {
            cout << "0";
        } else {
            for (Node* p = head; p; p = p->next) {
                if (p != head && p->coeff > 0) cout << " + ";
                cout << p->coeff << "x^" << p->degree;
            }
        }
        cout << endl;
    }

    ~Polynomial() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Polynomial<double> p1, p2;
    string filename;
    int choice;

    cout << "Enter the name of the polynomial file = ";
    cin >> filename;
    p1.readFromFile(filename);
    p1.display();

    while (true) {
        cout << "\n1. ADD polynomial\n2. MULTIPLY polynomial\n3. EVALUATE polynomial\n4. QUIT\n";
        cout << "Enter choice = ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the file containing the polynomial to add = ";
            cin >> filename;
            p2.readFromFile(filename);
            Polynomial<double> sum = p1.add(p2);
            cout << "Sum: ";
            sum.display();
        } else if (choice == 2) {
            cout << "Enter the file containing the polynomial to multiply = ";
            cin >> filename;
            p2.readFromFile(filename);
            Polynomial<double> product = p1.multiply(p2);
            cout << "Product: ";
            product.display();
        } else if (choice == 3) {
            double x;
            cout << "Enter the value of x to evaluate = ";
            cin >> x;
            double result = p1.evaluate(x);
            cout << "Result: " << result << endl;
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice, try again." << endl;
        }
    }

    return 0;
}
