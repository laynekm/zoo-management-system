#include "ExhibitArray.h"

ExhibitArray::ExhibitArray() {
	size = 0;
	maxSize = 1;
	Exhibit** elements = new Exhibit*[maxSize];
	elementsPointer = elements;
}

ExhibitArray::~ExhibitArray() {
	for (int i = 0; i < size; i++) {
		delete elementsPointer[i];
	}
	delete[] elementsPointer;
}

//add element pointer to array
//if size reaches max size, copy elements to a new array of size maxsize*2
void ExhibitArray::add(Exhibit* exhibit) {
	elementsPointer[size] = exhibit;
	size++;

	if (size >= maxSize) {
		maxSize *= 2;
		Exhibit** newElements = new Exhibit*[maxSize];
		for (int i = 0; i < size; i++) {
			newElements[i] = elementsPointer[i];
		}
		delete[] elementsPointer;
		elementsPointer = newElements;
	}
}

//remove element pointer from array, delete element
//move all elements >pos down one so there's no gaps
//if size <= mazsize/3, copy elements to new array of size maxsize/2
void ExhibitArray::remove(Exhibit* exhibit) {
	int deletedPos;
	for (int i = 0; i < size; i++) {
		if (elementsPointer[i] == exhibit) {
			delete elementsPointer[i];
			deletedPos = i;
		}
	}

	for (int i = deletedPos; i < size - 1; i++) {
		elementsPointer[i] = elementsPointer[i + 1];
	}

	elementsPointer[size] = NULL;
	size--;

	if (size <= maxSize / 3) {
		maxSize = maxSize / 2;
		Exhibit** newElements = new Exhibit*[maxSize];
		for (int i = 0; i < size; i++) {
			newElements[i] = elementsPointer[i];
		}
		delete[] elementsPointer;
		elementsPointer = newElements;
	}
}

Exhibit* ExhibitArray::get(int pos) {
	return elementsPointer[pos];
}

Exhibit* ExhibitArray::find(string id) {
	for (int i = 0; i < size; i++) {
		if (elementsPointer[i]->getID() == id) {
			return elementsPointer[i];
		}
	}
	
	return NULL;
}

int ExhibitArray::getSize() {
	return size;
}

void ExhibitArray::toString(string& returnString) {
	returnString = "";

	if (size == 0) {
		returnString += "There are no exhibits in the zoo.\n";
		return;
	}

	stringstream ss;
	string animalString;

	ss << "Total number of exhibits: " << size << endl << endl;

	for (int i = 0; i < size; i++) {
		ss << "ID: " << elementsPointer[i]->getID() << endl;
		ss << "Name: " << elementsPointer[i]->getName() << endl;
		if (elementsPointer[i]->getHandler() != NULL) {
			ss << "Handler: " << elementsPointer[i]->getHandler()->getName() << endl;
		}
		else {
			ss << "Handler: None" << endl;
		}
		ss << "Total animals: " << elementsPointer[i]->getAnimals()->getSize() << endl;
		elementsPointer[i]->getAnimals()->toString(animalString);
		if (animalString == "") {
			ss << "There are no animals in this exhibit." << endl;
		}
		else {
			ss << setw(12) << "TYPE"
				<< setw(12) << "ID"
				<< setw(12) << "NAME"
				<< setw(12) << "SPECIES"
				<< setw(12) << "EXHIBIT"
				<< setw(15) << "BIRTH YEAR" << endl
			    << animalString << endl;
		}
	}

	returnString = ss.str();
}

void ExhibitArray::toSongString(string& returnString) {
	returnString = "";

	if (size == 0) {
		returnString += "There is no song to sing (no animals in the zoo!)\n";
		return;
	}

	stringstream ss;
	string animalString;

	ss << endl;
	for (int i = 0; i < size; i++) {
		ss << "In the " << elementsPointer[i]->getName() << " exhibit..." << endl;
		if (elementsPointer[i]->getAnimals()->getSize() > 0) {
			elementsPointer[i]->getAnimals()->toSongString(animalString);
			ss << animalString << endl;
		}
		else {
			ss << "Absolute silence." << endl;
		}
	}

	ss << endl << " - brought to you by polymorphism." << endl;
	returnString = ss.str();
}