#include "PackageMenu.h"
#include <iostream>
#include <algorithm>

using namespace std;

void PackageMenu::display() {
    int choice;
    do {
        cout << "\n\033[1;33m--- Package Management ---\033[0m\n";
        cout << "1. Add New Package\n";
        cout << "2. View All Packages\n";
        cout << "3. Edit a Package\n";
        cout << "4. Delete a Package\n";
        cout << "5. Back to Main Menu\n";
        cout << "--------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPackage(); break;
            case 2: viewPackages(); break;
            case 3: editPackage(); break;
            case 4: deletePackage(); break;
            case 5: break;
            default:
                cout << "\033[1;31mInvalid choice!\033[0m\n";
                break;
        }
    } while (choice != 5);
}

void PackageMenu::addPackage() {
    string track, destination, status;
    double weight;

    cin.ignore();
    cout << "Enter tracking number: ";
    getline(cin, track);

    cout << "Enter destination: ";
    getline(cin, destination);

    cout << "Enter weight (kg): ";
    cin >> weight;
    cin.ignore();

    cout << "Enter status: ";
    getline(cin, status);

    Package p(track, destination, weight);
    p.setStatus(status);
    packages->push_back(p);

    cout << "Package added successfully.\n";
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

void PackageMenu::editPackage() {
    string track;
    cin.ignore();
    cout << "Enter tracking number of package to edit: ";
    getline(cin, track);

    for (auto& p : *packages) {
        if (p.getTrackingNumber() == track) {
            string newDest, newStatus;
            double newWeight;

            cout << "Enter new destination: ";
            getline(cin, newDest);
            cout << "Enter new weight: ";
            cin >> newWeight;
            cin.ignore();
            cout << "Enter new status: ";
            getline(cin, newStatus);

            p = Package(track, newDest, newWeight);
            p.setStatus(newStatus);
            cout << "Package updated successfully.\n";
            return;
        }
    }

    cout << "Package not found.\n";
}

void PackageMenu::deletePackage() {
    string track;
    cin.ignore();
    cout << "Enter tracking number of package to delete: ";
    getline(cin, track);

    auto it = remove_if(packages->begin(), packages->end(),
        [&](const Package& p) {
            return p.getTrackingNumber() == track;
        });

    if (it != packages->end()) {
        packages->erase(it, packages->end());
        cout << "Package deleted successfully.\n";
    } else {
        cout << "Package not found.\n";
    }
}
