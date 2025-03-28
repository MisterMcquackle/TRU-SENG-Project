// ===============================================
// TANK'S Distribution System
// Employee Menu Interface
// ===============================================

#ifndef EMPLOYEEMENU_H
#define EMPLOYEEMENU_H

#include "Menu.h"
#include "Employee.h"
#include <vector>

using namespace std;

// Menu class for handling employee-related functions
class EmployeeMenu : public Menu {
private:
    vector<Employee> employees; // Container for employee records

public:
    void display() override; // Override display function to show employee menu

private:
    // Menu options
    void addEmployee();
    void viewEmployees() const;
    void updateEmployee();
    void deleteEmployee();
};

#endif
