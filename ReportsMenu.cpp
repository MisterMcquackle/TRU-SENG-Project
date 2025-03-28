// ===============================================
// TANK'S Distribution System
// Reports Menu Implementation
// ===============================================

#include "ReportsMenu.h"
#include <iostream>

using namespace std;

void ReportsMenu::display() {
    int choice;
    do {
        cout << "\n\033[1;35m--- Reports & Dashboard ---\033[0m\n"
             << "1. Generate Payroll Report\n"
             << "2. Package Distribution Summary\n"
             << "3. Import Cost Summary\n"
             << "4. Back to Main Menu\n"
             << "----------------------------\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: generatePayrollReport(); break;
            case 2: generatePackageSummary(); break;
            case 3: generateImportSummary(); break;
            case 4: break;
            default: cout << "\033[1;31mInvalid choice!\033[0m\n";
        }
    } while (choice != 4);
}

void ReportsMenu::generatePayrollReport() {
    cout << "\033[1;32m[Payroll] Total payroll calculated: $25,000 this month.\033[0m\n";
}

void ReportsMenu::generatePackageSummary() {
    cout << "\033[1;32m[Packages] 120 packages processed today.\033[0m\n";
}

void ReportsMenu::generateImportSummary() {
    cout << "\033[1;32m[Imports] 15 new imports received this week.\033[0m\n";
}
