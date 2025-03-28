// ===============================================
// TANK'S Distribution System
// Import Menu Interface
// ===============================================

#ifndef IMPORTMENU_H
#define IMPORTMENU_H

#include "Menu.h"
#include <vector>
#include <string>

using namespace std;

class ImportMenu : public Menu {
private:
    vector<string> importRecords;

public:
    void display() override;

private:
    void addImportRecord();
    void viewImportRecords();
    void updateImportRecord();
};

#endif
