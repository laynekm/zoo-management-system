#pragma once
#include "Utilities.h"
#include "Exhibit.h"
#include "Animal.h"
#include "Employee.h"
#include "Zoo.h"
#include <iostream>
#include <string>
#include <fstream>

class ZooController {
	public:
		ZooController();
		void mainMenu();
	private:
		Zoo zoo;
		Utilities util;
		void initAnimals();
		void displayAnimalsPrompt();
		void addAnimalPrompt();
		void removeAnimalPrompt();
		void editAnimalPrompt();
		void initEmployees();
		void displayEmployeesPrompt();
		void addEmployeePrompt();
		void removeEmployeePrompt();
		void editEmployeePrompt();
		void initExhibits();
		void displayExhibitsPrompt();
		void addExhibitPrompt();
		void removeExhibitPrompt();
		void editExhibitPrompt();
		void allTogetherNow();
};