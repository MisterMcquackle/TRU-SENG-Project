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

using namespace std;

class Employee {
private:
    string name;
    double payperHR;
    string job;
    string schedule[7];

    const string positions[5] = {"Shelf Stocker", "Reception", "Delivery", "Manager", "Temp"};
    const string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

public:
    Employee() : name(""), payperHR(0.0), job("Unassigned") {
        for (auto& s : schedule) s = "Off";
    }

    Employee(const string& setname, int setposition, double setpayperHR) {
        name = setname;
        job = positions[clamp(setposition, 0, 4)];
        payperHR = setpayperHR;
        for (auto& s : schedule) s = "Off";
    }

    void wagechange(double newpayperHR) { payperHR = newpayperHR; }

    double getpayperHR() const { return payperHR; }

    double getsalary() const { return (payperHR * 40.0) * 52.143; }

    string getname() const { return name; }

    string getjob() const { return job; }

    string shiftToHrs(int day) const {
        if (schedule[day] == "Day" || schedule[day] == "day")
            return "6:00am - 2:00pm";
        else if (schedule[day] == "Night" || schedule[day] == "night")
            return "2:00pm - 10:00pm";
        else
            return "Off";
    }

    void setschedule(const string& employeeName) {
        int totalHours = 0;
        cout << "\033[1;36m" << employeeName << "'s Schedule Setup:\033[0m\n";
        for (int i = 0; i < 7; ++i) {
            string work;
            while (true) {
                cout << days[i] << " (Day / Night / Off): ";
                cin >> work;
                transform(work.begin(), work.end(), work.begin(), ::tolower);
                if (work == "day" || work == "night" || work == "off") {
                    schedule[i] = work;
                    if (work != "off") totalHours += 8;
                    break;
                } else {
                    cout << "\033[1;31mInvalid input. Please type Day, Night or Off.\033[0m\n";
                }
            }
            if (totalHours >= 40) {
                cout << "\033[1;33m40 hours reached. No more shifts will be assigned.\033[0m\n";
                break;
            }
        }
    }

    void displayschedule() const {
        for (int i = 0; i < 7; ++i) {
            cout << setw(10) << left << days[i] << ": " << shiftToHrs(i) << "\n";
        }
    }

    void displayInfo() const {
        cout << "\n\033[1;34m--- Employee Info ---\033[0m\n";
        cout << "Name       : " << getname() << "\n";
        cout << "Position   : " << getjob() << "\n";
        cout << "Schedule   :\n";
        displayschedule();
        cout << fixed << setprecision(2);
        cout << "Hourly Wage: $" << getpayperHR() << "\n";
        cout << "Est. Salary: $" << getsalary() << "\n";
        cout << "----------------------\n";
    }
};

#endif
