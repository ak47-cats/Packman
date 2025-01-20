#ifndef MAP_HPP
#define MAP_HPP

#include <vector>

#include "character.hpp"

class Position {
public:
	int x_;
	int y_;

	Position(int x, int y): x_(x), y_(y) {};
};

enum Direction { // NOTE: can be optimized with map
    UP    = 'w',
    DOWN  = 's',
    LEFT  = 'a',
    RIGHT = 'd'
};

class Map {
private:
    const size_t fieldSizeX = 40;
    const size_t fieldSizeY = 20;
    std::vector<Character> characters_; // NOTE: vector can be changed to array

public:
    template <typename ... Characters>
    Map(Characters ... characters): characters_(characters) {};

private:
    void Draw();

public:
    void Show();
};

#endif // MAP_HPP