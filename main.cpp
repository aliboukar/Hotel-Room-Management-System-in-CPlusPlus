#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Room {
private:
    int roomNumber;
    double roomPrice;
    bool isOccupied;


public:
    Room(int num, double price, bool occupied = false)
        : roomNumber(num), roomPrice(price), isOccupied(occupied) {}

    int getRoomNumber() const { return roomNumber; }
    double getRoomPrice() const { return roomPrice; }
    bool getIsOccupied() const { return isOccupied; }


    void setOccupied(bool status) { isOccupied = status; }

    void displayInfo() const {
        cout << "Room " << roomNumber
             << " | Price: $" << roomPrice
             << " | Status: " << (isOccupied ? "Occupied" : "Available") << endl;
    }
};

class Hotel {
private:
    vector<Room> rooms;

public:
     bool isEmpty() const { return rooms.empty(); }
    void addRoom(int num, double price, bool occupied = false) {
        rooms.push_back(Room(num, price, occupied));
    }

    void showAllRooms() const {
        for (const auto &room : rooms)
            room.displayInfo();
    }

    void showAvailableRooms() const {
        bool found = false;
        for (const auto &room : rooms) {
            if (!room.getIsOccupied()) {
                room.displayInfo();
                found = true;
            }
        }
        if (!found) cout << "No rooms available.\n";
    }

    void bookRoom(int num) {
        for (auto &room : rooms) {
            if (room.getRoomNumber() == num) {
                if (room.getIsOccupied()) {
                    cout << "Room is already booked.\n";
                    return;
                }
                string name, confirm;
                int phone;
                cout << "Enter your name: ";
                cin >> name;
                cout << "Enter phone number: ";
                cin >> phone;
                cout << "Type 'confirm' to confirm booking: ";
                cin >> confirm;
                if (confirm == "confirm") {
                room.setOccupied(true);
                    cout << "Booking confirmed for room " << num << "!\n";
                    saveBookings(); // Save after booking

                } else {
                    cout << "Booking cancelled.\n";
                }
                return;
            }
        }
        cout << "Room not found.\n";
    }

    void cancelBooking(int num) {
        for (auto &room : rooms) {
            if (room.getRoomNumber() == num) {
                if (!room.getIsOccupied()) {
                    cout << "Room is already available.\n";
                    return;
                }
                room.setOccupied(false);
                cout << "Booking cancelled for room " << num << ".\n";
                saveBookings();
                return;
            }
        }
        cout << "Room not found.\n";
    }

    void searchByPrice(double price) const {
        bool found = false;
        for (const auto &room : rooms) {
            if (room.getRoomPrice() == price) {
                room.displayInfo();
                found = true;
            }
        }
        if (!found) cout << "No rooms found at this price.\n";
    }


    void showStatistics() const {
        int occupied = 0;
        double totalIncome = 0;
        for (const auto &room : rooms) {
            if (room.getIsOccupied()) {
                occupied++;
                totalIncome += room.getRoomPrice();
            }
        }
        cout << "Total rooms: " << rooms.size() << endl;
        cout << "Occupied rooms: " << occupied << endl;
        cout << "Available rooms: " << rooms.size() - occupied << endl;
        cout << "Total income: $" << totalIncome << endl;
    }


    void saveBookings() const {
        ofstream file("bookings.txt");
        for (const auto &room : rooms) {
            file << room.getRoomNumber() << " "
                 << room.getRoomPrice() << " "
                 << room.getIsOccupied() << "\n";
        }
        file.close();
    }


    void loadBookings() {
        ifstream file("bookings.txt");
        if (!file.is_open()) return;

        rooms.clear();
        int num;
        double price;
        bool occupied;
        while (file >> num >> price >> occupied) {
            addRoom(num, price, occupied);
        }
        file.close();
    }
};

int main() {
    Hotel hotel;
    hotel.loadBookings();


    if (hotel.isEmpty()) {
        hotel.addRoom(101, 150);
        hotel.addRoom(102, 200);
        hotel.addRoom(103, 180);
          hotel.saveBookings();
    }

    int choice;
    while (true) {
        cout << "\n===== HOTEL MENU =====\n";
        cout << "1. Show all rooms\n";
        cout << "2. Show available rooms\n";
        cout << "3. Book a room\n";
        cout << "4. Cancel booking\n";
        cout << "5. Search room by price\n";
        cout << "6. Show statistics\n";
        cout << "7. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        int roomNum;
        double price;

        switch (choice) {
            case 1: hotel.showAllRooms(); break;
            case 2: hotel.showAvailableRooms(); break;
            case 3:
                cout << "Enter room number to book: ";
                cin >> roomNum;
                hotel.bookRoom(roomNum);
                break;
            case 4:
                cout << "Enter room number to cancel booking: ";
                cin >> roomNum;
                hotel.cancelBooking(roomNum);
                break;
            case 5:
                cout << "Enter price to search: ";
                cin >> price;
                hotel.searchByPrice(price);
                break;
            case 6: hotel.showStatistics(); break;
            case 7: cout << "Program ended.\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
