#pragma once
#include "Animal.h"

class AnimalList {

	//node is friend class of AnimalList so AnimalList has access to all its attributes
	class Node {
		friend class AnimalList;
		private:
		Animal* data;
		Node* next;
		Node* prev;
	};

	public:
		AnimalList();							//constructor - initializes head and tail to null, size to 0
		~AnimalList();							//destructor - deletes all nodes and their data
		void add(Animal*);						//adds node to linked list, data is given animal pointer
		void remove(Animal*);					//removes node from linked list, deletes node and data
		void removeWithoutDeleting(Animal*);	//removes node from linked list, deletes node but does not delete data
		Animal* get(int);						//returns animal pointer at given position
		Animal* find(string);					//returns animal pointer based on given id
		int getSize();							//returns size
		void toString(string&);					//creates string representation of all animal objects in list, returns via reference parameter
		void toSongString(string&);				//creates string representation of all animals' sing function, returns via reference parameter
	private:
		Node* head;								//pointer to first node in list
		Node* tail;								//pointer to last node in list
		int size;
};