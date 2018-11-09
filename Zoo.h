#pragma once
#include "Animal.h"
#include "Exhibit.h"
#include "AnimalList.h"
#include "ExhibitArray.h"
#include "EmployeeVector.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Zoo {
	public:
		void addAnimal(Animal*, Exhibit*);
		void removeAnimal(Animal*, Exhibit*);
		void addExhibit(Exhibit*);
		void removeExhibit(Exhibit*);
		void addEmployee(Employee*);
		void removeEmployee(Employee*);
		ExhibitArray& getExhibits();
		EmployeeVector& getEmployees();
	private:
		ExhibitArray exhibits;
		EmployeeVector employees;
};