#include "config.hpp"
#include "menuList.hpp"

int main() {
    TerminalConfig terminalConfig;
    terminalConfig.Enable();

    MenuList menuList;
    menuList.mainMenu.Open();

    terminalConfig.Disable();
    return 0;
}