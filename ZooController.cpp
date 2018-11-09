#include "ZooController.h"

ZooController::ZooController() {
	initExhibits();
	initAnimals();
	initEmployees();
}

//displays all program features, calls function based on user input
void ZooController::mainMenu() {
	stringstream ss;
	ss << left;
	ss << "\n-----------------------------------------" << endl;
	ss << "---| ZOO MANAGEMENT SYSTEM MAIN MENU |---" << endl;
	ss << "-----------------------------------------" << endl;
	ss << setw(22) << "1. Display Animals"	<< setw(22) << "5. Display Employees" << setw(22) << "9. Display Exhibits" << setw(22) << "13. Sing me a song" << endl;
	ss << setw(22) << "2. Add Animal"		<< setw(22) << "6. Add Employee" << setw(22) << "10. Add Exhibit" << setw(22) << "14. Quit" << endl;
	ss << setw(22) << "3. Remove Animal"	<< setw(22) << "7. Remove Employee" << setw(22) << "11. Remove Exhibit" << endl;
	ss << setw(22) << "4. Edit Animal"		<< setw(22) << "8. Edit Employee" << setw(22) << "12. Edit Exhibit" << endl;
	cout << ss.str();

	int choice = 0;
	cout << "\nSelect an option: ";
	choice = util.promptForIntRange(1, 14);

	if (choice == 1)		{ displayAnimalsPrompt(); }
	else if (choice == 2)	{ addAnimalPrompt(); }
	else if (choice == 3)	{ removeAnimalPrompt(); }
	else if (choice == 4)	{ editAnimalPrompt(); }
	else if (choice == 5)	{ displayEmployeesPrompt(); }
	else if (choice == 6)	{ addEmployeePrompt(); }
	else if (choice == 7)	{ removeEmployeePrompt(); }
	else if (choice == 8)	{ editEmployeePrompt(); }
	else if (choice == 9)	{ displayExhibitsPrompt(); }
	else if (choice == 10)	{ addExhibitPrompt(); }
	else if (choice == 11)	{ removeExhibitPrompt(); }
	else if (choice == 12)	{ editExhibitPrompt(); }
	else if (choice == 13)	{ allTogetherNow(); }
	else { return; }

}

//displays all exhibits (including its hanndler and animals)
void ZooController::displayExhibitsPrompt() {
	string exhibitString;
	zoo.getExhibits().toString(exhibitString);

	stringstream ss;
	ss << "-----| EXHIBITS |-----------------------------------------------------------" << endl;
	ss << exhibitString;
	ss << "---------------------------------------------------------------------------" << endl;
	cout << ss.str();

	util.waitForInput();
	mainMenu();
}

//prompts user to add new exhibit
void ZooController::addExhibitPrompt() {
	string name;
	cout << "Name: ";
	name = util.promptForString();

	Exhibit* exhibit = new Exhibit(name);
	zoo.addExhibit(exhibit);
	cout << "Exhibit added.\n";

	util.waitForInput();
	mainMenu();
}

//prompts user for exhibit id, finds this exhibit, then deletes it
void ZooController::removeExhibitPrompt() {
	cout << "--- REMOVE EXHIBIT MENU ---\n";

	string id;
	cout << "Enter ID of exhibit to be removed: ";
	id = util.promptForString();

	Exhibit* exhibit = zoo.getExhibits().find(id);
	if (exhibit == NULL) {
		cout << "Exhibit not found.\n";
	}
	else {
		zoo.removeExhibit(exhibit);
		cout << "Exhibit removed.\n";
	}

	util.waitForInput();
	mainMenu();
}

