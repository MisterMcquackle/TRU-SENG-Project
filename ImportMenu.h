// ===============================================
// TANK'S Distribution System
// Import Menu Interface
// ===============================================

#ifndef IMPORTMENU_H
#define IMPORTMENU_H

#include "Menu.h"
#include <vector>
#include <string>

class ImportMenu : public Menu {
private:
    std::vector<std::string> importRecords;

public:
    void display() override;

private:
    void addImportRecord();
    void viewImportRecords();
    void updateImportRecord();
};

#endif
