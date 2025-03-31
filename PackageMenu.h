// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#ifndef PACKAGEMENU_H
#define PACKAGEMENU_H

#include "Menu.h"
#include "Package.h"
#include <vector>

// Menu for managing package records
class PackageMenu : public Menu {
private:
    std::vector<Package>* packages;  // Shared pointer to global package list

public:
    // Constructor to bind package list
    PackageMenu(std::vector<Package>* pkgList) : packages(pkgList) {}

    // Main display logic
    void display() override;

private:
    // Menu operations
    void addPackage();
    void viewPackages();
    void editPackage();
    void deletePackage();
};

#endif
