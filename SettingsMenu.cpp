// ===============================================
// TANK'S Distribution System
// Settings Menu Implementation
// ===============================================

#include "SettingsMenu.h"
#include <iostream>

void SettingsMenu::display() {
    int choice;
    do {
        std::cout << "\n\033[1;31m--- System Settings ---\033[0m\n"
                  << "1. Change Console Theme (Placeholder)\n"
                  << "2. Back to Main Menu\n"
                  << "------------------------\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: changeTheme(); break;
            case 2: break;
            default: std::cout << "\033[1;31mInvalid choice!\033[0m\n";
        }
    } while (choice != 2);
}

void SettingsMenu::changeTheme() {
    std::cout << "\033[1;33m[Theme] Console theme set to default.\033[0m\n";
}
