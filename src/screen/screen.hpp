#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "ftxui/screen/screen.hpp"  // for Screen
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include <iostream>

class Screen {
    ftxui::Dimensions terminalSize = ftxui::Terminal::Size();
    ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::FixedSize(terminalSize.dimx, terminalSize.dimy);

public:
    void Show() {
    }
};

#endif // SCREEN_HPP