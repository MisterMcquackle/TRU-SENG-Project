#include "PackageMenu.h"
#include <iostream>

using namespace std;

void PackageMenu::display() {
    int choice;
    do {
        cout << "\n\033[1;33m--- Package Management ---\033[0m\n";
        cout << "1. View All Packages\n";
        cout << "2. Back to Main Menu\n";
        cout << "--------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: viewPackages(); break;
            case 2: break;
            default: cout << "\033[1;31mInvalid choice!\033[0m\n"; break;
        }
    } while (choice != 2);
}

void PackageMenu::viewPackages() {
    if (packages->empty()) {
        cout << "No packages to display.\n";
        return;
    }

    for (const auto& p : *packages) {
        p.displayInfo();
    }
}
