// ===============================================
// TANK'S Distribution System
// Package Menu Implementation
// ===============================================

#include "PackageMenu.h"
#include <iostream>
#include <limits>

void PackageMenu::display() {
    int choice;
    do {
        std::cout << "\n\033[1;32m--- Package Management ---\033[0m\n"
                  << "1. Add Package\n"
                  << "2. View Packages\n"
                  << "3. Update Package Status\n"
                  << "4. Back to Main Menu\n"
                  << "---------------------------\n"
                  << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: addPackage(); break;
            case 2: viewPackages(); break;
            case 3: updatePackageStatus(); break;
            case 4: std::cout << "Returning...\n"; break;
            default: std::cout << "\033[1;31mInvalid choice!\033[0m\n"; break;
        }
    } while (choice != 4);
}

void PackageMenu::addPackage() {
    std::string track, dest;
    double weight;
    std::cin.ignore();
    std::cout << "Enter tracking number: ";
    std::getline(std::cin, track);
    std::cout << "Enter destination: ";
    std::getline(std::cin, dest);
    std::cout << "Enter weight (kg): ";
    std::cin >> weight;

    packages.emplace_back(track, dest, weight);
    std::cout << "\033[1;32mPackage added.\033[0m\n";
}

void PackageMenu::viewPackages() {
    if (packages.empty()) {
        std::cout << "\033[1;31mNo packages available.\033[0m\n";
        return;
    }
    for (const auto& p : packages) {
        p.displayInfo();
        std::cout << "--------------------\n";
    }
}

void PackageMenu::updatePackageStatus() {
    std::string track;
    std::cin.ignore();
    std::cout << "Enter tracking number: ";
    std::getline(std::cin, track);

    for (auto& p : packages) {
        if (p.getTrackingNumber() == track) {
            std::string status;
            std::cout << "Enter new status (In Transit / Delivered): ";
            std::getline(std::cin, status);
            p.setStatus(status);
            std::cout << "\033[1;32mStatus updated.\033[0m\n";
            return;
        }
    }
    std::cout << "\033[1;31mPackage not found.\033[0m\n";
}
