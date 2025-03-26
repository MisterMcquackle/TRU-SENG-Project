#ifndef MENU_H
#define MENU_H

class Menu {
public:
    virtual void display() = 0; // Pure virtual function
    virtual ~Menu() {}          // Virtual destructor
};

#endif // MENU_H
