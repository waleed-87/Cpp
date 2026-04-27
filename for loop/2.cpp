#include<iostream>
using namespace std;
int main(){

	int day, month, year,weekday;
	cout << "Enter day"<<endl;
	cin >> day;
	cout << "Enter Month"<<endl;
	cin >> month;
	cout << "Enter Year"<<endl;
	cin >> year;

	if (month == 1 || month == 2) {
		month += 12;
		year = year - 1;
	}
	weekday = (day + 26 * (month + 1) / 10 +
		year + year / 4 - year / 100 + year / 400) % 7;
	cout << "The day of the week is: ";
	switch (weekday) {
	case 0: cout << "Saturday"; break;
	case 1: cout << "Sunday"; break;
	case 2: cout << "Monday"; break;
	case 3: cout << "Tuesday"; break;
	case 4: cout << "Wednesday"; break;
	case 5: cout << "Thursday"; break;
	case 6: cout << "Friday"; break;
	}
	cout << endl;



	return 0;
}