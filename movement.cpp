#include <iostream>
#include <cstddef>
#include <cstring>
#include <termios.h>
#include <unistd.h>

#include "menu/menu.hpp"

class Position {
public:
    size_t x_;
    size_t y_;

    Position(size_t x, size_t y): x_(x), y_(y) {};
};

class Packman {
private:
    Position position;
public:
    Packman(size_t x, size_t y): position(x, y) {};

private:
    bool DoStep() {
        char nextStep = std::cin.get();
        switch (nextStep)
        {
            case 'w':
                this->position.y_ -= 1;
                return true;
            
            case 's':
                this->position.y_ += 1;
                return true;

            case 'd':
                this->position.x_ += 1;
                return true;;

            case 'a':
                this->position.x_ -= 1;
                return true;;

            case ' ':
                return false;
            
            default:
                return false;
        }
    }

// GPT's realization
    void EnableEcho(termios* orig) { 
        tcsetattr(STDIN_FILENO, TCSAFLUSH, orig);
    } 

// GPT's realization
    void DisableEcho(termios* orig) {
        struct termios newTermios;

        // Получаем текущие настройки терминала
        tcgetattr(STDIN_FILENO, orig);
        newTermios = *orig;

        // Отключаем эхо
        newTermios.c_lflag &= ~(ICANON | ECHO);

        // Применяем новые настройки
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &newTermios);
    }

    void Draw() {
        const size_t fieldSizeX = 40;
        const size_t fieldSizeY = 20;
        const size_t memorySize = fieldSizeY * (fieldSizeX + 1); // +1 for \n
        char field[memorySize];

        memset(field, '~', memorySize);
        for (size_t i = 1; i <= fieldSizeY; i++)
            field[(fieldSizeX + 1) * i - 1] = '\n';

        field[(fieldSizeX + 1) * this->position.y_ + this->position.x_] = '@';

        fwrite(field, sizeof(char), memorySize, stdout);
    }

public:
    void MoveAndDraw() {
        struct termios orig;
        this->DisableEcho(&orig);

        while (true) {
            if (!this->DoStep())
                break;
            this->Draw();
        }

        this->EnableEcho(&orig);
    }
};

void Hello() {
    std::cout << "hello" << std::endl;
}

void Bye() {
    std::cout << "Bye" << std::endl;
}

int main() {
    Packman packman(1, 1);
    // packman.MoveAndDraw();

    Menu mainMenu = Menu(2, Button("Hello", Hello), Button("Bye", Bye));
    mainMenu.ChooseButton();

    return 0;
}
