--- Zoo Management System ---
Author: Layne Koftinow-Mikan

A management system for a zoo which allows for handling of exhibits, animals, and employees.
Uses object-oriented programming techniques such as inheritance, polymorphism, encapsulation, and data abstraction.

Different data structures such as linked list, array, and vector containers are used to store dynamically allocated objects of exhibits, animals, and employes.
ExhibitArray stores Exhibits, each of which stores an AnimalList of Animals; EmployeeVector stores Employees.
Virtual base classes such as 'Animal' are inherited by concrete classes such as 'Mammal' or 'Bird', which each implement a variant of Animal's pure virtual functions.
Data and functions are encapsulated in manys ways; most notably, the user only interacts with the 'ZooController' class, not with the 'Zoo' or its data structures themselves