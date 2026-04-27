//#include <iostream>
//using namespace std;
//int main() {
//
//    int number = 0, sum = 0, count = 0;
//    cout << "Enter positive integers less than 1000 (Type 1000 to stop):" << endl;
//    while (true) {
//        cout << "Enter a Number" << endl;
//        cin >> number;
//        if (number == 1000) {
//            cout << "Exiting program. Goodbye!" << endl;
//            break;
//        }
//        if (number >= 0 && number < 1000) {
//
//            sum += number;
//            count++;
//        }
//        else {
//            cout << "Invalid input. Please enter a number between 0 and 999." << endl;
//
//        }
//        if (count > 0) {
//            cout << "--Result--" << endl;
//            cout << "Sum =" << sum << endl;
//            cout << "Average =" << sum / count << endl;
//        }
//
//    }
//
//
//    return 0;
//}