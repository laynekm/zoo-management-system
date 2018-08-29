#pragma once
#include "Animal.h"

class AnimalList {
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