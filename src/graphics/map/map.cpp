#include <iostream>
#include <cstring>

#include "map.hpp"
#include "timer.hpp"

void Map::Draw() { // TODO: it's govno
    #define memorySize fieldSizeY * (fieldSizeX + 1) // +1 for \n // TODO: kill define
    char field[memorySize];

    std::cout << "\033[2J\033[1;1H"; // ANSI Escape Codes для очистки экрана и перемещения курсора 
                                   //                                         в верхний левый угол

    memset(field, '~', memorySize);
    for (size_t i = 1; i <= fieldSizeY; i++)
        field[(fieldSizeX + 1) * i - 1] = '\n';

    field[(fieldSizeX + 1) * character_.position_.y_ + character_.position_.x_] = 
                                                                character_.GetIcon().symbol_;
    
    fwrite(field, sizeof(char), memorySize, stdout);
}

void Map::Show() {
    const int ticTime = 50;
    int times = 500; // TODO: there should be exit system
    while(times-- > 0) {
        Timer timer(ticTime);
        timer.Start();

        while (!timer.IsTimeOut())
            character_.ProcessEvent();
        
        Draw();

        switch (character_.GetDirection()) {
            case Direction::UP:
                character_.position_.y_ = (character_.position_.y_ + fieldSizeY - 1) % fieldSizeY;
                break;

            case Direction::DOWN:
                character_.position_.y_ = (character_.position_.y_ + fieldSizeY + 1) % fieldSizeY;
                break;

            case Direction::LEFT:
                character_.position_.x_ = (character_.position_.x_ + fieldSizeX - 1) % fieldSizeX;
                break;

            case Direction::RIGHT:
                character_.position_.x_ = (character_.position_.x_ + fieldSizeX + 1) % fieldSizeX;
                break;
        }
    }
}