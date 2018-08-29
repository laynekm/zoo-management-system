#include "Employee.h"

int Employee::numOfEmployees = 0;

Employee::Employee(string n) {
	stringstream ss;
	ss << setw(4) << setfill('0') << numOfEmployees;
	id = "EM-" + ss.str();

	name = n;

	numOfEmployees++;
}

Employee::~Employee() {

}

Handler::Handler(string n) : Employee(n) {
	type = "Handler";
}

Maintenance::Maintenance(string n, string s) : Employee(n) {
	type = "Maintenance";
	subtype = s;
}

Admin::Admin(string n, string s) : Employee(n) {
	type = "Admin";
	subtype = s;
}

//getters
string Employee::getID()		{return id;}
string Employee::getName()		{return name;}
string Employee::getType()		{return type;}
string Employee::getSubtype()	{return subtype;}

//setters (id and type should not have setters)
void Employee::setName(string n)	{name = n;}
void Employee::setSubtype(string s) {subtype = s;}