//#include <iostream>
//#include <cctype>
//using namespace std;
//int main() {
//    int vowels = 0, consonants = 0, capital = 0, small = 0, total = 0, total_A = 0;
//    char character;
//
//    while (true) {
//        cout << "Enter Character =";
//        cin >> character;
//        cout << "For Exit type x" << endl;
//
//
//        if (character == 'x') {
//            break;
//        }
//        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {
//
//            if (character == 'a' || character == 'A' || character == 'e' || character == 'E' ||
//                character == 'i' || character == 'I' ||
//                character == 'o' || character == 'O' || character == 'u' || character == 'U')
//            {
//
//                vowels += 1;
//
//            }
//            else {
//                consonants += 1;
//
//            }
//        }
//        if (isupper(character)) {
//            capital += 1;
//
//        }
//        if (islower(character)) {
//            small += 1;
//
//        }
//
//        if (character == 'A') {
//
//            total_A += 1;
//
//        }
//        total += 1;
//
//
//    }
//    cout << "Vowels =\t" << vowels << endl;
//    cout << "Consonants =\t" << consonants << endl;
//    cout << "Capitals =\t" << capital << endl;
//    cout << "Small =\t" << small << endl;
//    cout << "Count of 'A' =\t" << total_A << endl;
//    cout << "Total =\t" << total << endl;
//    return 0;
//}