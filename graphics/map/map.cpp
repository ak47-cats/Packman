#include <iostream>
#include <cstring>

#include "map.hpp"

void Map::Draw() { // TODO: it's govno
    const size_t fieldSizeX = 40;
    const size_t fieldSizeY = 20;
    const size_t memorySize = fieldSizeY * (fieldSizeX + 1); // +1 for \n
    char field[memorySize];

    memset(field, '~', memorySize);
    for (size_t i = 1; i <= fieldSizeY; i++)
        field[(fieldSizeX + 1) * i - 1] = '\n';

    Position position = characters_[0].GetPosition();
    field[(fieldSizeX + 1) * position.y_ + position.x_] = characters_[0].GetIcon().symbol_;
    
    fwrite(field, sizeof(char), memorySize, stdout);
}

void Map::Show() {

}