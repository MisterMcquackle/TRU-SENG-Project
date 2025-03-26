#include <iostream>
#include "EmployeeMenu.h"
#include "PackageMenu.h"
#include "ImportMenu.h"
#include "ReportsMenu.h"
#include "SettingsMenu.h"

using namespace std;

// Function to handle menu selection dynamically
void showMenu(Menu* menu) {
    menu->display();
}

int main() {
    int choice;
    Menu* menu = nullptr; // Pointer to base class

    while (true) {
        cout << "----------------------------------------\n";
        cout << "  TANK'S Revolutionary Management System\n";
        cout << "----------------------------------------\n";
        cout << "1. Employee Management\n";
        cout << "2. Package Management\n";
        cout << "3. Import Management\n";
        cout << "4. Reports & Dashboard\n";
        cout << "5. System Settings\n";
        cout << "6. Exit\n";
        cout << "----------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                menu = new EmployeeMenu();
                break;
            case 2:
                menu = new PackageMenu();
                break;
            case 3:
                menu = new ImportMenu();
                break;
            case 4:
                menu = new ReportsMenu();
                break;
            case 5:
                menu = new SettingsMenu();
                break;
            case 6:
                cout << "Exiting system... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
                continue;
        }

        // Display the chosen menu
        showMenu(menu);

        // Free memory
        delete menu;
    }
}
