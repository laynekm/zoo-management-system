#pragma once
#include "Exhibit.h"
#include <iostream>
#include <string>
#include <fstream>

class ExhibitArray {
public:
	ExhibitArray();
	~ExhibitArray();
	void add(Exhibit*);
	void remove(Exhibit*);
	Exhibit* get(int);
	Exhibit* find(string);
	int getSize();
	void toString(string&);
	void toSongString(string&);
private:
	Exhibit** elementsPointer;
	int size;
	int maxSize;
};