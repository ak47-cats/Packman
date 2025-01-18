#include <iostream>

#include "menu.hpp"

void Menu::Draw() {
    for (size_t i = 0; i < currentButton_; i++)
        std::cout << "[-] " << buttons_[i].GetName() << std::endl;

    std::cout << "[X] " << buttons_[currentButton_].GetName() << std::endl;

    for (size_t i = currentButton_ + 1; i < buttonCount_; i++)
        std::cout << "[-] " << buttons_[i].GetName() << std::endl;
}

void Menu::ChooseButton() {
    const char UP     = 'w';
    const char DOWN   = 's';
    const char CHOICE = '\n';
    
    char userAction;

    while(true) {
        Draw();
        userAction = std::cin.get();
        switch (userAction) {
            case UP:
                currentButton_ = (currentButton_ + 1) % buttonCount_;
                break;

            case DOWN:
                currentButton_ = (currentButton_ - 1) % buttonCount_;
                break;

            case CHOICE:
                buttons_[currentButton_].Callback();
                return;
        }
    }
}