#include "Exhibit.h"


int Exhibit::numOfExhibits = 0;

//constructor - creates id based on numOfExhibits, sets initial values, increases numOfExhibits, creates new AnimalList which stores exhibit's animals
Exhibit::Exhibit(string n) {
	stringstream ss;
	ss << setw(4) << setfill('0') << numOfExhibits;
	id = "EX-" + ss.str();

	name = n;
	numOfExhibits++;

	animals = new AnimalList();
}

//destructor - only need to delete AnimalList (handler is deleted in EmployeeVector destructor, not here)
Exhibit::~Exhibit() {
	delete animals;
}

//getters
string Exhibit::getID()				{ return id;}
string Exhibit::getName()			{return name;}
AnimalList* Exhibit::getAnimals()	{return animals;}
Employee* Exhibit::getHandler()		{ return exhibitHandler;}

//setters, setHandler must also set subtype of existing handler to NULL, and set subtype of new handler
void Exhibit::setName(string n) { name = n; }
void Exhibit::setHandler(Employee* handler) {
	if (handler == NULL) {
		exhibitHandler = NULL;
		return;
	}

	if (exhibitHandler != NULL) {
		exhibitHandler->setSubtype("");
	}
	exhibitHandler = handler;
	handler->setSubtype(name);
}


void Exhibit::addAnimal(Animal* animal) {
	animals->add(animal);
	animal->setExhibit(name);
}

void Exhibit::removeAnimal(Animal* animal) {
	animals->remove(animal);
}

void Exhibit::removeAnimalWithoutDeleting(Animal* animal) {
	animals->removeWithoutDeleting(animal);
}

//creates string representation of exhibit, returns via reference parameter
void Exhibit::toString(string& returnString) {
	returnString = "";

	stringstream ss;
	ss << left;
	ss << setw(16) << "ID: " << setw(12) << id << endl;
	ss << setw(16) << "Name: " << setw(12) << name << endl;
	ss << setw(16) << "Handler: " << setw(12) << exhibitHandler->getName() << endl;

	returnString = ss.str();
}