#include "Animal.h"

int Animal::numOfAnimals = 0;

//it's probably better to setExhibit() upon it being put into an exhibit
Animal::Animal(string n, string s, int a) {
	stringstream ss;
	ss << setw(4) << setfill('0') << numOfAnimals;
	id = "AN-" + ss.str();

	name = n;
	species = s;
	yearOfBirth = a;

	numOfAnimals++;
}

Animal::~Animal() {

}

//subclass constructors
Mammal::Mammal(string n, string s, int a):Animal(n, s, a) {
	type = "Mammal";
}
Reptile::Reptile(string n, string s, int a) : Animal(n, s, a) {
	type = "Reptile";
}
Amphibian::Amphibian(string n, string s, int a) : Animal(n, s, a) {
	type = "Amphibian";
}
Bird::Bird(string n, string s, int a) : Animal(n, s, a) {
	type = "Bird";
}
Fish::Fish(string n, string s, int a) : Animal(n, s, a) {
	type = "Fish";
}

//overriding pure virtual function "sing" in parent class Animal
string Mammal::sing() {
	stringstream ss;
	if (species == "Human" || species == "human") {
		ss << name << " the " << species << " desperately rattles the cage bars and asks to be let out.";
	}
	else {
		ss << name << " the " << species << " raises his paws and roars!";
	}
	return ss.str();
}
string Reptile::sing() {
	stringstream ss;
	ss << name << " the " << species << " slaps its tail and hisses!";
	return ss.str();
}

string Amphibian::sing() {
	stringstream ss;
	ss << name << " the " << species << " hops in the air and croaks!";
	return ss.str();
}
string Bird::sing() {
	stringstream ss;
	ss << name << " the " << species << " flaps its wings and squaks!";
	return ss.str();
}
string Fish::sing() {
	stringstream ss;
	ss << name << " the " << species << " jumps out of the water and splashes!";
	return ss.str();
}

void Animal::toString(string& returnString) {
	returnString = "";

	stringstream ss;
	ss << left;
	ss << setw(16) << "ID: " << setw(12) << id << endl;
	ss << setw(16) << "Type: " << setw(12) << type << endl;
	ss << setw(16) << "Name: " << setw(12) << name << endl;
	ss << setw(16) << "Species: " << setw(12) << species << endl;
	ss << setw(16) << "Exhibit: " << setw(12) << exhibit << endl;
	ss << setw(16) << "Year of birth: " << setw(12) << yearOfBirth << endl;
	
	returnString = ss.str();
}

//getters
string Animal::getType()		{return type;}
string Animal::getID()			{return id;}
string Animal::getName()		{return name;}
string Animal::getSpecies()		{return species;}
string Animal::getExhibit()		{return exhibit; }
int Animal::getYearOfBirth()	{return yearOfBirth;}

//setters (id and type should not have setters)
void Animal::setName(string n)		{name = n;}
void Animal::setSpecies(string s)	{species = s;}
void Animal::setYearOfBirth(int y)	{yearOfBirth = y;}
void Animal::setExhibit(string e)	{exhibit = e;}