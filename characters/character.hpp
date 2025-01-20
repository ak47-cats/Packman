#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "event.hpp"


// TODO: move Direction and Position declaration to other file
enum Direction { // NOTE: can be optimized with map
    UP    = 'w',
    DOWN  = 's',
    LEFT  = 'a',
    RIGHT = 'd'
};

class Position {
public:
	int x_;
	int y_;

	Position(int x, int y): x_(x), y_(y) {};
};

class Icon {
public:
    char symbol_;
    // Color color;

    Icon(char symbol): symbol_(symbol) {};
};

class Character {
public:
    Position position_;

protected:
    Direction direction_;
    Icon icon_;

    bool IsEvent();
    Event_t GetEvent();

public: 
    Character(Position position, Icon icon): position_(position), icon_(icon) {};

    Position GetPosition() { return position_; }
    Icon GetIcon() { return icon_; }
    Direction GetDirection() { return direction_; }

    virtual void ProcessEvent();
};

#endif // CHARACTER_HPP