#ifndef MENU_LIST_HPP
#define MENU_LIST_HPP

#include <array>

#include "screen/menu.hpp"

enum MENU_LIST {
    MAIN,
    OPTIONS, 
    PLAY,

    MENU_COUNT
};

class MenuList {
private:
    std::array<Menu, MENU_LIST::MENU_COUNT> list;
    std::size_t currentMenu = MENU_LIST::MAIN;

    // TODO: add auto code generation
    void ToMain()     {currentMenu = MENU_LIST::MAIN;}
    void ToOptinons() {currentMenu = MENU_LIST::OPTIONS;}
    void ToPlay()     {currentMenu = MENU_LIST::PLAY;}

public: 
    MenuList();
    
    ftxui::Component Rendering();
};

#endif // MENU_LIST_HPP/