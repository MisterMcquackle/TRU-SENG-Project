#include "Employees.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Employees::addEmployee(const Employee& emp) {
    employeeList.push_back(emp);
}

void Employees::removeEmployee(const string& name) {
    auto it = remove_if(employeeList.begin(), employeeList.end(),
        [&](const Employee& emp) {
            return emp.getName() == name;
        });

    if (it != employeeList.end()) {
        employeeList.erase(it, employeeList.end());
        cout << "Employee \"" << name << "\" removed.\n";
    } else {
        cout << "Employee \"" << name << "\" not found.\n";
    }
}

void Employees::displayAll() const {
    if (employeeList.empty()) {
        cout << "No employees found.\n";
        return;
    }
    for (const auto& emp : employeeList) {
        emp.displayInfo();
    }
}

Employee* Employees::findEmployee(const string& name) {
    for (auto& emp : employeeList) {
        if (emp.getName() == name) {
            return &emp;
        }
    }
    return nullptr;
}
