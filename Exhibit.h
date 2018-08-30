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
		Exhibit(string);								//constructor - creates id based on numOfExhibits, sets initial values, increases numOfExhibits, creates new AnimalList which stores exhibit's animals
		~Exhibit();										//destructor - only need to delete AnimalList (handler is deleted in EmployeeVector destructor, not here)
		string getID();									//getters
		string getName();
		Employee* getHandler();
		AnimalList* getAnimals();
		void setHandler(Employee*);						//setters, setHandler must also set subtype of existing handler to NULL, and set subtype of new handler
		void setName(string);
		void addAnimal(Animal*);						//adds animal to exhibit's AnimalList (see AnimalList for functionality)
		void removeAnimal(Animal*);						//removes animal from exhibit's AnimalList (see AnimalList for functionality)
		void removeAnimalWithoutDeleting(Animal*);		//removes animal from exhibits AnimalList without deletion (see AnimalList for functionality)
		void toString(string&);							//creates string representation of exhibit, returns via reference parameter
	private:
		static int numOfExhibits;						//tracks the number of objects created, used to create id
		string id;
		string name;
		Employee* exhibitHandler;						//pointer to exhibit's handler, can only be one at a time; setting new one removes old one
		AnimalList* animals;							//each exhibit has its own AnimalList, dynamically allocated in constructor
};