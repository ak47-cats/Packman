#include <iostream>

#include "menuList.hpp"

namespace MainMenu {
    void Play() {
        std::cout << "Play" << std::endl;
    }

    void Options() {
        std::cout << "Options" << std::endl;
    }

    void Exit() {
        std::cout << "Exit" << std::endl;
    }

    MainMenu::MainMenu(): menu(3, Button("Play",    Play),
                                  Button("Options", Options), 
                                  Button("Exit",    Exit)) {};

    void MainMenu::Open() {
        menu.ChooseButton();
    }
}