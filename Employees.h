// ===============================================
// TANK'S Distribution System
// Employee Class
// ===============================================

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

class Employee {
private:
    std::string name;
    double payperHR;
    std::string job;
    std::string schedule[7];

    const std::string positions[5] = {"Shelf Stocker", "Reception", "Delivery", "Manager", "Temp"};
    const std::string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

public:
    // Default Constructor
    Employee() : name(""), payperHR(0.0), job("Unassigned") {
        for (auto& s : schedule) s = "Off";
    }

    // Parameterized Constructor
    Employee(const std::string& setname, int setposition, double setpayperHR) {
        name = setname;
        job = positions[std::clamp(setposition, 0, 4)];
        payperHR = setpayperHR;
        for (auto& s : schedule) s = "Off";
    }

    // Set hourly wage
    void wagechange(double newpayperHR) {
        payperHR = newpayperHR;
    }

    // Get hourly wage
    double getpayperHR() const {
        return payperHR;
    }

    // Estimate annual salary
    double getsalary() const {
        return (payperHR * 40.0) * 52.143;
    }

    // Get name
    std::string getname() const {
        return name;
    }

    // Get job title
    std::string getjob() const {
        return job;
    }

    // Translate schedule to time blocks
    std::string shiftToHRs(int day) const {
        if (schedule[day] == "Day" || schedule[day] == "day")
            return "6:00am - 2:00pm";
        else if (schedule[day] == "Night" || schedule[day] == "night")
            return "2:00pm - 10:00pm";
        else
            return "Off";
    }

    // Set weekly schedule for an employee
    void setschedule(const std::string& employeeName) {
        int totalHours = 0;
        std::cout << "\033[1;36m" << employeeName << "'s Schedule Setup:\033[0m\n";
        for (int i = 0; i < 7; ++i) {
            std::string work;
            while (true) {
                std::cout << days[i] << " (Day / Night / Off): ";
                std::cin >> work;
                std::transform(work.begin(), work.end(), work.begin(), ::tolower);
                if (work == "day" || work == "night" || work == "off") {
                    schedule[i] = work;
                    if (work != "off") totalHours += 8;
                    break;
                } else {
                    std::cout << "\033[1;31mInvalid input. Please type Day, Night or Off.\033[0m\n";
                }
            }
            if (totalHours >= 40) {
                std::cout << "\033[1;33m40 hours reached. No more shifts will be assigned.\033[0m\n";
                break;
            }
        }
    }

    // Display the employee's schedule
    void displayschedule() const {
        for (int i = 0; i < 7; ++i) {
            std::cout << std::setw(10) << std::left << days[i] << ": " << shiftToHRs(i) << "\n";
        }
    }

    // Display all employee info
    void displayInfo() const {
        std::cout << "\n\033[1;34m--- Employee Info ---\033[0m\n";
        std::cout << "Name     : " << getname() << "\n";
        std::cout << "Position : " << getjob() << "\n";
        std::cout << "Schedule :\n";
        displayschedule();
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Hourly Wage : $" << getpayperHR() << "\n";
        std::cout << "Est. Salary : $" << getsalary() << "\n";
        std::cout << "---------------------------\n";
    }
};

#endif
