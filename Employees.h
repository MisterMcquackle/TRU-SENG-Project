// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "Employee.h"
#include <vector>
#include <string>

// Manages a list of Employee objects (like a database)
class Employees {
private:
    std::vector<Employee> employeeList;

public:
    // Add new employee to the list
    void addEmployee(const Employee& emp);

    // Remove employee by name
    void removeEmployee(const std::string& name);

    // Display all employees and their data
    void displayAll() const;

    // Search for employee by name
    Employee* findEmployee(const std::string& name);

    // Getter for the internal list (used in reports)
    const std::vector<Employee>& getList() const { return employeeList; }
};

#endif
