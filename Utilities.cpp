#include "Utilities.h"

//prompts for int, verifies it is int
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

//prompts for int, verifies it is int and within specified range
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

//prompts for string
string Utilities::promptForString() {
	string input;
	getline(cin >> ws, input);
	cout << endl;
	return input;
}

//pauses until user provides input
void Utilities::waitForInput() {
	cout << endl;
	system("pause");
	cout << endl;
}