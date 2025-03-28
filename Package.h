// ===============================================
// TANK'S Distribution System
// Package Class Header
// ===============================================

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>

using namespace std;

class Package {
private:
    string trackingNumber;
    string destination;
    double weight;
    string status;

public:
    Package(const string& trackNum, const string& dest, double wt)
        : trackingNumber(trackNum), destination(dest), weight(wt), status("Pending") {}

    void setStatus(const string& newStatus) {
        status = newStatus;
    }

    string getTrackingNumber() const {
        return trackingNumber;
    }

    void displayInfo() const {
        cout << "\033[1;34mTracking Number:\033[0m " << trackingNumber << "\n"
             << "\033[1;34mDestination:\033[0m " << destination << "\n"
             << "\033[1;34mWeight:\033[0m " << weight << " kg\n"
             << "\033[1;34mStatus:\033[0m " << status << "\n";
    }
};

#endif
