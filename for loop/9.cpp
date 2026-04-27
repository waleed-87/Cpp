//#include<iostream>
//using namespace std;
//int main() {
//    int n;
//    int min, max, score;
//    cout << "Enter number of Scores (max 10): ";
//    cin >> n;
//
//    if (n <= 0 || n > 10) {
//        cout << "Invaild number of scores !" << endl;
//        return 0;
//    }
//    cout << "Enter score 1: ";
//    cin >> score;
//
//    min = score;
//    max = score;
//    for (int i = 2; i <= n;i++) {
//        cout << "Enter Score " << i << ":";
//        cin >> score;
//        if (score > max) {
//            max = score;
//
//        }
//        if (score < min) {
//            min = score;
//        }
//    }
//    cout << "Minimum Score =\t" << min << endl;
//    cout << "Maximum Score =\t" << max << endl;
//
//    return 0;
//}