#include "EmployeeVector.h"

EmployeeVector::EmployeeVector() {
	elements = new vector<Employee*>;
}

EmployeeVector::~EmployeeVector() {

}

void EmployeeVector::add(Employee* employee) {
	elements->push_back(employee);
}

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

Employee* EmployeeVector::get(int pos) {
	return elements->at(pos);
}

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

void EmployeeVector::toString(string& returnString) {
	returnString = "";

	if (elements->size() == NULL) {
		returnString = "There are no employees! Where'd everyone go?";
		return;
	}

	stringstream ss;
	ss  << "-----| EMPLOYEES |---------------------------------------------------------" << endl
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

	ss << "---------------------------------------------------------------------------" << endl;
	returnString = ss.str();
}