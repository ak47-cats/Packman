#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>
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
    // static const size_t maxButtonCount_ = 10;
    size_t currentButton_ = 0;
    std::vector<Button> buttons_; // NOTE: vector may be changed to something static
    // Button buttons_[maxButtonCount_];

    void Draw();

public:
    template<typename ... Buttons>
    Menu(size_t buttonCount, Buttons ... buttons): buttonCount_(buttonCount)/* , buttons_(buttons ...) */{
        // assert(sizeof...(Buttons) == buttonCount_); // TODO: make asserts befor initing 
        // assert(buttonCount_ <= maxButtonCount_); 
        buttons_ = {buttons ...};
    }; 

    void ChooseButton();
};

#endif // MENU_HPP