//prompts user to edit exhibit attributes (if id exists)
void ZooController::editExhibitPrompt() {
	cout << "--- EDIT EXHIBIT MENU ---\n";

	string id;
	cout << "Enter Exhibit ID: ";
	id = util.promptForString();

	Exhibit* exhibit = zoo.getExhibits().find(id);

	if (exhibit == NULL) {
		cout << "Exhibit not found.";
		util.waitForInput();
		mainMenu();
	}

	string exhibitString;
	exhibit->toString(exhibitString);
	cout << exhibitString << endl;

	cout << "Fields that can be edited: \n";
	cout << "1. Name\n";
	cout << "2. Handler\n";

	cout << "Select an option: ";
	int selection = util.promptForIntRange(1, 2);

	//prompts for new name, changes name
	if (selection == 1) {
		cout << "Enter new name: \n";
		string name = util.promptForString();
		exhibit->setName(name);
		cout << "Name changed.\n";
	}

	//displays all employees of type handler, prompts for selection, then edits old/new handler
	else {
		cout << "Select new handler: \n";
		int employeeInt;
		int size = zoo.getEmployees().getSize();
		for (int i = 0; i < size; i++) {
			if (zoo.getEmployees().get(i)->getType() == "Handler") {
				cout << i + 1<< ". " << zoo.getEmployees().get(i)->getName() << endl;
			}
		}

		employeeInt = util.promptForIntRange(0, size);
		Employee* handler = zoo.getEmployees().get(employeeInt - 1);
		exhibit->setHandler(handler);
	}

	util.waitForInput();
	mainMenu();
}

//displays all animal in the zoo, in order of exhibit id (order is implicit as exhibit ids are constant, they will appear in whichever order they were added)
void ZooController::displayAnimalsPrompt() {
	string animalString;
	stringstream ss;

	ss << "-----| ANIMALS |-----------------------------------------------------------" << endl
		<< setw(12) << "TYPE"
		<< setw(12) << "ID"
		<< setw(12) << "NAME"
		<< setw(12) << "SPECIES"
		<< setw(12) << "EXHIBIT"
		<< setw(15) << "BIRTH YEAR" << endl;

	for (int i = 0; i < zoo.getExhibits().getSize(); i++) {
		zoo.getExhibits().get(i)->getAnimals()->toString(animalString);
		ss << animalString;
	}

	ss << "---------------------------------------------------------------------------" << endl;
	cout << ss.str();

	util.waitForInput();
	mainMenu();
}

//prompts user for new animal attributes, creates new animal of specified type, adds to exhibit
void ZooController::addAnimalPrompt() {
	cout << "--- ADD ANIMAL MENU ---\n";

	if (zoo.getExhibits().getSize() == 0) {
		cout << "No exhibits in the zoo! Cannot add animals if there are no exhibits." << endl;
		util.waitForInput();
		mainMenu();
	}

	string name;
	string species;
	string exhibitName;
	string typeString;
	int typeInt = 0;
	int exhibitSelector = 0;
	int yearOfBirth = -1;
	int lifeExpectancy = -1;

	cout << "Type:\n";
	cout << "1. Mammal\n";
	cout << "2. Reptile\n";
	cout << "3. Amphibian\n";
	cout << "4. Bird\n";
	cout << "5. Fish\n";
	cout << "\nSelect an option: ";
	typeInt = util.promptForIntRange(1, 5);

	cout << "Name: ";
	name = util.promptForString();

	cout << "Species: ";
	species = util.promptForString();

	cout << "Exhibit:\n";
	ExhibitArray& exhibits = zoo.getExhibits();
	int size = exhibits.getSize();
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". " << exhibits.get(i)->getName() << endl;
	}

	cout << "Select an option: ";
	exhibitSelector = util.promptForIntRange(1, size);
	Exhibit* exhibit = exhibits.get(exhibitSelector - 1);

	cout << "Year of birth: ";
	yearOfBirth = util.promptForInt();

	if (typeInt == 1){
		Animal* mammal = new Mammal(name, species, yearOfBirth);
		zoo.addAnimal(mammal, exhibit);
	}
	else if(typeInt == 2){ 
		Animal* reptile = new Reptile(name, species, yearOfBirth);
		zoo.addAnimal(reptile, exhibit);
	}
	else if(typeInt == 3){
		Animal* amphibian = new Amphibian(name, species, yearOfBirth);
		zoo.addAnimal(amphibian, exhibit);
	}
	else if(typeInt == 4){
		Animal* bird = new Bird(name, species, yearOfBirth);
		zoo.addAnimal(bird, exhibit);
	}
	else{
		Animal* fish = new Fish(name, species, yearOfBirth);
		zoo.addAnimal(fish, exhibit);
	}

	cout << "Animal added.\n";
	util.waitForInput();
	mainMenu();
}

