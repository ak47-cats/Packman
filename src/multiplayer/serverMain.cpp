#include <iostream>
#include <cstdlib>

#include "server.hpp"

bool GetPlayerCount(char* playerCountStr, std::size_t* playerCountBuffer);

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {                    // TODO: add fuature for change port
        std::cout << "usage: ./server PLAYER_COUNT */ [SERVER_PORT (default 5000)] /*" << std::endl;
        return 0;
    }
    else {
        std::size_t playerCount = 0;

        if (GetPlayerCount(argv[1], &playerCount)) {
                Server server(playerCount, defaultServerPort);
                if (server.IsValid())
                    server.Run();
            }
    }

    return 0;
}

bool GetPlayerCount(char* playerCountStr, std::size_t* playerCountBuffer) {
    if (playerCountBuffer == NULL || playerCountStr == NULL) {
        std::cerr << "Null ptr in " << __FUNCTION__ << "()" << std::endl;
        return false;
    }

    *playerCountBuffer = atoi(playerCountStr);
    if (*playerCountBuffer > 0 && *playerCountBuffer <= maxPlayerCount)
        return true;

    std::cerr << "PLAYER_COUNT must be between 1 and " << maxPlayerCount << std::endl <<
                  "Your input is " << *playerCountBuffer << std::endl;
    return false;
}
