// ===============================================
// TANK'S Distribution System
// Reports Menu Interface
// ===============================================

#ifndef REPORTSMENU_H
#define REPORTSMENU_H

#include "Menu.h"
#include "Employees.h"
#include <vector>

class ReportsMenu : public Menu {
private:
    Employees* employees;

    void generatePayrollReport();
    void generatePackageSummary(); // stub for now
    void generateImportSummary();  // stub for now

public:
    ReportsMenu(Employees* empList) : employees(empList) {}
    void display() override;
};

#endif
