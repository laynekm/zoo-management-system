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
		int promptForInt();					//prompts for int, verifies it is int
		int promptForIntRange(int, int);	//prompts for int, verifies it is int and within specified range
		string promptForString();			//prompts for string
		void waitForInput();				//pauses until user provides input
};