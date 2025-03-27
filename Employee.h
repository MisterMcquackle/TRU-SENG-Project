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
    static const std::string positions[5];
    static const std::string days[7];

public:
    Employee() : name(""), payperHR(0.0), job("Unassigned") {
        for (auto& s : schedule) s = "Off";
    }

    Employee(const std::string& setname, const std::string& setjob, double setpayperHR) {
        name = setname;
        job = validatePosition(setjob);
        payperHR = setpayperHR;
        for (auto& s : schedule) s = "Off";
    }

    static std::string validatePosition(const std::string& pos) {
        for (const auto& p : positions) {
            if (p == pos) return p;
        }
        return "Invalid";
    }

    void wagechange(double newpayperHR) {
        payperHR = newpayperHR;
    }

    double getpayperHR() const { return payperHR; }

    double getsalary() const { return (payperHR * 40.0) * 52.143; }

    std::string getname() const { return name; }

    std::string getjob() const { return job; }

    void setschedule() {
        std::cout << "\n\033[1;36mEnter number of hours (0–8) for each day:\033[0m\n";
        int totalHours = 0;

        for (int i = 0; i < 7; ++i) {
            int hours = -1;
            while (true) {
                std::cout << days[i] << ": ";
                std::cin >> hours;

                if (std::cin.fail() || hours < 0 || hours > 8) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "❌ Please enter a valid number between 0 and 8.\n";
                } else {
                    break;
                }
            }

            schedule[i] = (hours == 0) ? "Off" : (hours <= 4 ? "Half Day" : "Full Day");
            totalHours += hours;

            if (totalHours >= 40) {
                std::cout << "✅ 40-hour limit reached. Remaining days set to Off.\n";
                for (int j = i + 1; j < 7; ++j) {
                    schedule[j] = "Off";
                }
                break;
            }
        }
    }

    void displayschedule() const {
        for (int i = 0; i < 7; ++i) {
            std::cout << std::setw(10) << std::left << days[i] << ": " << schedule[i] << "\n";
        }
    }

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

const std::string Employee::positions[5] = {
    "Shelf Stocker", "Reception", "Delivery", "Manager", "Temp"
};

const std::string Employee::days[7] = {
    "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

#endif
