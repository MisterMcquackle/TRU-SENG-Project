#ifndef PACKAGEMENU_H
#define PACKAGEMENU_H

#include "Menu.h"
#include "Package.h"
#include <vector>

class PackageMenu : public Menu {
private:
    std::vector<Package>* packages;

public:
    PackageMenu(std::vector<Package>* pkgList) : packages(pkgList) {}
    void display() override;

private:
    void viewPackages();
};

#endif
