#ifndef IMPORT_H
#define IMPORT_H

#include <string>
#include <iostream>

class Import {
private:
    std::string material;
    double quantityKg;
    double costPerKg;

public:
    Import(const std::string& material, double quantity, double cost)
        : material(material), quantityKg(quantity), costPerKg(cost) {}

    std::string getMaterial() const { return material; }
    double getQuantity() const { return quantityKg; }
    double getCostPerKg() const { return costPerKg; }
    double getTotalCost() const { return quantityKg * costPerKg; }

    void display() const {
        std::cout << "\033[1;34mMaterial:\033[0m " << material
                  << "\n\033[1;34mQuantity:\033[0m " << quantityKg << " kg"
                  << "\n\033[1;34mCost per Kg:\033[0m $" << costPerKg
                  << "\n\033[1;34mTotal Cost:\033[0m $" << getTotalCost()
                  << "\n-------------------------\n";
    }
};

#endif
