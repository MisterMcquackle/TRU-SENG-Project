// ===============================================
// TANK'S Distribution System
// Import Menu Implementation
// ===============================================

#include "ImportMenu.h"
#include <iostream>
#include <limits>

void ImportMenu::display() {
    int choice;
    do {
        std::cout << "\n\033[1;36m--- Import Management ---\033[0m\n"
                  << "1. Add Import Record\n"
                  << "2. View Import Records\n"
                  << "3. Update Import Record\n"
                  << "4. Back to Main Menu\n"
                  << "--------------------------\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addImportRecord(); break;
            case 2: viewImportRecords(); break;
            case 3: updateImportRecord(); break;
            case 4: break;
            default: std::cout << "\033[1;31mInvalid choice!\033[0m\n";
        }
    } while (choice != 4);
}

void ImportMenu::addImportRecord() {
    std::string record;
    std::cin.ignore();
    std::cout << "Enter import record details: ";
    std::getline(std::cin, record);
    importRecords.push_back(record);
    std::cout << "\033[1;32mRecord added.\033[0m\n";
}

void ImportMenu::viewImportRecords() {
    if (importRecords.empty()) {
        std::cout << "\033[1;31mNo import records available.\033[0m\n";
        return;
    }
    for (const auto& r : importRecords) {
        std::cout << "\033[1;36m- \033[0m" << r << "\n";
    }
}

void ImportMenu::updateImportRecord() {
    std::string oldRecord, newRecord;
    std::cin.ignore();
    std::cout << "Enter existing record to update: ";
    std::getline(std::cin, oldRecord);

    for (auto& r : importRecords) {
        if (r == oldRecord) {
            std::cout << "Enter updated details: ";
            std::getline(std::cin, newRecord);
            r = newRecord;
            std::cout << "\033[1;32mRecord updated.\033[0m\n";
            return;
        }
    }
    std::cout << "\033[1;31mRecord not found.\033[0m\n";
}
