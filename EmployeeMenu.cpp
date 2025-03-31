// ===============================================
// TANK'S Distribution System
// Employee Menu Implementation (Fixed)
// ===============================================

#include "EmployeeMenu.h"
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

void EmployeeMenu::display() {
    int choice;
    do {
        cout << "\n\033[1;33m--- Employee Management ---\033[0m\n"
             << "1. Add New Employee\n"
             << "2. View Employee List\n"
             << "3. Update Employee Information\n"
             << "4. Delete Employee\n"
             << "5. Back to Main Menu\n"
             << "---------------------------\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: updateEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: cout << "Returning to main menu...\n"; break;
            default:
                cout << "\033[1;31mInvalid choice! Please enter a number between 1 and 5.\033[0m\n";
                break;
        }
    } while (choice != 5);
}
