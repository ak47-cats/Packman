#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include <concepts>
 
#include "ftxui/component/component.hpp"
#include "ftxui/dom/elements.hpp"

class ButtonInterface {
    public:
        std::string name;
        std::function<void ()> Callback;

        ButtonInterface(std::string name, std::function<void ()> Callback);
    };

ftxui::ButtonOption DefaultStyle();

template<typename T>
concept IsButtonInterface = std::is_same_v<ButtonInterface, T>;

class Menu {
private:
    std::string name;
    ftxui::Component buttons;
    ftxui::Component rendering;

    void SetRendering();

public:
    Menu() {} 

    template<IsButtonInterface ... Buttons>
    Menu(std::string name, Buttons ... buttons): name(name) {
        int column = 0;
        this->buttons = ftxui::Container::Vertical({
            (ftxui::Container::Horizontal({ftxui::Button(buttons.name, 
                                                         buttons.Callback,
                                                         DefaultStyle())}, &column) | ftxui::flex) ...});

        SetRendering();
    }

    ftxui::Component Rendering();
};

#endif // MENU_HPP
