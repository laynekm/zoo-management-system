#include "Utilities.h"

//read as string then convert to int
int Utilities::promptForInt() {
	int input;
	while (!(cin >> input)) {
		cout << "Error - please enter a valid number: ";
		cin.clear();
		cin.ignore(132, '\n');
	}
	cout << endl;
	return input;
}

int Utilities::promptForIntRange(int min, int max) {
	int input;
	while (!(cin >> input) || input < min || input > max) {
		cout << "Error - enter a valid integer between " << min << " and " << max << ": ";
		cin.clear();
		cin.ignore(132, '\n');
	}
	cout << endl;
	return input;
}

string Utilities::promptForString() {
	string input;
	getline(cin >> ws, input);
	cout << endl;
	return input;
}

void Utilities::waitForInput() {
	cout << endl;
	system("pause");
	cout << endl;
}