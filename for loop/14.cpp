//#include <iostream>
//using namespace std;
//int main() {
//    int floors = 0, rooms = 0;
//    int total_rooms = 0, total_occupied_rooms = 0;
//    float unoccupied = 0, occupied = 0;
//    float unoccupied_percentage = 0, occupied_percentage = 0;
//    cout << "Enter number of Floors =";
//    cin >> floors;
//
//    if (floors >= 1) {
//        for (int i = 1;i <= floors;i++) {
//            cout << "Enter number of rooms in " << i << "Floor (minimum 10 rooms)=";
//            cin >> rooms;
//            while (rooms < 10) {
//                cout << "Invalid. Minimum 10 rooms. Re-enter: ";
//                cin >> rooms;
//            }
//
//            total_rooms += rooms;
//            cout << "Enter number of occupied rooms in " << i << "Floor =";
//            cin >> occupied;
//            total_occupied_rooms += occupied;
//
//        }
//    }
//    unoccupied = total_rooms - occupied;
//    occupied_percentage = (occupied / total_rooms) * 100;
//    unoccupied_percentage = (unoccupied / total_rooms) * 100;
//
//    cout << "--Total---" << endl;
//    cout << "Total Floors =\t" << floors << endl;
//    cout << "Total Rooms =\t" << total_rooms << endl;
//    cout << "Occupied Rooms =\t" << occupied_percentage << '%' << endl;
//    cout << "Unccupied Rooms =\t" << unoccupied_percentage << '%' << endl;
//    return 0;
//}