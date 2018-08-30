#pragma once
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Employee {
public:
	Employee(string);			
	~Employee();	
	string getID();					//getters
	string getName();
	string getType();
	string getSubtype();
	void setName(string);			//setters
	void setSubtype(string);
	void toString(string&);			//creates string representation of employee object, returns via reference parameter
protected:
	static int numOfEmployees;		//tracks the number of objects created, used to create id
	string id;
	string name;
	string type;
	string subtype;
};

//subclass constructors, "handler" is special case where subtype is set when added to an exhibit (Exhibit::addAnimal(Animal*))
class Handler : public Employee {
	public:
		Handler(string);
};

class Maintenance : public Employee {
	public:
		Maintenance(string, string);
};

class Admin : public Employee {
	public:
		Admin(string, string);
};