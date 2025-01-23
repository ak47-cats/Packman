#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "clientServerInclude.hpp"

class Client {
private:
    socket_t clientSocket;
    socket_t serverSocket;
    sockaddr_in serverAddress;
    char buffer[bufferSize]; 

    bool ConnectToServer();

    void GetClientActions();
    void SendData();
    void RecieveProcessedData();

public: // TODO: add interface changing server IP 
    Client();
    ~Client();

    void Play();
};

#endif // CLIENT_HPP