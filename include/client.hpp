#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "clientServerInclude.hpp"

class Client {
private:
    socket_t clientSocket;
    sockaddr_in serverAddress;
    char buffer[bufferSize] = {}; 
    bool isValid = false;

    bool ConnectToServer();

    void GetClientActions();
    void SendData();
    void RecieveData();
    void ProcessRecievedData();

public: // TODO: add interface changing server IP and port
    Client();
    ~Client();

    void Play();
    bool IsValid();
};

#endif // CLIENT_HPP