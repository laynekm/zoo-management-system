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
		Handler* getHandler();
		AnimalList* getAnimals();
		void addAnimal(Animal*);
		void removeAnimal(Animal*);
		void setHandler(Handler*);
		void setName(string);
		void toString(string&);
	private:
		static int numOfExhibits;
		string id;
		string name;
		Handler* exhibitHandler;
		AnimalList* animals = new AnimalList();
};