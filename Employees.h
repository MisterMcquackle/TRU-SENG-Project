#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "Employee.h"
#include <vector>
#include <string>

class Employees {
private:
    std::vector<Employee> employeeList;

public:
    void addEmployee(const Employee& emp);
    void removeEmployee(const std::string& name);
    void displayAll() const;
    Employee* findEmployee(const std::string& name);

    const std::vector<Employee>& getList() const { return employeeList; }
};

#endif
