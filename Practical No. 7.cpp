// Second year Computer Engineering class, set A of students like
// Vanilla Ice-cream and set B of students like butterscotch ice-cream. Write C++ program to store two sets using linked list.
// compute and display-Set of students who like both vanilla and butterscotch
// Set of students who like either vanilla or butterscotch or not both
// Number of students who like neither vanilla nor butterscotch.

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

void insert(Node*& head, const string& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

bool exists(Node* head, const string& value) {
    while (head != nullptr) {
        if (head->data == value)
            return true;
        head = head->next;
    }
    return false;
}

Node* intersection(Node* setA, Node* setB) {
    Node* result = nullptr;
    while (setA != nullptr) {
        if (exists(setB, setA->data)) {
            insert(result, setA->data);
        }
        setA = setA->next;
    }
    return result;
}

Node* unionSets(Node* setA, Node* setB) {
    Node* result = nullptr;
    while (setA != nullptr) {
        insert(result, setA->data);
        setA = setA->next;
    }
    while (setB != nullptr) {
        if (!exists(result, setB->data)) {
            insert(result, setB->data);
        }
        setB = setB->next;
    }
    return result;
}

Node* symmetricDifference(Node* setA, Node* setB) {
    Node* result = nullptr;
    while (setA != nullptr) {
        if (!exists(setB, setA->data)) {
            insert(result, setA->data);
        }
        setA = setA->next;
    }
    while (setB != nullptr) {
        if (!exists(result, setB->data)) {
            insert(result, setB->data);
        }
        setB = setB->next;
    }
    return result;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* setA = nullptr;
    Node* setB = nullptr;

    int nA, nB;
    cout << "Enter the number of students who like Vanilla Ice Cream: ";
    cin >> nA;
    cout << "Enter the names of students who like Vanilla Ice Cream: \n";
    for (int i = 0; i < nA; i++) {
        string name;
        cin >> name;
        insert(setA, name);
    }

    cout << "Enter the number of students who like Butterscotch Ice Cream: ";
    cin >> nB;
    cout << "Enter the names of students who like Butterscotch Ice Cream: \n";
    for (int i = 0; i < nB; i++) {
        string name;
        cin >> name;
        insert(setB, name);
    }

    Node* both = intersection(setA, setB);
    Node* either = unionSets(setA, setB);
    Node* notBoth = symmetricDifference(setA, setB);

    cout << "Students who like both Vanilla and Butterscotch: \n";
    display(both);

    cout << "Students who like either Vanilla or Butterscotch or not both: \n";
    display(notBoth);

    cout << "Number of students who like neither Vanilla nor Butterscotch: \n";
    int totalStudents;
    cout << "Enter the total no of students in the class: ";
    cin >> totalStudents;

    int neitherCount = totalStudents - (nA + nB - (nA - nB));
    cout << "Number of students who like neither: " << neitherCount << endl;

    return 0;
}
