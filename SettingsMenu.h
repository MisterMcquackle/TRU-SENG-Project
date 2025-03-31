#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include "Menu.h"
#include "Employees.h"
#include "Package.h"
#include <vector>

class SettingsMenu : public Menu {
private:
    Employees* employees;
    std::vector<Package>* packages;

public:
    SettingsMenu(Employees* empList, std::vector<Package>* pkgList)
        : employees(empList), packages(pkgList) {}

    void display() override;

private:
    void generateTestData();
};

#endif