//prompts user for animal id, verifies this id exists, then removes animal
void ZooController::removeAnimalPrompt() {
	cout << "--- REMOVE ANIMAL MENU ---\n";

	string id;
	cout << "Enter ID of animal to be removed: ";
	id = util.promptForString();

	ExhibitArray& exhibits = zoo.getExhibits();
	Exhibit* exhibit = NULL;
	Animal* animal = NULL;

	for (int i = 0; i < exhibits.getSize(); i++) {
		exhibit = exhibits.get(i);
		animal = exhibit->getAnimals()->find(id);
		if (animal != NULL) {
			break;
		}
	}

	if (animal == NULL || exhibit == NULL) {
		cout << "Animal not found.\n";
	}
	else {
		zoo.removeAnimal(animal, exhibit);
		cout << "Animal removed.\n";
	}

	util.waitForInput();
	mainMenu();
}

//prompts user to edit animal attributes (if id exists)
void ZooController::editAnimalPrompt() {
	cout << "--- EDIT ANIMAL MENU ---\n";

	string id;
	cout << "Enter Animal ID: ";
	id = util.promptForString();

	Animal* animal = NULL;
	Exhibit* exhibit = NULL;
	for (int i = 0; i < zoo.getExhibits().getSize(); i++) {
		exhibit = zoo.getExhibits().get(i);
		animal = exhibit->getAnimals()->find(id);
		if (animal != NULL) {
			break;
		}
	}

	if (animal == NULL) {
		cout << "Animal not found.";
		util.waitForInput();
		mainMenu();
	}

	string animalString;
	animal->toString(animalString);
	cout << animalString << endl << endl;

	cout << "Fields that can be edited: \n";
	cout << "1. Type\n";
	cout << "2. Name\n";
	cout << "3. Species\n";
	cout << "4. Exhibit\n";
	cout << "5. Year of birth\n";

	cout << "Select an option: ";
	int selection = util.promptForIntRange(1, 5);

	//creates deep copy of object of new animal-type
	if (selection == 1) {
		cout << "Select new type:\n";
		cout << "1. Mammal\n";
		cout << "2. Reptile\n";
		cout << "3. Amphibian\n";
		cout << "4. Bird\n";
		cout << "5. Fish\n";
		cout << "Select an option: ";
		int typeInt = util.promptForIntRange(1, 5);


		string name = animal->getName();
		string species = animal->getSpecies();
		int yearOfBirth = animal->getYearOfBirth();

		if (typeInt == 1) {
			Animal* mammal = new Mammal(name, species, yearOfBirth);
			zoo.addAnimal(mammal, exhibit);
			cout << "Type changed (deep-copy created). New ID: " << mammal->getID();
		}
		else if (typeInt == 2) {
			Animal* reptile = new Reptile(name, species, yearOfBirth);
			zoo.addAnimal(reptile, exhibit);
			cout << "Type changed (deep-copy created). New ID: " << reptile->getID();
		}
		else if (typeInt == 3) {
			Animal* amphibian = new Amphibian(name, species, yearOfBirth);
			zoo.addAnimal(amphibian, exhibit);
			cout << "Type changed (deep-copy created). New ID: " << amphibian->getID();
		}
		else if (typeInt == 4) {
			Animal* bird = new Bird(name, species, yearOfBirth);
			zoo.addAnimal(bird, exhibit);
			cout << "Type changed (deep-copy created). New ID: " << bird->getID();
		}
		else {
			Animal* fish = new Fish(name, species, yearOfBirth);
			zoo.addAnimal(fish, exhibit);
			cout << "Type changed (deep-copy created). New ID: " << fish->getID();
		}

		zoo.removeAnimal(animal, exhibit);
	}

	//prompts for new name, sets new name
	else if (selection == 2) {
		cout << "Enter new name: ";
		string name = util.promptForString();
		animal->setName(name);
		cout << "Name changed.\n";
	}

	//prompts for new species, sets new species
	else if (selection == 3) {
		cout << "Enter new species: ";
		string species = util.promptForString();
		animal->setSpecies(species);
		cout << "Species changed.\n";
		
	}

	//prompts for new exhibit, moves to new exhibit
	else if (selection == 4) {
		int selection = 0;
		ExhibitArray& exhibits = zoo.getExhibits();
		int size = exhibits.getSize();

		for (int i = 0; i < size; i++) {
			cout << i + 1 << ". " << exhibits.get(i)->getName() << endl;
		}

		cout << "Select new exhibit: ";
		selection = util.promptForIntRange(1, size);
		Exhibit* newExhibit = exhibits.get(selection - 1);

		exhibit->removeAnimalWithoutDeleting(animal);
		newExhibit->addAnimal(animal);
		cout << "Exhibit changed.\n";
	}

	//prompts for new year of birth, sets new year of birth
	else {
		cout << "Enter new year of birth: ";
		int year = util.promptForInt();
		animal->setYearOfBirth(year);
		cout << "Year of birth changed.\n";
	}

	util.waitForInput();
	mainMenu();
}

