//#include <iostream>
//#include <string> 
//using namespace std;
//
//int main() {
//    int choice;
//    double seconds;
//    double CARBON_SPEED = 258.0;
//    double AIR_SPEED = 331.5;
//    double HELIUM_SPEED = 972.0;
//    double HYDROGEN_SPEED = 1270.0;
//
//    while (true) {
//        cout << "\n--- Speed of Sound Calculator ---" << endl;
//        cout << "1. Carbon Dioxide" << endl;
//        cout << "2. Air" << endl;
//        cout << "3. Helium" << endl;
//        cout << "4. Hydrogen" << endl;
//        cout << "5. Exit" << endl;
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        if (choice == 5) {
//            cout << "Exiting program. Goodbye!" << endl;
//            break;
//        }
//
//        if (choice < 1 || choice > 4) {
//            cout << "Error: Invalid selection. Please choose 1-5." << endl;
//            continue;
//        }
//
//        cout << "Enter the number of seconds (0 to 30): ";
//        cin >> seconds;
//
//        if (seconds < 0 || seconds > 30) {
//            cout << "Error: Time must be between 0 and 30 seconds." << endl;
//        }
//        else {
//            double speed = 0;
//            string medium = "";
//
//            if (choice == 1) {
//                speed = CARBON_SPEED;
//                medium = "Carbon Dioxide";
//            }
//            else if (choice == 2) {
//                speed = AIR_SPEED;
//                medium = "Air";
//            }
//            else if (choice == 3) {
//                speed = HELIUM_SPEED;
//                medium = "Helium";
//            }
//            else if (choice == 4) {
//                speed = HYDROGEN_SPEED;
//                medium = "Hydrogen";
//            }
//
//
//            double distance = speed * seconds;
//            cout << "In " << medium << ", the sound traveled " << distance << " meters." << endl;
//        }
//    }
//    return 0;
//}