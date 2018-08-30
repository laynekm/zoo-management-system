#include <iostream>
#include "AnimalList.h"
using namespace std;

//constructor - initializes head and tail to null
AnimalList::AnimalList() {
	head = NULL;
	tail = NULL;
	size = 0;
}

//destructor - deletes all nodes and their data to prevent memory leaks
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

//finds animal object based on its id attribute and returns reference to this object
Animal* AnimalList::find(string id) {
	Node* currNode = head;
	while (currNode != NULL){
		if (currNode->data->getID() == id) {break;}
		currNode = currNode->next;
	}

	if (currNode == NULL) { return NULL;}
	else { return currNode->data; }
}

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

void AnimalList::add(Animal* animal) {
	Node* newNode = new Node;
	newNode->data = animal;
	newNode->next = NULL;
	newNode->prev = NULL;

	//case where the list is empty
	if (head == NULL) {
		head = newNode;
		tail = newNode;
	}

	//if not empty, just add to end of list
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}

	size++;
}

void AnimalList::remove(Animal* animal) {
	Node* currNode = head;
	Node* prevNode = NULL;

	//iterate through until the currNode is the node to be removed
	while (currNode != NULL) {
		if (currNode->data == animal) {break;}
		prevNode = currNode;
		currNode = currNode->next;
	}

	//case where removing the only node in list
	if (currNode == head && head->next == NULL) {
		head = NULL;
		delete currNode->data;
		delete currNode;
		size--;
		return;
	}

	//case where removing from beginning of list
	else if (currNode == head) {
		head = head->next;
		head->prev = NULL;
		delete currNode->data;
		delete currNode;
		size--;
	}

	//case where removing from end of list
	else if (currNode == tail) {
		tail = tail->prev;
		tail->next = NULL;
		delete currNode->data;
		delete currNode;
		size--;
	}

	//case where removing removing from inside list
	else {
		currNode->prev->next = currNode->next;
		currNode->next->prev = currNode->prev;
		delete currNode->data;
		delete currNode;
		size--;
	}

}

void AnimalList::removeWithoutDeleting(Animal* animal) {
	Node* currNode = head;
	Node* prevNode = NULL;

	//iterate through until the currNode is the node to be removed
	while (currNode != NULL) {
		if (currNode->data == animal) { break; }
		prevNode = currNode;
		currNode = currNode->next;
	}

	//case where removing the only node in list
	if (currNode == head && head->next == NULL) {
		head = NULL;
		delete currNode;
		size--;
		return;
	}

	//case where removing from beginning of list
	else if (currNode == head) {
		head = head->next;
		head->prev = NULL;
		delete currNode;
		size--;
	}

	//case where removing from end of list
	else if (currNode == tail) {
		tail = tail->prev;
		tail->next = NULL;
		delete currNode;
		size--;
	}

	//case where removing removing from inside list
	else {
		currNode->prev->next = currNode->next;
		currNode->next->prev = currNode->prev;
		delete currNode;
		size--;
	}
}

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