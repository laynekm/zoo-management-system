#include "Zoo.h"

Zoo::Zoo() {

}

Zoo::~Zoo() {

}

void Zoo::addExhibit(Exhibit* exhibit) {
	exhibits.add(exhibit);
}

void Zoo::removeExhibit(Exhibit* exhibit) {
	exhibits.remove(exhibit);
}

void Zoo::addAnimal(Animal* animal, Exhibit* exhibit) {
	exhibit->addAnimal(animal);
}

void Zoo::removeAnimal(Animal* animal, Exhibit* exhibit) {
	exhibit->removeAnimal(animal);
}

void Zoo::addEmployee(Employee* employee) {
	employees.add(employee);
}

void Zoo::removeEmployee(Employee* employee) {
	employees.remove(employee);
}

ExhibitArray& Zoo::getExhibits() {
	return exhibits;
}

EmployeeVector& Zoo::getEmployees() {
	return employees;
}