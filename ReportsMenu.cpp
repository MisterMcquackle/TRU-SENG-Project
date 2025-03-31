#include "ReportsMenu.h"
#include <iostream>
#include <iomanip>

using namespace std;

void ReportsMenu::display() {
    int choice;
    do {
        cout << "\n\033[1;35m--- Reports & Dashboard ---\033[0m\n";
        cout << "1. Generate Payroll Report\n";
        cout << "2. Package Distribution Summary\n";
        cout << "3. Import Cost Summary\n";
        cout << "4. Back to Main Menu\n";
        cout << "-----------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: generatePayrollReport(); break;
            case 2: generatePackageSummary(); break;
            case 3: generateImportSummary(); break;
            case 4: break;
            default: cout << "\033[1;31mInvalid choice!\033[0m\n"; break;
        }
    } while (choice != 4);
}

void ReportsMenu::generatePayrollReport() {
    if (!employees) return;

    double totalPayroll = 0.0;
    cout << "\n\033[1;34m[Payroll Report]\033[0m\n";
    for (const auto& emp : employees->getList()) {
        cout << left << setw(20) << emp.getName()
             << " | $" << fixed << setprecision(2) << emp.getSalary() << "\n";
        totalPayroll += emp.getSalary();
    }
    cout << "----------------------------------\n";
    cout << "Total Estimated Payroll: $" << totalPayroll << "\n";
}

void ReportsMenu::generatePackageSummary() {
    cout << "\n\033[1;33m[Packages] Feature not yet implemented.\033[0m\n";
}

void ReportsMenu::generateImportSummary() {
    cout << "\n\033[1;33m[Imports] Feature not yet implemented.\033[0m\n";
}
