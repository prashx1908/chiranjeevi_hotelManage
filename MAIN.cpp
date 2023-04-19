#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Room {
    private:
        int roomNumber;
        bool isOccupied;
        double rate;

    public:
        Room(int roomNum, bool occupied, double roomRate) {
            roomNumber = roomNum;
            isOccupied = occupied;
            rate = roomRate;
        }

        int getRoomNumber() {
            return roomNumber;
        }

        bool getIsOccupied() {
            return isOccupied;
        }

        void setIsOccupied(bool occupied) {
            isOccupied = occupied;
        }

        double getRate() {
            return rate;
        }

        void setRate(double roomRate) {
            rate = roomRate;
        }
};

class Reservation {
    private:
        string guestName;
        int roomNumber;
        int numberOfNights;

    public:
        Reservation(string name, int roomNum, int nights) {
            guestName = name;
            roomNumber = roomNum;
            numberOfNights = nights;
        }

        string getGuestName() {
            return guestName;
        }

        int getRoomNumber() {
            return roomNumber;
        }

        int getNumberOfNights() {
            return numberOfNights;
        }
};

class Hotel {
    private:
        vector<Room> rooms;
        vector<Reservation> reservations;

    public:
        Hotel() {
            for (int i = 1; i <= 10; i++) {
                Room newRoom(i, false, 100.00);
                rooms.push_back(newRoom);
            }
        }

        void displayRooms() {
            for (Room room : rooms) {
                cout << "Room " << room.getRoomNumber() << " - ";
                if (room.getIsOccupied()) {
                    cout << "Occupied" << endl;
                } else {
                    cout << "Available" << endl;
                }
            }
        }

        void makeReservation() {
            string guestName;
            int roomNumber;
            int numberOfNights;

            cout << "Enter guest name: ";
            cin >> guestName;

            cout << "Enter room number: ";
            cin >> roomNumber;

            cout << "Enter number of nights: ";
            cin >> numberOfNights;

            // Check if room is available
            auto room = find_if(rooms.begin(), rooms.end(), [&](Room r){ return r.getRoomNumber() == roomNumber && !r.getIsOccupied(); });
            if (room != rooms.end()) {
                // Room is available
                room->setIsOccupied(true);

                Reservation newReservation(guestName, roomNumber, numberOfNights);
                reservations.push_back(newReservation);

                cout << "Reservation made successfully." << endl;
            } else {
                // Room is not available
                cout << "Room is not available." << endl;
            }
        }

        void displayReservations() {
            for (Reservation reservation : reservations) {
                cout << "Guest Name: " << reservation.getGuestName() << endl;
                cout << "Room Number: " << reservation.getRoomNumber() << endl;
                cout << "Number of Nights: " << reservation.getNumberOfNights() << endl;
                cout << endl;
            }
        }

        void checkOut() {
            int roomNumber;

            cout << "Enter room number: ";
            cin >> roomNumber;

            auto reservation = find_if(reservations.begin(), reservations.end(), [&](Reservation r){ return r.getRoomNumber() == roomNumber; });
            if (reservation != reservations.end()) {
                // Room is occupied and reservation exists
                            auto room = find_if(rooms.begin(), rooms.end(), [&](Room r){ return r.getRoomNumber() == roomNumber; });
            if (room != rooms.end()) {
                // Update room status to unoccupied
                room->setIsOccupied(false);

                // Remove reservation from list
                reservations.erase(reservation);

                cout << "Checkout successful." << endl;
            }
        } else {
            // Room is not occupied or reservation does not exist
            cout << "No reservation found for room " << roomNumber << endl;
        }
    }
};

int main() {
Hotel hotel;
while (true) {
    int choice;
    cout << "1. Display Rooms" << endl;
    cout << "2. Make Reservation" << endl;
    cout << "3. Display Reservations" << endl;
    cout << "4. Check Out" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            hotel.displayRooms();
            break;
        case 2:
            hotel.makeReservation();
            break;
        case 3:
            hotel.displayReservations();
            break;
        case 4:
            hotel.checkOut();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
    }
}

return 0;}
