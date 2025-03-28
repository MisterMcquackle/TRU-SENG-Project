// ===============================================
// TANK'S Distribution System
// Reports Menu Interface
// ===============================================

#ifndef REPORTSMENU_H
#define REPORTSMENU_H

#include "Menu.h"
using namespace std;

class ReportsMenu : public Menu {
public:
    void display() override;

private:
    void generatePayrollReport();
    void generatePackageSummary();
    void generateImportSummary();
};

#endif
