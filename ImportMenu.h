// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#ifndef IMPORTMENU_H
#define IMPORTMENU_H

#include "Menu.h"
#include "Import.h"
#include <vector>

// UI menu for managing material imports
class ImportMenu : public Menu {
private:
    std::vector<Import>* importList;  // Shared list of all imports

public:
    // Constructor: receives pointer to global import list
    ImportMenu(std::vector<Import>* list) : importList(list) {}

    // Main menu loop
    void display() override;

private:
    // Menu operations
    void addImportRecord();
    void viewImportRecords();
    void deleteImportRecord();
};

#endif
