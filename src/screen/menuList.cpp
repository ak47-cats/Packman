#include "menuList.hpp"

#include <iostream>
#include "ftxui/screen/screen.hpp"  // for Screen
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive

// TODO: add auto code generation
MenuList::MenuList() {
    Menu main("Main menu",
              ButtonInterface("Play",    [] {std::cout << "aboba" << std::endl;}),
              ButtonInterface("Options", [] {std::cout << "lalal" << std::endl;}));

    Menu options("Options", 
                 ButtonInterface("Main", [&] {ToMain();}));

    Menu play("Play menu",
              ButtonInterface("Main", [&] {ToMain();}));

    list[MENU_LIST::MAIN]    = main;
    list[MENU_LIST::OPTIONS] = options;
    list[MENU_LIST::PLAY]    = play;
}

ftxui::Component MenuList::Rendering() {
    return list[MENU_LIST::MAIN].Rendering();
}