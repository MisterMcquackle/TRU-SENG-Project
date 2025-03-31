// ###########################################
// #     TANK'S DISTRIBUTION SYSTEM          #
// #  2025 - 03 - 29 (Final Hotfix)          #
// #  Built By: Andrew, Davis, Kohen, Matteo #
// ###########################################

#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

// Abstract base class for all interactive menus
class Menu {
public:
    virtual ~Menu() = default;

    // Pure virtual method to be implemented by all derived menus
    virtual void display() = 0;
};

#endif
