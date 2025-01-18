#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <cstddef>

using ButtonCallback = void (*)();

class Button {
private:
    ButtonCallback Callback_;
    std::string name_;

public:
    Button(std::string name, ButtonCallback Callback): name_(name), Callback_(Callback) {};

    std::string GetName() {
        return name_;
    }

    void Callback() {
        Callback_();
    }
};


class Menu {
private:
    const size_t buttonCount_;
    static const size_t maxButtonCount_ = 10;
    size_t currentButton_ = 0;
    Button buttons_[maxButtonCount_];

public:
    Menu(size_t buttonCount); // i need to make variadic parameters of this constructor
                              // because i should init buttons
    void ChooseButton();
};

#endif // MENU_HPP