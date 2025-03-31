// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include "Menu.h"
#include "Employees.h"
#include "Package.h"
#include "Import.h"
#include <vector>

// Menu for system utilities like generating test data
class SettingsMenu : public Menu {
private:
    Employees* employees;
    std::vector<Package>* packages;
    std::vector<Import>* imports;

public:
    // Constructor with full dataset references
    SettingsMenu(Employees* empList, std::vector<Package>* pkgList, std::vector<Import>* importList)
        : employees(empList), packages(pkgList), imports(importList) {}

    // Show main settings menu
    void display() override;

private:
    // Mass populate dummy data
    void generateTestData();
};

#endif
