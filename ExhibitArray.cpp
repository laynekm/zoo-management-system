#include "ExhibitArray.h"

//constructor - sets size/maxsize, creates new array of exhibit pointers of size maxsize
ExhibitArray::ExhibitArray() {
	size = 0;
	maxSize = 1;
	elements = new Exhibit*[maxSize];
}

//destructor - deletes all elements, then deletes elements array
ExhibitArray::~ExhibitArray() {
	for (int i = 0; i < size; i++) {
		delete elements[i];
	}
	delete[] elements;
}

//adds element pointer to end of array; if max size reached, copy elements to new array of size maxsize*2
void ExhibitArray::add(Exhibit* exhibit) {
	elements[size] = exhibit;
	size++;

	if (size >= maxSize) {
		maxSize *= 2;
		Exhibit** newElements = new Exhibit*[maxSize];
		for (int i = 0; i < size; i++) {
			newElements[i] = elements[i];
		}
		delete[] elements;
		elements = newElements;
	}
}

//removes/deletes element and fills in gap to prevent NULL element; if size <= maxsize/3, elements copied to new array of size maxsize/2
void ExhibitArray::remove(Exhibit* exhibit) {
	int deletedPos;
	for (int i = 0; i < size; i++) {
		if (elements[i] == exhibit) {
			delete elements[i];
			deletedPos = i;
		}
	}

	for (int i = deletedPos; i < size - 1; i++) {
		elements[i] = elements[i + 1];
	}

	elements[size] = NULL;
	size--;

	if (size <= maxSize / 3) {
		maxSize = maxSize / 2;
		Exhibit** newElements = new Exhibit*[maxSize];
		for (int i = 0; i < size; i++) {
			newElements[i] = elements[i];
		}
		delete[] elements;
		elements = newElements;
	}
}

//returns element pointer at given pos
Exhibit* ExhibitArray::get(int pos) {
	return elements[pos];
}

//returns element pointer with given id
Exhibit* ExhibitArray::find(string id) {
	for (int i = 0; i < size; i++) {
		if (elements[i]->getID() == id) {
			return elements[i];
		}
	}
	
	return NULL;
}

//returns array size (# of elements, not maxsize)
int ExhibitArray::getSize() {
	return size;
}

//creates string representation of all exhibits and its animals, returns via reference parameter
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
		ss << "ID: " << elements[i]->getID() << endl;
		ss << "Name: " << elements[i]->getName() << endl;

		if (elements[i]->getHandler() != NULL) { 
			ss << "Handler: " << elements[i]->getHandler()->getName() << endl;
		}
		else {
			ss << "Handler: None" << endl;
		}

		ss << "Total animals: " << elements[i]->getAnimals()->getSize() << endl;
		elements[i]->getAnimals()->toString(animalString);
		if (animalString == "") {
			ss << "There are no animals in this exhibit." << endl << endl;;
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

//creates string representation of all animals' song functions, returns via reference parameter
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
		ss << "In the " << elements[i]->getName() << " exhibit..." << endl;
		if (elements[i]->getAnimals()->getSize() > 0) {
			elements[i]->getAnimals()->toSongString(animalString);
			ss << animalString << endl;
		}
		else {
			ss << "Absolute silence." << endl;
		}
	}

	ss << endl << " - brought to you by polymorphism." << endl;
	returnString = ss.str();
}