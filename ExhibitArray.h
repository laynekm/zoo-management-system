#pragma once
#include "Exhibit.h"
#include <iostream>
#include <string>
#include <fstream>

class ExhibitArray {
public:
	ExhibitArray();					//constructor - sets size/maxsize, creates new array of exhibit pointers of size maxsize
	~ExhibitArray();				//destructor - deletes all elements, then deletes elements array
	void add(Exhibit*);				//adds element pointer to end of array; if max size reached, copy elements to new array of size maxsize*2
	void remove(Exhibit*);			//removes/deletes element and fills in gap to prevent NULL element; if size <= maxsize/3, elements copied to new array of size maxsize/2
	Exhibit* get(int);				//returns element pointer at given pos
	Exhibit* find(string);			//returns element pointer with given id
	int getSize();					//returns array size (# of elements, not maxsize)
	void toString(string&);			//creates string representation of all exhibits and its animals, returns via reference parameter
	void toSongString(string&);		//creates string representation of all animals' song functions, returns via reference parameter
private:
	Exhibit** elements;
	int size;						//# of elements
	int maxSize;					//max size of current array instance (not constant)
};