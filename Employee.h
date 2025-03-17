#include <iostream>
#include <string>
using namespace std;

class Employee {
    public:
    string name;
    double payperHR;
    const string position[5] = {"Shelf Stocker", "Reception", "Delivery", "Manager", "temp"};
    string job;
    string schedule[7] = {};
    const string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};


    Employee(){
        name = "";
        position[1];
        payperHR = 0.0;
    }

    Employee(string setname, int setposition, double setpayperHR){
        name = setname;
        job = position[setposition];
        payperHR = setpayperHR;
    }

    void wagechange(double newpayperHR){
        payperHR = newpayperHR;
    }

    double getpayperHR(){
        return payperHR;
    }

    double getsalary(){
        double salary = (payperHR*40)*52.143;
        return salary;
    }

    string getname(){
        return name;
    }

    string getjob(){
        return job;
    }

    

    string shiftToHRs(int day){
        if (schedule[day] == "Day" || schedule[day] == "day"){
            return "6:00am-2:00pm";
        }
        if (schedule[day] == "Night" || schedule[day] == "night"){
            return "2:00pm-10:00pm";
        }
        else{
            return "off work";
        }
    }

    void setschedule(string name){
        int HRs = 0;
        cout << name << "'s schedule: " << endl;
        for (int day = 1; day <= 7; day++){
            retype:
            cout << days[day - 1] << " (Night or Day shift or Off work): ";
            string work;
            cin >> work;
        
            if (work == "night" || work == "Night" || work == "day" || work == "Day" || work == "off" || work == "Off"){
                schedule[day] = work;
                if (work == "night" || work == "Night" || work == "day" || work == "Day"){
                    HRs += 8;
                }
            }
            else{
                cout << "\ntype Day or Night or Off\n";
                goto retype;
            } 

            if (HRs == 40){
                cout << "Max hours assigned\n";
                break;
            }
        }  
    }

    void displayschedule(){
        cout << "Monday: " << shiftToHRs(1) << endl;
        for (int day = 2; day <= 7; day++){
            cout << days[day - 1] << ": " << shiftToHRs(day) << endl;
        }
    }

    void displayInfo(){
        cout << endl;
        cout << getname() << " info:" << endl;
        cout << "Position: " << getjob() << endl;
        cout << "Schedule: " << endl;
        displayschedule();
        cout << "Hourly wage: $" << getpayperHR() << endl;
        cout << "Annual salary: $" << getsalary() << endl;
    }
};
