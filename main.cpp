#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Room {

private:
    int roomNumber;
    bool isOccupied;
    double roomPrice;

public:
    Room(int num, bool occ, double price) {
        roomNumber = num;
        isOccupied = occ;
        roomPrice = price;
    }

    int getRoomNumber() {
        return roomNumber;
    }

    double getroomPrice() {
        return roomPrice;
    }

    void getisOccupied() {
        if (isOccupied == 1) {
            cout << "Sorry but the room is not available" << endl;
        } else {
            cout << "Room available" << endl;
        }
    }

    void displayinfo() {
        cout << "The number of the room is: " << roomNumber << endl;
        cout << "The price of the room is: " << roomPrice << endl;
        getisOccupied();
    }

    void bookRoom() {
        string name;
        int phoneNum;
        int day;
        string month;
        string confirm;
        int Num;

if(isOccupied){
    cout<<"sorry room is already booked"<<endl;
    return;
}

                cout << "**************Booking Section******************" << endl;
                cout << "Enter your name" << endl;
                cin >> name;
                cout << "Phone Number" << endl;
                cin >> phoneNum;
                cout << "DAY of booking" << endl;
                cin >> day;
                cout << "MONTH of booking" << endl;
                cin >> month;
                cout << "write *Confirm* to confirm your booking" << endl;
                cin >> confirm;

                if (confirm == "confirm") {
                    cout << "Booking is confirmed here is the period of your booking: "
                         << day << month << endl;
                } else {
                    cout << "Booking not confirmed" << endl;
                }
            }
};
int main()
{
    vector<Room>rooms;
      rooms.push_back(Room(101, false, 150));
      rooms.push_back(Room(102, true, 200));


     int roomNumber;
      bool isOccupied;
      double roomPrice;
       int choice;
       int Num;

      while(true) {

        cout<<"1. Select a room number: "<<endl;
        cout<<"2. Price of the room number: "<<endl;
        cout<<"3. Is the room available: "<<endl;
        cout<<"4. Get room info: "<<endl;
        cout<<"5. Book a room: "<<endl;
        cin>>choice;



    switch(choice){

    case 1: {
        int EnteredNumber;
        cout<<"Enter room Number you want: "<<endl;
        cin>>EnteredNumber;
        for(auto &room : rooms) {
            if(room.getRoomNumber() == EnteredNumber) {
                room.getisOccupied();

            }
        }

break;
    }

    case 2: {
    double EnteredPrice;
    bool found = false;

    cout<<"What is the room price that is good for you?"<<endl;
    cin>>EnteredPrice;

    for(auto &room : rooms) {
        if(room.getroomPrice() == EnteredPrice) {
           cout<<"Your price match this room: "<<room.getRoomNumber()<<endl;
           found = true;
        }
    }
if(!found){
    cout<<"we don't have any room available with this price try another price !"<<endl;
}
break;
    }
case 3: {
    int EnteredNum;
    bool found = false;
    cout<<"which room you want ?: "<<endl;
    cin>>EnteredNum;
    for(auto &room : rooms) {
        if(room.getRoomNumber() == EnteredNum){
            room.getisOccupied();
            found = true;
        }
    }
    if(!found){
        cout<<"The room selected doesn't exist"<<endl;
    }
break;
}
case 4: {

           for(auto &room : rooms){
            room.displayinfo();
           }

break;
}
case 5: {  cout << "Select the room you want to book: " << endl;
        cin >> Num;
        for(auto &room : rooms){
            if(room.getRoomNumber() == Num) {
                room.bookRoom();
            }
        }

}

    }

    }

    ;



    return 0;
}
