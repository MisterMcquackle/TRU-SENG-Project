#include <iostream>
#include "Employee.h"
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

vector<string> Employees;
vector<shared_ptr<Employee>> E;

void displayEmployees(){
    cout << "Employees: " << endl;
    for (string employee : Employees){
        cout << employee << endl;
    }
}

void selectEmployee(string name){
    bool found = false;
    for (const auto& nom : E){
        if (nom->name == name){
            nom->displayInfo();
            found = true;
        }
    }
    if (!found){
        cout << name << " is not an employee" << endl;
    }
}

void scheduleSet(string name){
    bool found = false;
    for (const auto& nom : E){
        if (nom->name == name){
            nom->setschedule(name);
            found = true;
        }
    }
    if (!found){
        cout << name << " is not an employee" << endl;
    }
}

void hireEmployee(string name, int pos, int wage){
    cout << name << " has been hired" << endl;
    for (int i = 0; i < Employees.size(); i++){  
        if (Employees[i].empty()){
            Employees[i] = name;
            E.push_back(make_shared<Employee>(name, pos, wage));
            return;
        }
    }
    E.push_back(make_shared<Employee>(name, pos, wage));
    Employees.push_back(name);
}

void fireEmployee(string name){
    for (int i = 0; i < Employees.size(); i++){
       if (Employees[i] == name){
            Employees[i].clear();
       }
    }

    auto it = remove_if(E.begin(), E.end(), [&](const shared_ptr<Employee>& emp){
        return emp->name == name;
    });

    if (it != E.end()) {
        E.erase(it, E.end());
        cout << name << " has been fired" << endl;
    } 
    else {
        cout << name << " is not an employee" << endl;
    }
}

void changewage(string name, int wagechange){
    for (const auto& nom : E){
        if (nom->name == name){
            nom->wagechange(wagechange);
        }
    }
}
