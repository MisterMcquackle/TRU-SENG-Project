#include "ImportMenu.h"
#include <iostream>
#include <algorithm>

using namespace std;

void ImportMenu::display() {
    int choice;
    do {
        cout << "\n\033[1;36m--- Import Management ---\033[0m\n";
        cout << "1. Add Import Record\n";
        cout << "2. View Import Records\n";
        cout << "3. Delete Import Record\n";
        cout << "4. Back to Main Menu\n";
        cout << "---------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addImportRecord(); break;
            case 2: viewImportRecords(); break;
            case 3: deleteImportRecord(); break;
            case 4: break;
            default:
                cout << "\033[1;31mInvalid choice!\033[0m\n";
                break;
        }
    } while (choice != 4);
}

void ImportMenu::addImportRecord() {
    string material;
    double quantity, cost;

    cin.ignore();
    cout << "Enter material name: ";
    getline(cin, material);

    cout << "Enter quantity (kg): ";
    cin >> quantity;

    cout << "Enter cost per kg: ";
    cin >> cost;

    importList->emplace_back(material, quantity, cost);
    cout << "\033[1;32mImport record added.\033[0m\n";
}

void ImportMenu::viewImportRecords() {
    if (importList->empty()) {
        cout << "\033[1;33mNo import records available.\033[0m\n";
        return;
    }

    for (const auto& record : *importList) {
        record.display();
    }
}

void ImportMenu::deleteImportRecord() {
    if (importList->empty()) {
        cout << "\033[1;33mNo import records to delete.\033[0m\n";
        return;
    }

    string name;
    cin.ignore();
    cout << "Enter material name to delete: ";
    getline(cin, name);

    auto it = remove_if(importList->begin(), importList->end(),
        [&](const Import& imp) {
            return imp.getMaterial() == name;
        });

    if (it != importList->end()) {
        importList->erase(it, importList->end());
        cout << "\033[1;32mRecord deleted.\033[0m\n";
    } else {
        cout << "\033[1;31mMaterial not found.\033[0m\n";
    }
}
