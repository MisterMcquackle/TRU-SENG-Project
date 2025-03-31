#include <iostream>
#include <vector>
#include "EmployeeMenu.h"
#include "PackageMenu.h"
#include "ImportMenu.h"
#include "ReportsMenu.h"
#include "SettingsMenu.h"
#include "Employees.h"
#include "Package.h"

using namespace std;

int main() {
    int choice;
    Menu* menu = nullptr;
    Employees employees;
    vector<Package> packages;
    vector<Import> imports;

    do {
        cout << "\n\033[1;36m==============================\033[0m\n";
        cout << "\033[1;36m TANK's Distribution System \033[0m\n";
        cout << "\033[1;36m==============================\033[0m\n";
        cout << "1. Employee Management\n";
        cout << "2. Package Management\n";
        cout << "3. Import Management\n";
        cout << "4. Reports & Dashboard\n";
        cout << "5. System Settings\n";
        cout << "6. Exit\n";
        cout << "------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                menu = new EmployeeMenu(&employees);
                break;
            case 2:
                menu = new PackageMenu(&packages);
                break;
            case 3:
                menu = new ImportMenu(&imports);
                break;
            case 4:
                menu = new ReportsMenu(&employees, &packages, &imports);
                break;
            case 5:
                menu = new SettingsMenu(&employees, &packages, &imports);
                break;
            case 6:
                cout << "\033[1;32mExiting... Goodbye!\033[0m\n";
                return 0;
            default:
                cout << "\033[1;31mInvalid input. Try again.\033[0m\n";
                continue;
        }

        menu->display();
        delete menu;
    } while (true);

    return 0;
}
