// ===============================================
// TANK'S Distribution System
// Employee Menu Interface
// ===============================================

#ifndef EMPLOYEEMENU_H
#define EMPLOYEEMENU_H

#include "Menu.h"
#include "Employees.h"
#include <vector>

class EmployeeMenu : public Menu {
private:
    Employees* employees;

public:
    EmployeeMenu(Employees* empList) : employees(empList) {}
    void display() override;

private:
    void addEmployee();
    void viewEmployees() const;
    void updateEmployee();
    void deleteEmployee();
};

#endif
