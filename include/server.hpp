#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>

#include "clientServerInclude.hpp"

class Server {
private:
    socket_t serverSocket; 
    sockaddr_in address;
    int opt = 1; // IDK what is opt
    char buffer[bufferSize] = {};
    std::vector<socket_t> playerSockets;
    const std::size_t playerCount;

    void WaitPlayers();
    void RunGameLoop();

    void GetPlayerData();
    void ProcessPlayerData();
    void SendProcessedData();


public:
    Server(const std::size_t playerCount, const std::string serverPort);
    ~Server();

    void Run();
};

#endif // SERVER_HPP