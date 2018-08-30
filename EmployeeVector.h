#pragma once
#include "Employee.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class EmployeeVector {
public:
	EmployeeVector();				//constructor, creates new element vector, assigns to "elements" pointer
	~EmployeeVector();				//destructor, deletes all elements, then deletes vector
	void add(Employee*);			//pushes employee to end of vector
	void remove(Employee*);			//removes and deletes employee, then fills gap to prevent NULL element
	Employee* get(int);				//returns employee pointer at given pos
	Employee* find(string);			//returns employee pointer with given id
	int getSize();					//returns size of vector
	void toString(string&);			//creates string representation of vector, returns via reference parameter
private:
	vector<Employee*>* elements;
};