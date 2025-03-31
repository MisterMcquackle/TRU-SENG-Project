// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#include "Employees.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Add a new employee to the list
void Employees::addEmployee(const Employee& emp) {
    employeeList.push_back(emp);
}

// Remove an employee by name
void Employees::removeEmployee(const string& name) {
    auto it = remove_if(employeeList.begin(), employeeList.end(),
        [&](const Employee& emp) {
            return emp.getName() == name;
        });

    if (it != employeeList.end()) {
        employeeList.erase(it, employeeList.end());
        cout << "\033[1;32mEmployee \"" << name << "\" removed.\033[0m\n";
    } else {
        cout << "\033[1;31mEmployee \"" << name << "\" not found.\033[0m\n";
    }
}

// Show all employees in the list
void Employees::displayAll() const {
    if (employeeList.empty()) {
        cout << "\033[1;33mNo employees found.\033[0m\n";
        return;
    }

    for (const auto& emp : employeeList) {
        emp.displayInfo();
    }
}

// Search for employee by name
Employee* Employees::findEmployee(const string& name) {
    for (auto& emp : employeeList) {
        if (emp.getName() == name) {
            return &emp;
        }
    }
    return nullptr;
}
