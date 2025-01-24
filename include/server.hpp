#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>

#include "clientServerInclude.hpp"

class Server {
private:
    class Player {
    public:
        socket_t socket;
        char buffer[bufferSize] = {};
    };

    bool isValid = false;
    socket_t serverSocket; 
    sockaddr_in address;
    int addressLength = sizeof(address);
    int opt = 1; // IDK what is opt
    std::vector<Player> players;
    const std::size_t playerCount;

    std::string GetIp();

    void WaitPlayers();
    void RunGameLoop();

    void GetPlayerData();
    void ProcessPlayerData();
    void SendProcessedData();


public:
    Server(const std::size_t playerCount, const std::size_t serverPort);
    ~Server();

    void Run();
    bool IsValid();
};

#endif // SERVER_HPP