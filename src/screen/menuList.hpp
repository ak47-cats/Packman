#ifndef MENU_LIST_HPP
#define MENU_LIST_HPP

#include <array>

#include "screen/menu.hpp"

namespace MenuList {

enum MENU_LIST {
    MAIN,
    OPTIONS, 
    PLAY,

    MENU_COUNT
};

class MainMenu: public Menu {};
class OptionsMenu: public Menu {};
class PlayMenu: public Menu {};

class MenuList {
private:
    std::array<Menu, MENU_LIST::MENU_COUNT> list;
    std::size_t currentMenu = MENU_LIST::MAIN;

public: 
    MenuList();
};
}

#endif // MENU_LIST_HPP