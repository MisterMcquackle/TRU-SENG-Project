// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>

using namespace std;

// Represents a delivery package with basic info
class Package {
private:
    string trackingNumber;
    string destination;
    double weight;
    string status;

public:
    // Constructor
    Package(const string& trackNum, const string& dest, double wt)
        : trackingNumber(trackNum), destination(dest), weight(wt), status("Pending") {}

    // Set the package's status
    void setStatus(const string& newStatus) {
        status = newStatus;
    }

    // Getters
    string getTrackingNumber() const {
        return trackingNumber;
    }

    string getDestination() const {
        return destination;
    }

    // Display formatted package info
    void displayInfo() const {
        cout << "\033[1;34mTracking Number:\033[0m " << trackingNumber << "\n"
             << "\033[1;34mDestination:\033[0m " << destination << "\n"
             << "\033[1;34mWeight:\033[0m " << weight << " kg\n"
             << "\033[1;34mStatus:\033[0m " << status << "\n";
    }
};

#endif
