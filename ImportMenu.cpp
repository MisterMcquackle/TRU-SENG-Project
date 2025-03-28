// ===============================================
// TANK'S Distribution System
// Import Menu Implementation
// ===============================================

#include "ImportMenu.h"
#include <iostream>
#include <limits>

using namespace std;

void ImportMenu::display() {
    int choice;
    do {
        cout << "\n\033[1;36m--- Import Management ---\033[0m\n"
             << "1. Add Import Record\n"
             << "2. View Import Records\n"
             << "3. Update Import Record\n"
             << "4. Back to Main Menu\n"
             << "-------------------------\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addImportRecord(); break;
            case 2: viewImportRecords(); break;
            case 3: updateImportRecord(); break;
            case 4: break;
            default: cout << "\033[1;31mInvalid choice!\033[0m\n";
        }
    } while (choice != 4);
}

void ImportMenu::addImportRecord() {
    string record;
    cin.ignore();
    cout << "Enter import record details: ";
    getline(cin, record);
    importRecords.push_back(record);
    cout << "\033[1;32mRecord added.\033[0m\n";
}

void ImportMenu::viewImportRecords() {
    if (importRecords.empty()) {
        cout << "\033[1;31mNo import records available.\033[0m\n";
        return;
    }
    for (const auto& r : importRecords) {
        cout << "\033[1;36m- \033[0m" << r << "\n";
    }
}

void ImportMenu::updateImportRecord() {
    string oldRecord, newRecord;
    cin.ignore();
    cout << "Enter existing record to update: ";
    getline(cin, oldRecord);

    for (auto& r : importRecords) {
        if (r == oldRecord) {
            cout << "Enter updated details: ";
            getline(cin, newRecord);
            r = newRecord;
            cout << "\033[1;32mRecord updated.\033[0m\n";
            return;
        }
    }
    cout << "\033[1;31mRecord not found.\033[0m\n";
}
