#include <termio.h>
#include <iostream>
#include <unistd.h>

#include "character.hpp"

bool Character::IsEvent() {
    int bytesWaiting = 0;
    ioctl(STDIN_FILENO, FIONREAD, &bytesWaiting); // get count of available bytes
    return bytesWaiting;
}

Event_t Character::GetEvent() {
    if (IsEvent()) 
        return std::cin.get();

    return Event::NO_EVENT;
}