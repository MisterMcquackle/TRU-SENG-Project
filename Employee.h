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
    static const string positions[5];
    static const string days[7];

public:
    Employee() : name(""), payperHR(0.0), job("Unassigned") {
        for (auto& s : schedule) s = "Off";
    }

    Employee(const string& setname, const string& setjob, double setpayperHR) {
        name = setname;
        job = validatePosition(setjob);
        payperHR = setpayperHR;
        for (auto& s : schedule) s = "Off";
    }

    static string validatePosition(const string& pos) {
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

    string getname() const { return name; }

    string getjob() const { return job; }

    void setschedule() {
        cout << "\n\033[1;36mEnter number of hours (0–8) for each day:\033[0m\n";
        int totalHours = 0;

        for (int i = 0; i < 7; ++i) {
            int hours = -1;
            while (true) {
                cout << days[i] << ": ";
                cin >> hours;

                if (cin.fail() || hours < 0 || hours > 8) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "✘ Please enter a valid number between 0 and 8.\n";
                } else {
                    break;
                }
            }

            schedule[i] = (hours == 0) ? "Off" : (hours <= 4 ? "Half Day" : "Full Day");
            totalHours += hours;

            if (totalHours >= 40) {
                cout << "✓ 40-hour limit reached. Remaining days set to Off.\n";
                for (int j = i + 1; j < 7; ++j) {
                    schedule[j] = "Off";
                }
                break;
            }
        }
    }

    void displayschedule() const {
        for (int i = 0; i < 7; ++i) {
            cout << setw(10) << left << days[i] << ": " << schedule[i] << "\n";
        }
    }

    void displayInfo() const {
        cout << "\n\033[1;34m--- Employee Info ---\033[0m\n";
        cout << "Name       : " << getname() << "\n";
        cout << "Position   : " << getjob() << "\n";
        cout << "Schedule  :\n";
        displayschedule();
        cout << fixed << setprecision(2);
        cout << "Hourly Wage : $" << getpayperHR() << "\n";
        cout << "Est. Salary : $" << getsalary() << "\n";
        cout << "----------------------\n";
    }
};

const string Employee::positions[5] = {
    "Shelf Stocker", "Reception", "Delivery", "Manager", "Temp"
};

const string Employee::days[7] = {
    "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

#endif
