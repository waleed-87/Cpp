#include<iostream>
#include<fstream>
using namespace std;

int main() {
    int sum = 0, count = 0;
    int number; 
    ifstream readfile;

    readfile.open("cd.txt");

    if (readfile.is_open()) {
       
        while (readfile >> number) {
            count++;
            sum += number;
            cout << number << endl;
        }
        readfile.close();

        if (count > 0) {
            cout << "Total Numbers =\t" << count << endl;
            cout << "Sum =\t" << sum << endl;
            cout << "Average =\t" << (double)sum / count << endl;
        }
        else {
            cout << "The file was empty." << endl;
        }
    }
    else {
        cout << "Error: File not found!" << endl;
    }

    return 0;
}