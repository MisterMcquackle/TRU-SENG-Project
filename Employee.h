// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <array>
#include <iostream>

// Represents a single Employee in the system
class Employee {
private:
    std::string name;
    std::string jobTitle;
    double hourlyRate;
    std::array<std::string, 7> schedule;  // Mon-Sun schedule

    // Predefined job positions and weekday labels
    static const std::array<std::string, 5> positions;
    static const std::array<std::string, 7> days;

public:
    // Constructors
    Employee();
    Employee(const std::string& name, const std::string& jobTitle, double hourlyRate);

    // Schedule management
    void setSchedule();                                      // Manual entry
    void setScheduleDay(int dayIndex, const std::string& shift);  // Set individual day

    // Output methods
    void displaySchedule() const;
    void displayInfo() const;

    // Getters
    std::string getName() const;
    std::string getJobTitle() const;
    double getHourlyRate() const;
    double getSalary() const; // Annual salary estimate
};

#endif
