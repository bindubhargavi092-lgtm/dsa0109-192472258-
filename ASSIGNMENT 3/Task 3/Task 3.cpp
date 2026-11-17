#include <iostream>
using namespace std;

class Auditorium {
    int rows, seats;
    char** map;

public:
    Auditorium(int r, int s) : rows(r), seats(s), map(nullptr) {
        cout << "Event created" << endl;

        if (rows > 0 && seats > 0) {
            map = new char*[rows];

            for (int i = 0; i < rows; i++) {
                map[i] = new char[seats];

                for (int j = 0; j < seats; j++) {
                    map[i][j] = 'O';
                }
            }
        }
    }

    void book(int r, int s) {
        if (r >= 0 && r < rows && s >= 0 && s < seats) {
            if (map[r][s] == 'O') {
                map[r][s] = 'B';
                cout << "Seat booked" << endl;
            } else {
                cout << "Seat already booked" << endl;
            }
        } else {
            cout << "Invalid seat" << endl;
        }
    }

    void cancel(int r, int s) {
        if (r >= 0 && r < rows && s >= 0 && s < seats) {
            map[r][s] = 'O';
            cout << "Booking cancelled" << endl;
        } else {
            cout << "Invalid seat" << endl;
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seats; j++) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Auditorium() {
        for (int i = 0; i < rows && map != nullptr; i++) {
            delete[] map[i];
        }

        delete[] map;

        cout << "Event closed" << endl;
    }
};

int main() {
    Auditorium a(2, 3);

    a.book(0, 1);
    a.book(1, 2);

    a.display();

    a.cancel(0, 1);

    a.display();

    Auditorium* b = new Auditorium(2, 2);
    b->book(0, 0);
    b->display();

    delete b;

    {
        Auditorium c(1, 2);
        c.book(0, 1);
    }

    return 0;
}