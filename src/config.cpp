#include <unistd.h>
#include <iostream>

#include "config.hpp"

TerminalConfig::TerminalConfig() {
    tcgetattr(STDIN_FILENO, &oldTermios);
    newTermios = oldTermios;
}

void TerminalConfig::Enable() {
    newTermios.c_lflag &= ~(ICANON | ECHO); // Disable input bufferization and echo

    std::cout << "\033[?25l"; // Disable cursor

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &newTermios); // Enable new config
}

void TerminalConfig::Disable() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &oldTermios); // Enable old config

    std::cout << "\033[?25h"; // Enable cursor
}