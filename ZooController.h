#pragma once
#include "Utilities.h"
#include "Exhibit.h"
#include "Animal.h"
#include "Employee.h"
#include "Zoo.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ZooController {
	public:
		ZooController();				//constructor, calls init functions
		void mainMenu();				//zoo main menu, called by main.cpp
	private:
		Zoo zoo;					
		Utilities util;
		void initAnimals();				//all the init, display, add, remove object UI
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
		void allTogetherNow();			//polymorphism example, dislpays each Animal subclass's song
};