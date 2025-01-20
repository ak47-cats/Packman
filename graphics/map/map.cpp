#include <iostream>
#include <cstring>

#include "map.hpp"
#include "timer.hpp"

void Map::Draw() { // TODO: it's govno
    const size_t memorySize = fieldSizeY * (fieldSizeX + 1); // +1 for \n
    char field[memorySize];

    memset(field, '~', memorySize);
    for (size_t i = 1; i <= fieldSizeY; i++)
        field[(fieldSizeX + 1) * i - 1] = '\n';

    field[(fieldSizeX + 1) * characters_[0].position_.y_ + characters_[0].position_.x_] = 
                                                                characters_[0].GetIcon().symbol_;
    
    fwrite(field, sizeof(char), memorySize, stdout);
}

void Map::Show() {
    const int ticTime = 500;
    int times = 50; // TODO: there should be exit system
    while(times-- > 0) {
        Timer timer(ticTime);
        Character* character = &characters_[0];

        while (!timer.IsTimeOut())
            character->ProcessEvent();
        
        Draw();

        switch (character->GetDirection()) {
            case Direction::UP:
                character->position_.y_ = (character->position_.y_ + fieldSizeY - 1) % fieldSizeY;
                break;

            case Direction::DOWN:
                character->position_.y_ = (character->position_.y_ + fieldSizeY + 1) % fieldSizeY;
                break;

            case Direction::LEFT:
                character->position_.x_ = (character->position_.x_ + fieldSizeX + 1) % fieldSizeX;
                break;

            case Direction::RIGHT:
                character->position_.x_ = (character->position_.x_ + fieldSizeX - 1) % fieldSizeX;
                break;
        }
    }
}