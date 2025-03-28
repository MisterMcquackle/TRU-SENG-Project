// ===============================================
// TANK'S Distribution System
// Package Menu Implementation
// ===============================================

#include "PackageMenu.h"
#include <iostream>
#include <limits>

using namespace std;

void PackageMenu::display() {
    int choice;
    do {
        cout << "\n\033[1;32m--- Package Management ---\033[0m\n"
             << "1. Add Package\n"
             << "2. View Packages\n"
             << "3. Update Package Status\n"
             << "4. Back to Main Menu\n"
             << "--------------------------\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPackage(); break;
            case 2: viewPackages(); break;
            case 3: updatePackageStatus(); break;
            case 4: cout << "Returning...\n"; break;
            default: cout << "\033[1;31mInvalid choice!\033[0m\n"; break;
        }
    } while (choice != 4);
}

void PackageMenu::addPackage() {
    string track, dest;
    double weight;
    cin.ignore();
    cout << "Enter tracking number: ";
    getline(cin, track);
    cout << "Enter destination: ";
    getline(cin, dest);
    cout << "Enter weight (kg): ";
    cin >> weight;

    packages.emplace_back(track, dest, weight);
    cout << "\033[1;32mPackage added.\033[0m\n";
}

void PackageMenu::viewPackages() {
    if (packages.empty()) {
        cout << "\033[1;31mNo packages available.\033[0m\n";
        return;
    }
    for (const auto& p : packages) {
        p.displayInfo();
        cout << "--------------------\n";
    }
}

void PackageMenu::updatePackageStatus() {
    string track;
    cin.ignore();
    cout << "Enter tracking number: ";
    getline(cin, track);

    for (auto& p : packages) {
        if (p.getTrackingNumber() == track) {
            string status;
            cout << "Enter new status (In Transit / Delivered): ";
            getline(cin, status);
            p.setStatus(status);
            cout << "\033[1;32mStatus updated.\033[0m\n";
            return;
        }
    }
    cout << "\033[1;31mPackage not found.\033[0m\n";
}
