#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "AnimalList.h"
#include "Employee.h"
using namespace std;

class Exhibit {
	public:
		Exhibit(string);
		~Exhibit();
		string getID();
		string getName();
		Employee* getHandler();
		AnimalList* getAnimals();
		void addAnimal(Animal*);
		void removeAnimal(Animal*);
		void removeAnimalWithoutDeleting(Animal*);
		void setHandler(Employee*);
		void setName(string);
		void toString(string&);
	private:
		static int numOfExhibits;
		string id;
		string name;
		Employee* exhibitHandler;
		AnimalList* animals = new AnimalList();
};