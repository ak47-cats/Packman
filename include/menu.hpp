#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <cstring>
#include <vector>
#include <cstddef>
#include <cassert>

using ButtonCallback = void (*)();

class Button {
private:
    ButtonCallback Callback_;
    char name_[20]; // TODO: maybe string should be used

public:
    Button(const char* name, ButtonCallback Callback): Callback_(Callback) {
        memmove(name_, name, strlen(name)); // TODO: dangerous length, there can be overflow
    };

    std::string GetName() const {
        return std::string(name_);
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
    template <typename ... Buttons>
    Menu(size_t buttonCount, Buttons ... buttons): buttonCount_(buttonCount) {
        assert(sizeof...(Buttons) == buttonCount_); 
        buttons_ = {buttons ...};
    }

    void ChooseButton();
};

#endif // MENU_HPP