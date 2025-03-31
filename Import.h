// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#ifndef IMPORT_H
#define IMPORT_H

#include <string>
#include <iostream>

// Represents a single material import record
class Import {
private:
    std::string material;   // Material name (e.g., Steel, Plastic)
    double quantityKg;      // Quantity in kilograms
    double costPerKg;       // Price per kilogram

public:
    // Constructor with values for each field
    Import(const std::string& material, double quantity, double cost)
        : material(material), quantityKg(quantity), costPerKg(cost) {}

    // Getters
    std::string getMaterial() const { return material; }
    double getQuantity() const { return quantityKg; }
    double getCostPerKg() const { return costPerKg; }

    // Calculate the total cost of the import
    double getTotalCost() const { return quantityKg * costPerKg; }

    // Nicely formatted console output
    void display() const {
        std::cout << "\033[1;34mMaterial:\033[0m " << material
                  << "\n\033[1;34mQuantity:\033[0m " << quantityKg << " kg"
                  << "\n\033[1;34mCost per Kg:\033[0m $" << costPerKg
                  << "\n\033[1;34mTotal Cost:\033[0m $" << getTotalCost()
                  << "\n--------------------------------\n";
    }
};

#endif
