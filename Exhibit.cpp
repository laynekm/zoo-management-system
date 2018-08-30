#include "Exhibit.h"


int Exhibit::numOfExhibits = 0;

Exhibit::Exhibit(string n) {
	stringstream ss;
	ss << setw(4) << setfill('0') << numOfExhibits;
	id = "EX-" + ss.str();

	name = n;
	numOfExhibits++;
}

Exhibit::~Exhibit() {

}

string Exhibit::getID() {
	return id;
}

string Exhibit::getName() {
	return name;
}

AnimalList* Exhibit::getAnimals() {
	return animals;
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

void Exhibit::setHandler(Handler* handler){
	if (exhibitHandler != NULL) {
		exhibitHandler->setSubtype("");
	}
	exhibitHandler = handler;
	handler->setSubtype(name);
}

Handler* Exhibit::getHandler() {
	return exhibitHandler;
}

void Exhibit::setName(string n)		{name = n;}