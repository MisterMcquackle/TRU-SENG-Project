// ===============================================
// TANK'S Distribution System
// Main Program Entry
// ===============================================

#include <iostream>
#include "EmployeeMenu.h"
#include "PackageMenu.h"
#include "ImportMenu.h"
#include "ReportsMenu.h"
#include "SettingsMenu.h"

using namespace std;

int main() {
    int choice;
    Menu* menu = nullptr;

    do {
        cout << "\n\033[1;36m=============================\033[0m\n"
             << "\033[1;36m TANK'S Distribution System \033[0m\n"
             << "\033[1;36m=============================\033[0m\n"
             << "1. Employee Management\n"
             << "2. Package Management\n"
             << "3. Import Management\n"
             << "4. Reports & Dashboard\n"
             << "5. System Settings\n"
             << "6. Exit\n"
             << "-----------------------------\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: menu = new EmployeeMenu(); break;
            case 2: menu = new PackageMenu(); break;
            case 3: menu = new ImportMenu(); break;
            case 4: menu = new ReportsMenu(); break;
            case 5: menu = new SettingsMenu(); break;
            case 6: cout << "\033[1;32mExiting... Goodbye!\033[0m\n"; return 0;
            default: cout << "\033[1;31mInvalid input. Try again.\033[0m\n"; continue;
        }

        menu->display();
        delete menu;
    } while (true);

    return 0;
}
