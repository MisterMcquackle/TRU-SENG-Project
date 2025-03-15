#include <iostream>
#include "Employee.h"
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

int size;
vector<string> Employees;
vector<shared_ptr<Employee>> E;


void selectEmployee(string name){
    bool found = false;
    for (const auto& nom : E){
        if (nom->name == name){
            nom->displayInfo();
            found = true;
            break;
        }
    }
    if (!found){
        cout << "That person is not an employee" << endl;
    }
}

void hireEmployee(string name, int pos, int wage){
    for (int i = 0; i < Employees.size(); i++){  
        if (Employees[i].empty()){
            Employees[i] = name;
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

    auto it = remove_if(E.begin(), E.end(), [&](const shared_ptr<Employee>& emp) {
            return emp->name == name;
        });

    if (it != E.end()) {
        E.erase(it, E.end());
        cout << "Employee " << name << " has been removed." << endl;
    } else {
        cout << "That person is not an employee." << endl;
    }
}

