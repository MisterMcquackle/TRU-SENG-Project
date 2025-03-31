#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <array>
#include <iostream>

class Employee {
private:
    std::string name;
    std::string jobTitle;
    double hourlyRate;
    std::array<std::string, 7> schedule;

    static const std::array<std::string, 5> positions;
    static const std::array<std::string, 7> days;

public:
    Employee();
    Employee(const std::string& name, const std::string& jobTitle, double hourlyRate);

    void setSchedule();
    void setScheduleDay(int dayIndex, const std::string& shift); // <-- new method
    void displaySchedule() const;
    void displayInfo() const;

    std::string getName() const;
    std::string getJobTitle() const;
    double getHourlyRate() const;
    double getSalary() const;
};

#endif
