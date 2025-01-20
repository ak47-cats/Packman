#include "packman.hpp"

void Packman::Character::ProcessEvent() {
    Event_t event = GetEvent();

    if (event == Event::NO_EVENT) // The most often variant
        return;

    switch (event) {
        case Event::UP:
            direction_ = Direction::UP;
            break;
        
        case Event::DOWN:
            direction_ = Direction::DOWN;
            break;
    
        case Event::LEFT:
            direction_ = Direction::LEFT;
            break;

        case Event::RIGHT:
            direction_ = Direction::RIGHT;
            break;
    }
}