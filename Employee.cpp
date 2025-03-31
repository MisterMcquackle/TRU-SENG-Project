// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#include "Employee.h"
using namespace std;

// Static: Possible job titles
const array<string, 5> Employee::positions = {
    "Shelf Stocker", "Reception", "Delivery", "Manager", "Temp"
};

// Static: Days of the week
const array<string, 7> Employee::days = {
    "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

// Default constructor: uninitialized employee
Employee::Employee() : name(""), jobTitle("Unassigned"), hourlyRate(0.0) {
    schedule.fill("Off");
}

// Parameterized constructor
Employee::Employee(const string& name, const string& jobTitle, double hourlyRate)
    : name(name), jobTitle(jobTitle), hourlyRate(hourlyRate) {
    schedule.fill("Off");
}

// Manual schedule entry from user input
void Employee::setSchedule() {
    cout << "\033[1;36mEnter schedule for each day (Off / Day / Night):\033[0m\n";
    for (int i = 0; i < 7; ++i) {
        cout << "\033[1;34m" << days[i] << ":\033[0m ";
        cin >> schedule[i];
    }
}

// Set a specific day’s schedule (used for random generation)
void Employee::setScheduleDay(int dayIndex, const string& shift) {
    if (dayIndex >= 0 && dayIndex < 7) {
        schedule[dayIndex] = shift;
    }
}

// Display weekly schedule
void Employee::displaySchedule() const {
    for (int i = 0; i < 7; ++i) {
        cout << "\033[1;34m" << days[i] << ":\033[0m " << schedule[i] << "\n";
    }
}

// Display complete employee info
void Employee::displayInfo() const {
    cout << "\n\033[1;32m----- Employee Info -----\033[0m\n";
    cout << "\033[1;36mName       :\033[0m " << name << "\n";
    cout << "\033[1;36mPosition   :\033[0m " << jobTitle << "\n";
    cout << "\033[1;36mSchedule   :\033[0m\n";
    displaySchedule();
    cout << "\033[1;36mHourly Rate:\033[0m $" << hourlyRate << "\n";
    cout << "\033[1;36mEst. Salary:\033[0m $" << getSalary() << "\n";
    cout << "----------------------------\n";
}

// Getters
string Employee::getName() const { return name; }
string Employee::getJobTitle() const { return jobTitle; }
double Employee::getHourlyRate() const { return hourlyRate; }
double Employee::getSalary() const { return hourlyRate * 40.0 * 52.143; }  // Weekly * Weeks/year
