#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "map.hpp"

class Icon {
public:
    char symbol_;
    // Color color;

    Icon(char symbol): symbol_(symbol) {};
};

class Character {
private:
    Position position_;
    Direction direction_;
    Icon icon_;

public: 
    Character(Position position, Icon icon): position_(position), icon_(icon) {};

    Position GetPosition() {
        return position_;
    }

    Icon GetIcon() {
        return icon_;
    }

    void Turn(Direction direction) {
        direction_ = direction;
    }
};

#endif // CHARACTER_HPP