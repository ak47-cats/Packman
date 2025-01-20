#ifndef EVENT_HPP
#define EVENT_HPP

using Event_t = char;

namespace Event {
    const char UP    = 'w';
    const char DOWN  = 's';
    const char LEFT  = 'a';
    const char RIGHT = 'd';
    const char ENTER = '\n';

    const char NO_EVENT = '\0';
}

#endif // EVENT_HPP