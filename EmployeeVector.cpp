#include "EmployeeVector.h"

// Constructor - creates new element vector, assigns to "elements" pointer
EmployeeVector::EmployeeVector() {
	elements = new vector<Employee*>;
}

// Destructor - deletes all elements, then deletes vector
EmployeeVector::~EmployeeVector() {
	for (int i = 0; i < elements->size(); i++) {
		delete elements->at(i);
	}
	delete elements;
}

// Pushes employee to end of vector
void EmployeeVector::add(Employee* employee) {
	elements->push_back(employee);
}

// Removes and deletes employee, then fills gap to prevent NULL element
void EmployeeVector::remove(Employee* employee) {
	int deletedPos;
	for (int i = 0; i < elements->size(); i++) {
		if (elements->at(i) == employee) {
			delete elements->at(i);
			deletedPos = i;
		}
	}

	for (int i = deletedPos; i < elements->size() - 1; i++) {
		elements->at(i) = elements->at(i + 1);
	}

	elements->pop_back();
}

// Returns employee pointer at given pos
Employee* EmployeeVector::get(int pos) {
	return elements->at(pos);
}

// Returns employee pointer with given id
Employee* EmployeeVector::find(string id) {
	for (int i = 0; i < elements->size(); i++) {
		if (elements->at(i)->getID() == id) {
			return elements->at(i);
		}
	}

	return NULL;
}

int EmployeeVector::getSize() {
	return elements->size();
}

// Creates string representation of vector, returns via reference parameter
void EmployeeVector::toString(string& returnString) {
	returnString = "";

	if (elements->size() == NULL) {
		returnString = "There are no employees! Where'd everyone go?";
		return;
	}

	stringstream ss;
	ss  << "-----| EMPLOYEES |------------------------------------------" << endl
		<< setw(12) << "Total number: " << elements->size() << endl
		<< setw(12) << "ID"
		<< setw(22) << "NAME"
		<< setw(14) << "TYPE"
		<< setw(12) << "SUBTYPE" << endl;


	for (int i = 0; i < elements->size(); i++) {
		ss  << setw(12) << elements->at(i)->getID()
			<< setw(22) << elements->at(i)->getName()
			<< setw(14) << elements->at(i)->getType()
			<< setw(12) << elements->at(i)->getSubtype() << endl;
	}

	ss << "------------------------------------------------------------" << endl;
	returnString = ss.str();
}