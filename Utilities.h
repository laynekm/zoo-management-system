#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Utilities {
	public:
		int promptForInt();
		int promptForIntRange(int, int);
		string promptForString();
		void waitForInput();
};