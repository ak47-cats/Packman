#ifndef MAP_HPP
#define MAP_HPP

class Position {
public:
	int x_;
	int y_;

	Position(int x, int y): x_(x), y_(y) {};
};

enum Direction {
    UP    = 'w',
    DOWN  = 's',
    LEFT  = 'a',
    RIGHT = 'd'
};

#endif // MAP_HPP