#pragma once
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Employee {
public:
	Employee(string);
	~Employee();
	string getID();
	string getName();
	string getType();
	string getSubtype();
	void setName(string);
	void setSubtype(string);
	void toString(string&);
protected:
	static int numOfEmployees;
	string id;
	string name;
	string type;
	string subtype;
};

//subclasses of employee
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