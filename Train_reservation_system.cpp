#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Passenger {
    string name;
    int age;
};

int main() {
    map<int, Passenger> reservations;
    const int totalSeats = 10;

    int choice;

    while (true) {
        cout << "\n===== TRAIN RESERVATION =====\n";
        cout << "1. Book Seat\n";
        cout << "2. Cancel Seat\n";
        cout << "3. Search Passenger\n";
        cout << "4. Display Reservations\n";
        cout << "5. Available Seats\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int seat;
            string name;
            int age;

            cout << "Seat number (1-10): ";
            cin >> seat;

            if (seat < 1 || seat > totalSeats) {
                cout << "Invalid seat.\n";
                continue;
            }

            if (reservations.count(seat)) {
                cout << "Seat already booked.\n";
                continue;
            }

            cout << "Passenger name: ";
            cin >> name;

            cout << "Age: ";
            cin >> age;

            reservations[seat] = {name, age};

            cout << "Seat booked successfully.\n";
        }

        else if (choice == 2) {
            int seat;
            cout << "Enter seat number: ";
            cin >> seat;

            if (reservations.erase(seat))
                cout << "Reservation cancelled.\n";
            else
                cout << "Seat not booked.\n";
        }

        else if (choice == 3) {
            string name;
            cout << "Enter passenger name: ";
            cin >> name;

            bool found = false;

            for (auto &r : reservations) {
                if (r.second.name == name) {
                    cout << "Seat: " << r.first << endl;
                    cout << "Age: " << r.second.age << endl;
                    found = true;
                }
            }

            if (!found)
                cout << "Passenger not found.\n";
        }

        else if (choice == 4) {
            for (auto &r : reservations) {
                cout << "Seat " << r.first
                     << " -> " << r.second.name
                     << " (" << r.second.age << ")\n";
            }
        }

        else if (choice == 5) {
            cout << "Available seats: ";

            for (int i = 1; i <= totalSeats; i++) {
                if (!reservations.count(i))
                    cout << i << " ";
            }

            cout << endl;
        }

        else if (choice == 6) {
            break;
        }
    }

    return 0;
}
