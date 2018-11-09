#pragma once
#include "Animal.h"

class AnimalList {

	// Node is friend class of AnimalList so AnimalList has access to all its attributes
	class Node {
		friend class AnimalList;
		private:
		Animal* data;
		Node* next;
		Node* prev;
	};

	public:
		AnimalList();				
		~AnimalList();
		void add(Animal*);	
		void remove(Animal*);
		void removeWithoutDeleting(Animal*);
		Animal* get(int);
		Animal* find(string);
		int getSize();
		void toString(string&);
		void toSongString(string&);
	private:
		Node* head;
		Node* tail;
		int size;
};