// The ticket booking system of Cinemax Theater has to be 
// implemented using C++ program. There are 10 rows and 7 seats
// in each row. Doubly circular linked list has to be maintained to 
// keep track of free seats at rows. Assume some random booking to 
// start with. Use array to store pointers (Head pointer) to each row.
// On demand
// The list of available seats is to be displayed
// The seats are to be booked
// The booking can be cancelled.

#include <iostream>
using namespace std;

struct Seat {
    int seatNumber;
    bool isBooked;
    Seat* next;
    Seat* prev;

    Seat(int num) : seatNumber(num), isBooked(false), next(nullptr), prev(nullptr) {}
};

class Theater {
    Seat* rows[10]; // Array of head pointers for each row

public:
    Theater() {
        for (int i = 0; i < 10; i++) {
            rows[i] = nullptr;
            createRow(i);
        }
    }

    void createRow(int row) {
        Seat* head = nullptr;
        Seat* tail = nullptr;
        for (int i = 1; i <= 7; i++) {
            Seat* newSeat = new Seat(i);
            if (!head) {
                head = tail = newSeat;
                head->next = head->prev = head; // Make it circular
            } else {
                tail->next = newSeat;
                newSeat->prev = tail;
                newSeat->next = head;
                head->prev = newSeat;
                tail = newSeat;
            }
        }
        rows[row] = head; // Store head pointer for the row
    }

    void displayAvailableSeats() {
        for (int i = 0; i < 10; i++) {
            cout << "Row " << i + 1 << ": ";
            Seat* temp = rows[i];
            do {
                if (!temp->isBooked) {
                    cout << temp->seatNumber << " ";
                }
                temp = temp->next;
            } while (temp != rows[i]);
            cout << endl;
        }
    }

    void bookSeat(int row, int seat) {
        if (row < 1 || row > 10 || seat < 1 || seat > 7) {
            cout << "Invalid seat number!" << endl;
            return;
        }
        Seat* temp = rows[row - 1];
        do {
            if (temp->seatNumber == seat) {
                if (!temp->isBooked) {
                    temp->isBooked = true;
                    cout << "Seat " << seat << " in Row " << row << " booked successfully." << endl;
                    return;
                } else {
                    cout << "Seat " << seat << " in Row " << row << " is already booked!" << endl;
                    return;
                }
            }
            temp = temp->next;
        } while (temp != rows[row - 1]);
    }

    void cancelBooking(int row, int seat) {
        if (row < 1 || row > 10 || seat < 1 || seat > 7) {
            cout << "Invalid seat number!" << endl;
            return;
        }
        Seat* temp = rows[row - 1];
        do {
            if (temp->seatNumber == seat) {
                if (temp->isBooked) {
                    temp->isBooked = false;
                    cout << "Booking for Seat " << seat << " in Row " << row << " canceled." << endl;
                    return;
                } else {
                    cout << "Seat " << seat << " in Row " << row << " is not booked!" << endl;
                    return;
                }
            }
            temp = temp->next;
        } while (temp != rows[row - 1]);
    }
};

int main() {
    Theater theater;
    int choice, row, seat;
    while (true) {
        cout << "\n1. Display Available Seats\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                theater.displayAvailableSeats();
                break;
            case 2:
                cout << "Enter row number (1-10): ";
                cin >> row;
                cout << "Enter seat number (1-7): ";
                cin >> seat;
                theater.bookSeat(row, seat);
                break;
            case 3:
                cout << "Enter row number (1-10): ";
                cin >> row;
                cout << "Enter seat number (1-7): ";
                cin >> seat;
                theater.cancelBooking(row, seat);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
