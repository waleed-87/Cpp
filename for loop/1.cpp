#include <iostream>
using namespace std;
int main() {

	char input;

	cout << "Enter the desired grade of pet food (e.g., A or a)" << endl;
	cin >> input;
	switch (input) {
	case 'a':
	case 'A':
		cout << "A 30 cents per pound ";
		break;
	case 'b':
	case 'B':
		cout << "B 20 cents per pound ";
		break;
	case 'c':
	case 'C':
		cout << "A 10 cents per pound ";
		break;
	default:
		cout << "That is an invalid choice";
		

	}




	return 0;
}