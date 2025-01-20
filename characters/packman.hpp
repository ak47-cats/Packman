#ifndef PACKMAN_HPP
#define PACKMAN_HPP

#include "character.hpp"

class Packman: Character {
public: 
    Packman(Position position, Icon icon): Character(position, icon) {}; // TODO: inherit construction
};

#endif // PACKMAN_HPP