//displays all employees
void ZooController::displayEmployeesPrompt() {
	string employeeString;
	zoo.getEmployees().toString(employeeString);
	cout << employeeString;

	util.waitForInput();
	mainMenu();
}

//prompts user to input employee attributes, creates employee; if handler, it is added to exhibit
void ZooController::addEmployeePrompt() {
	cout << "--- ADD EMPLOYEE MENU ---\n";

	string name;
	string subtype;
	int typeInt = 0;
	int exhibitInt = 0;
	Exhibit* exhibit = NULL;

	cout << "Type:\n";
	cout << "1. Handler\n";
	cout << "2. Maintenance\n";
	cout << "3. Admin\n";
	cout << "\nSelect an option: ";
	typeInt = util.promptForIntRange(1, 3);

	cout << "Name: ";
	name = util.promptForString();
	
	//prompts for subtype
	if (typeInt == 1) {
		cout << "Handler exhibit:\n";
		ExhibitArray& exhibits = zoo.getExhibits();
		int size = exhibits.getSize();
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ". " << exhibits.get(i)->getName() << endl;
		}

		cout << "Select an option: ";
		exhibitInt = util.promptForIntRange(1, size);
		exhibit = exhibits.get(exhibitInt - 1);
		//subtype gets set once successfully added to exhibit
	}
	else if (typeInt == 2) {
		cout << "Maintenance job: ";
		subtype = util.promptForString();
	}
	else {
		cout << "Admin job: ";
		subtype = util.promptForString();
	}

	//creates objects, adds to EmployeeVector
	if (typeInt == 1) {
		Employee* handler = new Handler(name);
		zoo.addEmployee(handler);
		exhibit->setHandler(handler); 
	}
	else if (typeInt == 2) {
		Employee* maintenance = new Maintenance(name, subtype);
		zoo.addEmployee(maintenance);
	}
	else{
		Employee* admin = new Admin(name, subtype);
		zoo.addEmployee(admin);
	}

	cout << "Employe added.\n";
	util.waitForInput();
	mainMenu();
}

//prompts user for employee id, verifies id exists, removes employee
void ZooController::removeEmployeePrompt() {
	cout << "--- REMOVE EMPLOYEE MENU ---\n";

	string id;
	cout << "Enter ID of employee to be removed: ";
	id = util.promptForString();

	Employee* employee = zoo.getEmployees().find(id);
	if (employee == NULL) {
		cout << "Employee not found.\n";
	}
	else {
		//if employee is handler, must also set exhibit's exhibitHandler to NULL to prevent null pointer
		ExhibitArray& exhibits = zoo.getExhibits();
		for (int i = 0; i < exhibits.getSize(); i++) {
			Exhibit* exhibit = exhibits.get(i);
			if (exhibit->getHandler() == employee) {
				exhibit->setHandler(NULL);
			}
		}

		zoo.removeEmployee(employee);
		cout << "Employee removed.\n";
	}

	util.waitForInput();
	mainMenu();
}

