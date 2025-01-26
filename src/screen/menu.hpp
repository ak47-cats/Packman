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
public:
    ftxui::Component buttons;

public:
    template<IsButtonInterface ... Buttons>
    Menu(Buttons ... buttons) {
        int column = 0;
        this->buttons = ftxui::Container::Vertical({
            (ftxui::Container::Horizontal({ftxui::Button(buttons.name, 
                                                         buttons.Callback,
                                                         DefaultStyle())}, &column) | ftxui::flex) ...});
    }

    ftxui::Element Render();
};

#endif // MENU_HPP
