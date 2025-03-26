// ===============================================
// TANK'S Distribution System
// Settings Menu Interface
// ===============================================

#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include "Menu.h"

class SettingsMenu : public Menu {
public:
    void display() override;

private:
    void changeTheme(); // Example setting
};

#endif