//prompts user to edit employee attributes
void ZooController::editEmployeePrompt() {
	cout << "--- EDIT EMPLOYEE MENU ---\n";

	string id;
	cout << "Enter Employee ID: ";
	id = util.promptForString();

	Employee* employee = zoo.getEmployees().find(id);

	if (employee == NULL) {
		cout << "Employee not found.";
		util.waitForInput();
		mainMenu();
	}

	string employeeString;
	employee->toString(employeeString);
	cout << employeeString << endl;

	cout << "Fields that can be edited: \n";
	cout << "1. Type\n";
	cout << "2. Name\n";
	cout << "3. Subtype\n";

	cout << "Select an option: ";
	int selection = util.promptForIntRange(1, 3);

	//creates deep copy of employee with new type
	if (selection == 1) {
		cout << "Select new type:\n";
		cout << "1. Handler\n";
		cout << "2. Maintenance\n";
		cout << "3. Admin\n";
		cout << "\nSelect an option: ";
		int typeInt = util.promptForIntRange(1, 3);

		string name = employee->getName();
		string subtype = employee->getSubtype();

		//if new type is handler, must also prompt for handler's exhibit
		if (typeInt == 1) {
			Employee* handler = new Handler(name);
			cout << "Handler exhibit:\n";
			ExhibitArray& exhibits = zoo.getExhibits();
			int size = exhibits.getSize();
			for (int i = 0; i < size; i++) {
				cout << i + 1 << ". " << exhibits.get(i)->getName() << endl;
			}

			cout << "Select an option: ";
			int exhibitInt = util.promptForIntRange(1, size);
			Exhibit* exhibit = exhibits.get(exhibitInt - 1);
			zoo.addEmployee(handler);
			exhibit->setHandler(handler);

			cout << "Type changed (deep-copy created). New ID: " << handler->getID();
		}
		else if (typeInt == 2) {
			Employee* maintenance = new Maintenance(name, subtype);
			zoo.addEmployee(maintenance);
			cout << "Type changed (deep-copy created). New ID: " << maintenance->getID();
		}
		else {
			Employee* admin = new Admin(name, subtype);
			zoo.addEmployee(admin);
			cout << "Type changed (deep-copy created). New ID: " << admin->getID();
		}

		zoo.removeEmployee(employee);
	}


	//prompts for new name, sets new name
	else if (selection == 2) {
		cout << "Enter new name: \n";
		string name = util.promptForString();
		employee->setName(name);
		cout << "Name changed.\n";
	}

	//prompts for new subtype, sets new subtype
	else if (selection == 3) {
		cout << "Enter new subtype: \n";
		string subtype = util.promptForString();
		employee->setSubtype(subtype);
		cout << "Subtype changed.\n";
	}

	util.waitForInput();
	mainMenu();
}

//initializes default exhibits, adds to ExhibitArray
void ZooController::initExhibits() {
	cout << "Initializing exhibits..." << endl;
	Exhibit* exhibit1 = new Exhibit("Temperate");
	Exhibit* exhibit2 = new Exhibit("Arctic");
	Exhibit* exhibit3 = new Exhibit("Desert");
	Exhibit* exhibit4 = new Exhibit("Marine");
	Exhibit* exhibit5 = new Exhibit("Jurassic");
	Exhibit* exhibit6 = new Exhibit("Savannah");

	zoo.addExhibit(exhibit1);
	zoo.addExhibit(exhibit2);
	zoo.addExhibit(exhibit3);
	zoo.addExhibit(exhibit4);
	zoo.addExhibit(exhibit5);
	zoo.addExhibit(exhibit6);
}

