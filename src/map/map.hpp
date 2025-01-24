#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <variant>
#include <stddef.h>


class Nothing {};
class Wall {};

using PlayerId = size_t;
using SpawnId = size_t;
using EnemyId = size_t;

class Enemy {
    // Strategy strategy;
    // bool is_bot;
};


class Player {
    int remained_lives;
    int score;
};

struct Prize {
    size_t price;
};

class Spawn {
    // SpawnType type; // for enemy or players
};


class Context;
/*
Как нужно организовывать счет игрока?
Как игрок должен менять карту своим ходом?
1) В игроке должно храниться (x,y), а на карте достаточно хранить PlayerId и пулл игроков можно держать в другом месте.
2) Возможно можно просто в Player сделать метод visit и потом хуячить туда указатель на GameMap.
*/

// TODO: стоит ли создавать пулл игроков и ботов



using MapObject = std::variant<
    Nothing,
    Wall,
    Prize,

    EnemyId,
    PlayerId,
    SpawnId
>;

struct Coords{
    size_t x;
    size_t y;
};

class GameMap{
  private:
    size_t rows, cols;
    MapObject** map; // [rows][cols];
  public:
    GameMap(MapObject** map): map(map){}

    void swap(Coords a, Coords b){
        std::swap(map[a.y][a.x], map[b.y][b.x]);
    }
    MapObject& operator()(size_t y, size_t x){
        return map[y][x];
    }
};


#endif
