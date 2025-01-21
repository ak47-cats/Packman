#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <termios.h>

class TerminalConfig {
private:
    termios oldTermios;
    termios newTermios;

public:
    TerminalConfig();

    void Enable();
    void Disable();
};

#endif // CONFIG_HPP