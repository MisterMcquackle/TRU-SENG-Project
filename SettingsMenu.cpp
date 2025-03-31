// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#include "SettingsMenu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Display the system settings menu
void SettingsMenu::display() {
    int choice;
    do {
        cout << "\n\033[1;31m--- System Settings ---\033[0m\n";
        cout << "1. Generate Random Test Data\n";
        cout << "2. Back to Main Menu\n";
        cout << "-------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: generateTestData(); break;
            case 2: break;
            default:
                cout << "\033[1;31mInvalid choice!\033[0m\n";
                break;
        }
    } while (choice != 2);
}

// Auto-generate test employees, packages, and imports
void SettingsMenu::generateTestData() {
    static const string names[] = {"Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Hank"};
    static const string jobs[] = {"Manager", "Clerk", "Driver", "IT Support", "Security"};
    static const string destinations[] = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix"};
    static const string shifts[] = {"Off", "Day", "Night"};
    static const string materials[] = {"Steel", "Plastic", "Aluminum", "Copper", "Glass", "Wood", "Rubber", "Cement", "Paper", "Oil"};

    srand(static_cast<unsigned>(time(nullptr)));

    // Generate employees
    for (int i = 0; i < 10; ++i) {
        string name = names[rand() % 8] + to_string(rand() % 100);
        string job = jobs[rand() % 5];
        double rate = 15.0 + (rand() % 2000) / 100.0;

        Employee e(name, job, rate);

        for (int d = 0; d < 7; ++d) {
            e.setScheduleDay(d, shifts[rand() % 3]);
        }

        employees->addEmployee(e);
    }

    // Generate packages
    for (int i = 0; i < 15; ++i) {
        string tracking = "PKG" + to_string(rand() % 10000 + 1000);
        string destination = destinations[rand() % 5];
        double weight = 0.5 + (rand() % 1000) / 10.0;

        Package p(tracking, destination, weight);
        packages->push_back(p);
    }

    // Generate imports
    for (int i = 0; i < 10; ++i) {
        string material = materials[i];  // use first 10 unique
        double quantity = 100 + (rand() % 500);          // 100-600 kg
        double costPerKg = 1.0 + (rand() % 1000) / 50.0;  // $1 - $21

        imports->emplace_back(material, quantity, costPerKg);
    }

    cout << "\033[1;32m10 random employees, 15 packages, and 10 import records generated.\033[0m\n";
}
