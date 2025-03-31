// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#ifndef EMPLOYEEMENU_H
#define EMPLOYEEMENU_H

#include "Menu.h"
#include "Employees.h"
#include <vector>

// Handles the Employee Management Menu UI
class EmployeeMenu : public Menu {
private:
    Employees* employees;  // Pointer to global employee list

public:
    // Constructor
    EmployeeMenu(Employees* empList) : employees(empList) {}

    // Entry point for the menu
    void display() override;

private:
    // Menu actions
    void addEmployee();
    void viewEmployees() const;
    void updateEmployee();
    void deleteEmployee();
};

#endif
