#include "menu.hpp"

namespace MainMenu {
    void Play();
    void Options();
    void Exit();

    class MainMenu {
    private:
        Menu menu;

    public:
        MainMenu();

        void Open();
    };
}

class MenuList {
public: 
    MainMenu::MainMenu mainMenu;
};