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
		void addAnimal(Animal*, Exhibit*);		//adds animal to exhibit's AnimalList
		void removeAnimal(Animal*, Exhibit*);	//removes animal from exhibit's AnimalList
		void addExhibit(Exhibit*);				//adds exhibit to ExhibitArray
		void removeExhibit(Exhibit*);			//removes exhibit from ExhibitArray
		void addEmployee(Employee*);			//adds employee to EmployeeVector
		void removeEmployee(Employee*);			//removes employee from EmployeeVector
		ExhibitArray& getExhibits();			//returns reference to ExhibitArray (which in turn can return AnimalList)
		EmployeeVector& getEmployees();			//returns reference to EmployeeVector
	private:
		ExhibitArray exhibits;
		EmployeeVector employees;
};