//initializes default animals, adds to an exhibit's AnimalList
void ZooController::initAnimals() {
	cout << "Initializing animals..." << endl;

	Animal* mammal1 = new Mammal("Gustave", "Black Bear", 2000);
	Animal* bird1 = new Bird("Zero", "Pigeon", 2016);
	Animal* bird2 = new Bird("Agatha", "Seagull", 2017);
	Exhibit* temperate = zoo.getExhibits().get(0);
	zoo.addAnimal(mammal1, temperate);
	zoo.addAnimal(bird1, temperate);
	zoo.addAnimal(bird2, temperate);

	Animal* mammal2 = new Mammal("Sam", "Arctic Fox", 2015);
	Animal* mammal3 = new Mammal("Suzy", "Polar Bear", 2014);
	Animal* mammal4 = new Mammal("Ward", "Walrus", 1995);
	Animal* reptile1 = new Reptile("Mr. Bishop", "Salamander", 2000);
	Exhibit* arctic = zoo.getExhibits().get(1);
	zoo.addAnimal(mammal2, arctic);
	zoo.addAnimal(mammal3, arctic);
	zoo.addAnimal(mammal4, arctic);
	zoo.addAnimal(reptile1, arctic);

	Animal* mammal5 = new Mammal("Andy", "Desert Fox", 2000);
	Animal* reptile2 = new Reptile("Red", "Turtle", 1920);
	Exhibit* desert = zoo.getExhibits().get(2);
	zoo.addAnimal(mammal5, desert);
	zoo.addAnimal(reptile2, desert);

	Animal* mammal6 = new Mammal("Jack", "Seal", 1999);
	Animal* fish1 = new Fish("Will", "Salmon", 2005);
	Animal* fish2 = new Fish("Elizabeth", "Catfish", 2007);
	Exhibit* marine = zoo.getExhibits().get(3);
	zoo.addAnimal(mammal6, marine);
	zoo.addAnimal(fish1, marine);
	zoo.addAnimal(fish2, marine);

	Animal* reptile3 = new Reptile("Grant", "T-Rex", -65000000);
	Animal* mammal7 = new Mammal("Stu", "Human", 1980);
	Exhibit* jurassic = zoo.getExhibits().get(4);
	zoo.addAnimal(reptile3, jurassic);
	zoo.addAnimal(mammal7, jurassic);

}

//initializes default employees, adds to EmployeeVector (handler is also added to exhibit)
void ZooController::initEmployees() {
	cout << "Initializing employees..." << endl;

	ExhibitArray& exhibits = zoo.getExhibits();
	Employee* handler1 = new Handler("Barry Leonard");
	Employee* handler2 = new Handler("Ian Shelton");
	Employee* handler3 = new Handler("Hubert Reynolds");
	Employee* handler4 = new Handler("Colleen McGuire");
	Employee* handler5 = new Handler("Maurice Stevens");
	zoo.addEmployee(handler1);
	zoo.addEmployee(handler2);
	zoo.addEmployee(handler3);
	zoo.addEmployee(handler4);
	zoo.addEmployee(handler5);
	exhibits.get(0)->setHandler(handler1);
	exhibits.get(1)->setHandler(handler2);
	exhibits.get(2)->setHandler(handler3);
	exhibits.get(3)->setHandler(handler4);
	exhibits.get(4)->setHandler(handler5);


	Employee* maintenance1 = new Maintenance("Jesse Singleton", "Plumbing");
	Employee* maintenance2 = new Maintenance("Mable Sims", "Electric");
	zoo.addEmployee(maintenance1);
	zoo.addEmployee(maintenance2);

	Employee* admin1 = new Admin("Bonnie Zimmerman", "IT");
	Employee* admin2 = new Admin("Mildred Christensen", "HR");
	zoo.addEmployee(admin1);
	zoo.addEmployee(admin2);
}

//displays each animal's custom song() function derived from abstract base class, uses polymorphism
void ZooController::allTogetherNow() {
	string exhibitListString;
	zoo.getExhibits().toSongString(exhibitListString);
	cout << exhibitListString;

	util.waitForInput();
	mainMenu();
}