// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#ifndef REPORTSMENU_H
#define REPORTSMENU_H

#include "Menu.h"
#include "Employees.h"
#include "Package.h"
#include "Import.h"
#include <vector>

// Handles generation of dashboards and summaries
class ReportsMenu : public Menu {
private:
    Employees* employees;
    std::vector<Package>* packages;
    std::vector<Import>* imports;

    void generatePayrollReport();
    void generatePackageSummary();
    void generateImportSummary();

public:
    ReportsMenu(Employees* empList, std::vector<Package>* pkgList, std::vector<Import>* importList)
        : employees(empList), packages(pkgList), imports(importList) {}

    void display() override;
};

#endif
