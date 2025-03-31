// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#include "EmployeeMenu.h"
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

// Menu logic for employee options
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
            case 5:
                cout << "\033[1;32mReturning to main menu...\033[0m\n";
                break;
            default:
                cout << "\033[1;31mInvalid choice! Please enter a number between 1 and 5.\033[0m\n";
                break;
        }
    } while (choice != 5);
}

// Adds a new employee and auto-generates a schedule
void EmployeeMenu::addEmployee() {
    string name, job;
    double rate;

    cin.ignore();
    cout << "Enter employee name: ";
    getline(cin, name);

    cout << "Enter job title: ";
    getline(cin, job);

    cout << "Enter hourly rate: ";
    cin >> rate;

    Employee e(name, job, rate);
    e.setSchedule();
    employees->addEmployee(e);

    cout << "\033[1;32mEmployee added successfully.\033[0m\n";
}

// Displays all employees
void EmployeeMenu::viewEmployees() const {
    employees->displayAll();
}

// Update an employee’s weekly schedule
void EmployeeMenu::updateEmployee() {
    string name;
    cin.ignore();
    cout << "Enter name of employee to update: ";
    getline(cin, name);

    Employee* emp = employees->findEmployee(name);
    if (emp) {
        emp->setSchedule();
        cout << "\033[1;32mSchedule updated.\033[0m\n";
    } else {
        cout << "\033[1;31mEmployee not found.\033[0m\n";
    }
}

// Delete an employee from the system
void EmployeeMenu::deleteEmployee() {
    string name;
    cin.ignore();
    cout << "Enter name of employee to delete: ";
    getline(cin, name);

    employees->removeEmployee(name);
}
