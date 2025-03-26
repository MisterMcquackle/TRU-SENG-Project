// ===============================================
// TANK'S Distribution System
// Employee Menu Implementation
// ===============================================

#include "EmployeeMenu.h"
#include <iostream>
#include <limits>

void EmployeeMenu::display() {
    int choice;
    do {
        // Display the employee management menu with color
        std::cout << "\n\033[1;33m--- Employee Management ---\033[0m\n"
                  << "1. Add New Employee\n"
                  << "2. View Employee List\n"
                  << "3. Update Employee Information\n"
                  << "4. Delete Employee\n"
                  << "5. Back to Main Menu\n"
                  << "---------------------------\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        // Handle user choice
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: updateEmployee(); break;
            case 4: deleteEmployee(); break;
            case 5: std::cout << "Returning to main menu...\n"; break;
            default: std::cout << "\033[1;31mInvalid choice!\033[0m Please enter a number between 1 and 5.\n"; break;
        }
    } while (choice != 5);
}

void EmployeeMenu::addEmployee() {
    std::string name, position;
    double hourlyRate;

    // Input employee details
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::cout << "Enter employee name: ";
    std::getline(std::cin, name);
    std::cout << "Enter position: ";
    std::getline(std::cin, position);
    std::cout << "Enter hourly rate: ";
    std::cin >> hourlyRate;

    // Create and add new employee
    employees.emplace_back(name, position, hourlyRate);
    std::cout << "\033[1;32mEmployee added successfully!\033[0m\n";
}

void EmployeeMenu::viewEmployees() const {
    if (employees.empty()) {
        std::cout << "\033[1;31mNo employees to display.\033[0m\n";
        return;
    }

    // Display all employees
    for (const auto& emp : employees) {
        emp.displayInfo();
        std::cout << "-----------------------\n";
    }
}

void EmployeeMenu::updateEmployee() {
    std::string searchName;
    std::cout << "Enter the name of the employee to update: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::getline(std::cin, searchName);

    // Find and update employee
    for (auto& emp : employees) {
        if (emp.getName() == searchName) {
            double newRate;
            std::cout << "Enter new hourly rate: ";
            std::cin >> newRate;
            emp.setHourlyRate(newRate);
            std::cout << "\033[1;32mHourly rate updated!\033[0m\n";
            return;
        }
    }
    std::cout << "\033[1;31mEmployee not found.\033[0m\n";
}

void EmployeeMenu::deleteEmployee() {
    std::string searchName;
    std::cout << "Enter the name of the employee to delete: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::getline(std::cin, searchName);

    // Find and delete employee
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->getName() == searchName) {
            employees.erase(it);
            std::cout << "\033[1;32mEmployee deleted.\033[0m\n";
            return;
        }
    }
    std::cout << "\033[1;31mEmployee not found.\033[0m\n";
}
