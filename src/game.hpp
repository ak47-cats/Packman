#ifndef Game_hpp
#define Game_hpp

#include <vector>

namespace Game{

class Game{
  public:
    void update();
    void late_update();
    void draw();
    bool is_running() const;
};

class Context{
    std::array<Player> players;
    std::array<Enemy>  enemies;
    std::array<Spawn>  spawns;
    Pool<Prize>
};

}

#endif /* Game_hpp */
