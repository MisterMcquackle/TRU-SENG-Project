// ==========================================
// TRU-SENG Project - Employee Management Menu
// ==========================================

#include "EmployeeMenu.h"
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

void EmployeeMenu::display() {
    int choice;
    do {
        cout << "\n\033[1;33m--- Employee Management ---\033[0m\n"
             << "1. Add New Employee\n"
             << "2. View Employee List\n"
             << "3. Update Employee Information\n"
             << "4. Delete Employee\n"
             << "5. Back to Main Menu\n"
             << "-----------------------------\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: updateEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: cout << "Returning to main menu...\n"; break;
            default:
                cout << "\033[1;31mInvalid choice! Please enter a number between 1 and 5.\033[0m\n";
                break;
        }
    } while (choice != 5);
}

void EmployeeMenu::addEmployee() {
    string name, jobTitle;
    double rate;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter job title: ";
    getline(cin, jobTitle);

    cout << "Enter hourly rate: ";
    cin >> rate;

    Employee newEmp(name, jobTitle, rate);
    newEmp.setSchedule();
    employees.push_back(newEmp);

    cout << "Employee added successfully.\n";
}

void EmployeeMenu::viewEmployees() const {
    if (employees.empty()) {
        cout << "No employees to display.\n";
        return;
    }

    for (const auto& emp : employees) {
        emp.displayInfo();
    }
}

void EmployeeMenu::updateEmployee() {
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter name of employee to update: ";
    getline(cin, name);

    for (auto& emp : employees) {
        if (emp.getName() == name) {
            cout << "Found employee. Updating schedule...\n";
            emp.setSchedule();
            return;
        }
    }
    cout << "Employee not found.\n";
}

void EmployeeMenu::deleteEmployee() {
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter name of employee to delete: ";
    getline(cin, name);

    auto it = remove_if(employees.begin(), employees.end(),
        [&](const Employee& emp) {
            return emp.getName() == name;
        });

    if (it != employees.end()) {
        employees.erase(it, employees.end());
        cout << "Employee deleted successfully.\n";
    } else {
        cout << "Employee not found.\n";
    }
}
