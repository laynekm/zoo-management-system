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
		Zoo();
		~Zoo();
		void addAnimal(Animal*, Exhibit*);		//adds animal to exhibit
		void removeAnimal(Animal*, Exhibit*);	//removes animal from exhibit
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