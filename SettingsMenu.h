#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include "Menu.h"
#include "Employees.h"
#include "Package.h"
#include "Import.h"
#include <vector>

class SettingsMenu : public Menu {
private:
    Employees* employees;
    std::vector<Package>* packages;
    std::vector<Import>* imports; 

public:
    SettingsMenu(Employees* empList, std::vector<Package>* pkgList, std::vector<Import>* importList)
        : employees(empList), packages(pkgList), imports(importList) {}

    void display() override;

private:
    void generateTestData();
};

#endif
