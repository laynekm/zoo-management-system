#include <iostream>
#include "AnimalList.h"
using namespace std;

// Constructor - initializes head and tail to null, size to 0
AnimalList::AnimalList() {
	head = NULL;
	tail = NULL;
	size = 0;
}

// Destructor - deletes all nodes and their data
AnimalList::~AnimalList() {
	Node* currNode = head;
	Node* nextNode = NULL;
	while (currNode != NULL) {
		nextNode = currNode->next;
		delete currNode->data;
		delete currNode;
		currNode = nextNode;
	}
}

// Returns animal pointer based on given id
Animal* AnimalList::find(string id) {
	Node* currNode = head;
	while (currNode != NULL){
		if (currNode->data->getID() == id) {break;}
		currNode = currNode->next;
	}

	if (currNode == NULL) { return NULL;}
	else { return currNode->data; }
}

// Returns animal pointer at given position in list
Animal* AnimalList::get(int pos) {
	Node* currNode = head;
	int currPos = 0;
	while (currNode != NULL) {
		if (currPos == pos) {break;}
		currNode = currNode->next;
		currPos++;
	}

	if (currNode == NULL) { return NULL; }
	else { return currNode->data; }
}

// Adds node to linked list, data is given animal pointer
void AnimalList::add(Animal* animal) {
	Node* newNode = new Node;
	newNode->data = animal;
	newNode->next = NULL;
	newNode->prev = NULL;

	// Case where the list is empty
	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}

	// If not empty, just add to end of list
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

	size++;
}

// Removes node from linked list, deletes node and data
void AnimalList::remove(Animal* animal) {
	Node* currNode = head;
	Node* prevNode = NULL;

	// Iterate through until the currNode is the node to be removed
	while (currNode != NULL) {
		if (currNode->data == animal) {break;}
		prevNode = currNode;
		currNode = currNode->next;
	}

	// Case where removing the only node in list
	if (currNode == head && head->next == NULL) {
		head = NULL;
		delete currNode->data;
		delete currNode;
		size--;
		return;
	}

	// Case where removing from beginning of list
	else if (currNode == head) {
		head = head->next;
		head->prev = NULL;
		delete currNode->data;
		delete currNode;
		size--;
	}

	// Case where removing from end of list
	else if (currNode == tail) {
		tail = tail->prev;
		tail->next = NULL;
		delete currNode->data;
		delete currNode;
		size--;
	}

	// Case where removing removing from inside list
	else {
		currNode->prev->next = currNode->next;
		currNode->next->prev = currNode->prev;
		delete currNode->data;
		delete currNode;
		size--;
	}

}

// Removes node from linked list, deletes node but does not delete data
void AnimalList::removeWithoutDeleting(Animal* animal) {
	Node* currNode = head;
	Node* prevNode = NULL;

	// Iterate through until the currNode is the node to be removed
	while (currNode != NULL) {
		if (currNode->data == animal) { break; }
		prevNode = currNode;
		currNode = currNode->next;
	}

	// Case where removing the only node in list
	if (currNode == head && head->next == NULL) {
		head = NULL;
		delete currNode;
		size--;
		return;
	}

	// Case where removing from beginning of list
	else if (currNode == head) {
		head = head->next;
		head->prev = NULL;
		delete currNode;
		size--;
	}

	// Case where removing from end of list
	else if (currNode == tail) {
		tail = tail->prev;
		tail->next = NULL;
		delete currNode;
		size--;
	}

	// Case where removing removing from inside list
	else {
		currNode->prev->next = currNode->next;
		currNode->next->prev = currNode->prev;
		delete currNode;
		size--;
	}
}

// Creates string representation of all animal objects in list, returns via reference parameter
void AnimalList::toString(string& returnString) {
	returnString = "";

	Node* currNode = head;
	if (currNode == NULL) {
		return;
	}

	stringstream ss;
	while (currNode != NULL) {
		ss  << setw(12) << currNode->data->getType()
			<< setw(12) << currNode->data->getID()
			<< setw(12) << currNode->data->getName()
			<< setw(12) << currNode->data->getSpecies()
			<< setw(12) << currNode->data->getExhibit();

		int yearOfBirth = currNode->data->getYearOfBirth();
		ss << setw(15) << to_string(yearOfBirth) << endl;

		currNode = currNode->next;
	}

	returnString = ss.str();
}

// Creates string representation of all animals' sing function, returns via reference parameter
void AnimalList::toSongString(string& returnString) {
	returnString = "";
	stringstream ss;

	Node* currNode = head;
	if (currNode == NULL) {
		return;
	}

	while (currNode != NULL) {
		ss << currNode->data->sing() << endl;
		currNode = currNode->next;
	}

	returnString = ss.str();
}

int AnimalList::getSize() {
	return size;
}