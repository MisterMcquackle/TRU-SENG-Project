// ===============================================
// TANK'S Distribution System
// Employee Menu Implementation (Fixed)
// ===============================================

#include "EmployeeMenu.h"
#include <iostream>
#include <limits>

void EmployeeMenu::display() {
    int choice;
    do {
        std::cout << "\n\033[1;33m--- Employee Management ---\033[0m\n"
                  << "1. Add New Employee\n"
                  << "2. View Employee List\n"
                  << "3. Update Employee Information\n"
                  << "4. Delete Employee\n"
                  << "5. Back to Main Menu\n"
                  << "---------------------------\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: updateEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: std::cout << "Returning to main menu...\n"; break;
            default: std::cout << "\033[1;31mInvalid choice! Please enter a number between 1 and 5.\033[0m\n"; break;
        }
    } while (choice != 5);
}

void EmployeeMenu::addEmployee() {
    std::string name, position;
    double hourlyRate;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter employee name: ";
    std::getline(std::cin, name);
    std::cout << "Enter position (Shelf Stocker, Reception, Delivery, Manager, Temp): ";
    std::getline(std::cin, position);
    std::cout << "Enter hourly rate: ";
    std::cin >> hourlyRate;

    employees.emplace_back(name, position, hourlyRate);
    std::cout << "\033[1;32mEmployee added successfully!\033[0m\n";
}

void EmployeeMenu::viewEmployees() const {
    if (employees.empty()) {
        std::cout << "\033[1;31mNo employees to display.\033[0m\n";
        return;
    }

    for (const auto& emp : employees) {
        emp.displayInfo();
        std::cout << "-----------------------\n";
    }
}

void EmployeeMenu::updateEmployee() {
    std::string searchName;
    std::cout << "Enter the name of the employee to update: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, searchName);

    for (auto& emp : employees) {
        if (emp.getname() == searchName) {
            double newRate;
            std::cout << "Enter new hourly rate: ";
            std::cin >> newRate;
            emp.wagechange(newRate);
            std::cout << "\033[1;32mHourly rate updated!\033[0m\n";
            return;
        }
    }
    std::cout << "\033[1;31mEmployee not found.\033[0m\n";
}

void EmployeeMenu::deleteEmployee() {
    std::string searchName;
    std::cout << "Enter the name of the employee to delete: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, searchName);

    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->getname() == searchName) {
            employees.erase(it);
            std::cout << "\033[1;32mEmployee deleted.\033[0m\n";
            return;
        }
    }
    std::cout << "\033[1;31mEmployee not found.\033[0m\n";
}
