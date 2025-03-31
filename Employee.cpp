#include "Employee.h"
using namespace std;

const array<string, 5> Employee::positions = {
    "Shelf Stocker", "Reception", "Delivery", "Manager", "Temp"
};

const array<string, 7> Employee::days = {
    "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

Employee::Employee() : name(""), jobTitle("Unassigned"), hourlyRate(0.0) {
    schedule.fill("Off");
}

Employee::Employee(const string& name, const string& jobTitle, double hourlyRate)
    : name(name), jobTitle(jobTitle), hourlyRate(hourlyRate) {
    schedule.fill("Off");
}

void Employee::setSchedule() {
    cout << "Enter schedule for each day (Off / Day / Night):\n";
    for (int i = 0; i < 7; ++i) {
        cout << days[i] << ": ";
        cin >> schedule[i];
    }
}

void Employee::setScheduleDay(int dayIndex, const string& shift) {
    if (dayIndex >= 0 && dayIndex < 7) {
        schedule[dayIndex] = shift;
    }
}

void Employee::displaySchedule() const {
    for (int i = 0; i < 7; ++i) {
        cout << days[i] << ": " << schedule[i] << "\n";
    }
}

void Employee::displayInfo() const {
    cout << "---- Employee Info ----\n";
    cout << "Name       : " << name << "\n";
    cout << "Position   : " << jobTitle << "\n";
    cout << "Schedule   :\n";
    displaySchedule();
    cout << "Hourly Rate: $" << hourlyRate << "\n";
    cout << "Est. Salary: $" << getSalary() << "\n";
    cout << "------------------------\n";
}

string Employee::getName() const { return name; }
string Employee::getJobTitle() const { return jobTitle; }
double Employee::getHourlyRate() const { return hourlyRate; }
double Employee::getSalary() const { return hourlyRate * 40.0 * 52.143; }
