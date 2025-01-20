#ifndef MAP_HPP
#define MAP_HPP

#include <vector>

#include "packman.hpp"

class Map {
private:
    #define fieldSizeX 40 // TODO: kill define
    #define fieldSizeY 20
    Packman character_; // NOTE: vector can be changed to array

public:
    Map(Packman character): character_(character) {};

private:
    void Draw();

public:
    void Show();
};

#endif // MAP_HPP