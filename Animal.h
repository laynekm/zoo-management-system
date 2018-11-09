#pragma once
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Animal {
	public:
		Animal(string, string, int);
		~Animal();
		string getID();			
		string getName();
		string getSpecies();
		string getType();
		string getExhibit();
		int getYearOfBirth();
		void setName(string);
		void setSpecies(string);
		void setExhibit(string);
		void setYearOfBirth(int);
		void toString(string&);
		virtual string sing() = 0;		// Pure virtual function, specified by each subclass
	protected:
		static int numOfAnimals;		// Tracks number of objects created, used to create id
		string type;
		string id;
		string name;
		string species;
		string exhibit;
		int yearOfBirth;
};

// Subclasses of animal, each has the same constructor but specifies a sing() function
class Mammal : public Animal {
	public:
		Mammal(string, string, int);
		string sing();
};

class Reptile : public Animal {
	public:
		Reptile(string, string, int);
		string sing();
};

class Amphibian : public Animal {
	public:
		Amphibian(string, string, int);
		string sing();
};

class Bird : public Animal {
	public:
		Bird(string, string, int);
		string sing();
};

class Fish : public Animal {
	public:
		Fish(string, string, int);
		string sing();
};