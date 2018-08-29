#pragma once
#include "Employee.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class EmployeeVector {
public:
	EmployeeVector();
	~EmployeeVector();
	void add(Employee*);
	void remove(Employee*);
	Employee* get(int);
	Employee* find(string);
	int getSize();
	void toString(string&);
private:
	vector<Employee*>* elements;
};