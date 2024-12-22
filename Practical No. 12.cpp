// Double-ended queue (deque) is a linear list in which additions and 
// deletions may be made at either end. Obtain a data representation 
// mapping a deque into a one- dimensional array. Write C++ 
// program to simulate deque with functions to add and delete 
// elements from either end of the deque

#include <iostream>
using namespace std;

class Deque {
    int arr[10];
    int front, rear;
    int size = 10;
public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == size - 1) || front == rear + 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int element) {
        if (isFull()) {
            cout << "Insertion failed. Deque is full!" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = size - 1;
        } else {
            front--;
        }
        arr[front] = element;
        cout << element << " successfully added to the front of the deque." << endl;
    }

    void insertRear(int element) {
        if (isFull()) {
            cout << "Insertion failed. Deque is full!" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = element;
        cout << element << " successfully added to the rear of the deque." << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deletion failed. Deque is empty!" << endl;
            return;
        }
        cout << "Removing element from the front: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deletion failed. Deque is empty!" << endl;
            return;
        }
        cout << "Removing element from the rear: " << arr[rear] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is currently empty!" << endl;
            return;
        }
        cout << "Current deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    dq.insertFront(5);
    dq.insertRear(10);
    dq.display();
    dq.deleteFront();
    dq.display();
    dq.insertRear(20);
    dq.deleteRear();
    dq.display();
    return 0;
}
