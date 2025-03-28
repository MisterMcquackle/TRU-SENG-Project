// ===============================================
// TANK'S Distribution System
// Base Menu Class
// ===============================================

#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

// Abstract base class for all menu types
class Menu {
public:
    virtual ~Menu() = default;
    virtual void display() = 0; // Pure virtual function for displaying the menu
};

#endif
