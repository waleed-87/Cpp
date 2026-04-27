//#include <iostream>
//using namespace std;
//
//int main() {
//    int secret = 42;
//    int guess = 0;
//    int tries = 0;
//
//    cout << "Guess the secret number: ";
//
//    while (guess != secret) {
//        cin >> guess;
//        tries = tries + 1; 
//
//        if (guess > secret) {
//            cout << "Too high! Try again: ";
//        }
//        else if (guess < secret) {
//            cout << "Too low! Try again: ";
//        }
//    }
//
//    cout << "You got it! Total guesses: " << tries << endl;
//
//    return 0;
//}