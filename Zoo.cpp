#include "Zoo.h"

// Adds exhibit to ExhibitArray
void Zoo::addExhibit(Exhibit* exhibit) {
	exhibits.add(exhibit);
}

// Removes exhibit from ExhibitArray
void Zoo::removeExhibit(Exhibit* exhibit) {
	exhibits.remove(exhibit);
}

// Adds animal to exhibit's AnimalList
void Zoo::addAnimal(Animal* animal, Exhibit* exhibit) {
	exhibit->addAnimal(animal);
}

// Removes animal from exhibit's AnimalList
void Zoo::removeAnimal(Animal* animal, Exhibit* exhibit) {
	exhibit->removeAnimal(animal);
}

// Adds employee to EmployeeVector
void Zoo::addEmployee(Employee* employee) {
	employees.add(employee);
}

// Removes employee from EmployeeVector
void Zoo::removeEmployee(Employee* employee) {
	employees.remove(employee);
}

ExhibitArray& Zoo::getExhibits() {
	return exhibits;
}

EmployeeVector& Zoo::getEmployees() {
	return employees;
}