#include "EmployeeMenu.h"
#include <iostream>
#include <limits>

using namespace std;

void EmployeeMenu::display() {
    int choice;
    do {
        cout << "\n\033[1;33m--- Employee Management ---\033[0m\n";
        cout << "1. Add New Employee\n";
        cout << "2. View Employee List\n";
        cout << "3. Update Employee Information\n";
        cout << "4. Delete Employee\n";
        cout << "5. Back to Main Menu\n";
        cout << "---------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: updateEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: cout << "Returning to main menu...\n"; break;
            default: cout << "\033[1;31mInvalid choice! Please enter a number between 1 and 5.\033[0m\n"; break;
        }
    } while (choice != 5);
}

void EmployeeMenu::addEmployee() {
    string name, jobTitle;
    double rate;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter job title: ";
    getline(cin, jobTitle);

    cout << "Enter hourly rate: ";
    cin >> rate;

    Employee newEmp(name, jobTitle, rate);
    newEmp.setSchedule();
    employees->addEmployee(newEmp);

    cout << "Employee added successfully.\n";
}

void EmployeeMenu::viewEmployees() const {
    employees->displayAll();
}

void EmployeeMenu::updateEmployee() {
    string name;
    cout << "Enter name of employee to update: ";
    cin.ignore();
    getline(cin, name);

    Employee* emp = employees->findEmployee(name);
    if (emp) {
        cout << "Found employee. Updating schedule...\n";
        emp->setSchedule();
    } else {
        cout << "Employee not found.\n";
    }
}

void EmployeeMenu::deleteEmployee() {
    string name;
    cout << "Enter name of employee to delete: ";
    cin.ignore();
    getline(cin, name);

    employees->removeEmployee(name);
}
