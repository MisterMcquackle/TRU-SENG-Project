// ===============================================
// TANK'S Distribution System
// Package Menu Interface
// ===============================================

#ifndef PACKAGEMENU_H
#define PACKAGEMENU_H

#include "Menu.h"
#include "Package.h"
#include <vector>

class PackageMenu : public Menu {
private:
    std::vector<Package> packages;

public:
    void display() override;

private:
    void addPackage();
    void viewPackages();
    void updatePackageStatus();
};

#endif
