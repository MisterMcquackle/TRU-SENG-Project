#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "Employee.h"
#include <vector>
#include <algorithm>

class Employees {
private:
    std::vector<Employee> employeeList;

public:
    void addEmployee(const Employee& emp);
    void removeEmployee(const std::string& name);
    void displayAll() const;
    Employee* findEmployee(const std::string& name);
};

#endif
