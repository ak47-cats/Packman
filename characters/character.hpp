#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "event.hpp"
#include "map.hpp"

class Icon {
public:
    char symbol_;
    // Color color;

    Icon(char symbol): symbol_(symbol) {};
};

class Character {
public:
    Position position_;

private:
    Direction direction_;
    Icon icon_;

    bool IsEvent();
    Event_t GetEvent();

public: 
    Character(Position position, Icon icon): position_(position), icon_(icon) {};

    Icon GetIcon() { return icon_; }
    Direction GetDirection() { return direction_; }

    virtual void ProcessEvent();
};

#endif // CHARACTER_HPP