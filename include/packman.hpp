#ifndef PACKMAN_HPP
#define PACKMAN_HPP

#include "character.hpp"

class Packman: public Character {
public: 
    Packman(Position position, Icon icon): Character(position, icon) {}; // TODO: inherit construction
    
    void ProcessEvent() override;
};

#endif // PACKMAN_HPP
