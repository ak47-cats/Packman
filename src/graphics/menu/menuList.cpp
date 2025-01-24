#include <iostream>

#include "menuList.hpp"
#include "map.hpp"
#include "packman.hpp"
#include "client.hpp"

namespace MainMenu {
    void Play() {
        // Map map(Packman(Position(1, 1), Icon('@')));
        // map.Show();

        Client client;
        if (!client.IsValid()) {
            std::cout << "Client is invalid" << std::endl;
            return;
        }
        client.Play();
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