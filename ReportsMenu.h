#ifndef REPORTSMENU_H
#define REPORTSMENU_H

#include "Menu.h"
#include "Employees.h"
#include "Package.h"
#include <vector>

class ReportsMenu : public Menu {
private:
    Employees* employees;
    std::vector<Package>* packages;

    void generatePayrollReport();
    void generatePackageSummary();
    void generateImportSummary();

public:
    ReportsMenu(Employees* empList, std::vector<Package>* pkgList)
        : employees(empList), packages(pkgList) {}
    void display() override;
};

#endif
