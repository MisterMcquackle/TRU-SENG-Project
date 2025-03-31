#ifndef IMPORTMENU_H
#define IMPORTMENU_H

#include "Menu.h"
#include "Import.h"
#include <vector>

class ImportMenu : public Menu {
private:
    std::vector<Import>* importList;

public:
    ImportMenu(std::vector<Import>* list) : importList(list) {}
    void display() override;

private:
    void addImportRecord();
    void viewImportRecords();
    void deleteImportRecord();
};

#endif
