#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <cstddef>
#include <cassert>

using ButtonCallback = void (*)();

class Button {
private:
    ButtonCallback Callback_;
    std::string name_;

public:
    Button(std::string name, ButtonCallback Callback): name_(name), Callback_(Callback) {};

    std::string GetName() const {
        return name_;
    }

    void Callback() const {
        Callback_();
    }
};


class Menu {
private:
    const size_t buttonCount_;
    static const size_t maxButtonCount_ = 10;
    size_t currentButton_ = 0;
    Button buttons_[maxButtonCount_];

    void Draw();

public:
    template<typename ... Buttons>
    Menu(size_t buttonCount, Buttons ... buttons): buttonCount_(buttonCount), buttons_(buttons ...) {
        // assert(sizeof...(Buttons) == buttonCount_); // TODO: make asserts befor initing 
        // assert(buttonCount_ <= maxButtonCount_); 
    }; 

    void ChooseButton();
};

#endif // MENU_HPP