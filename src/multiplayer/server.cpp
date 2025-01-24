#include <iostream>
#include <cstdio>
#include <array>
#include <memory>
#include <cstring>

#include "server.hpp"
#include "timer.hpp"

Server::Server(const std::size_t playerCount, const std::size_t serverPort): playerCount(playerCount) {
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Socket creation error" << std::endl;
        return;
    }

    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        std::cerr << "Set socket options error" << std::endl;
        return;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(serverPort);

    if (bind(serverSocket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return;
    }

    // Начало прослушивания
    if (listen(serverSocket, 1) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return;
    }

    std::cout << "Server is listening" << std::endl;
    std::cout << "IP: " << GetIp();
    std::cout << "Port: " << serverPort << std::endl << std::endl;

    isValid = true;
}

Server::~Server() {
    for (Player& player : players) {
        close(player.socket);
        memset(player.buffer, 0, sizeof(player.buffer));
    }
    
    close(serverSocket);
}

// ChatGPS's realization
std::string Server::GetIp() {
    const char* cmd = "hostname -I";
    std::array<char, 128> buffer;
    std::string result;

    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    return result;
}

void Server::WaitPlayers() {
    for (std::size_t i = 0; i < playerCount; ++i) {
        Player nextPlayer;
        if ((nextPlayer.socket = accept(serverSocket, 
                                      (struct sockaddr *)&address, 
                                      (socklen_t*)&addressLength)) < 0) {
            std::cerr << "Accept " << i << " failed" << std::endl;
            return ;
        }
        players.push_back(nextPlayer);
    }
}

void Server::RunGameLoop() {
    for (std::size_t i = 0; i < 120; i++)  { // TODO: make loop wich ends at the game's end
        Timer timer(50);
        timer.Start();
        while (!timer.IsTimeOut()) {
            GetPlayerData();
            ProcessPlayerData();
            SendProcessedData();
        }
    }
}

void Server::GetPlayerData() {
    for (Player& player : players) {
        read(player.socket, player.buffer, bufferSize); // TODO: add error handling
    }
}

void Server::ProcessPlayerData() {
    // TODO:
}

void Server::SendProcessedData() {
    for (Player& player : players) {
        send(player.socket, player.buffer, bufferSize, 0);
        memset(player.buffer, 0, bufferSize);
    }
}

void Server::Run() {
    WaitPlayers();
    RunGameLoop();
}

bool Server::IsValid() {
    return isValid;
}