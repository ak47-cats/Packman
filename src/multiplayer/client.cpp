#include <iostream>
#include <cstring>

#include "client.hpp"
#include "timer.hpp"

Client::Client() {
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return;
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(defaultServerPort);
    // Преобразование IPv4 и IPv6 адресов из текстового формата в бинарный
    if (inet_pton(AF_INET, defaultServerIP.c_str(), &serverAddress.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        return;
    }

    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Connection Failed" << std::endl;
        return;
    }

    isValid = true; 
}

Client::~Client() {
    close(clientSocket);
    memset(buffer, 0, bufferSize);
}

void Client::GetClientActions() {
    memset(buffer, 0, bufferSize);

    Timer timer(100);
    timer.Start();
    while (timer.IsTimeOut()) {}

    static int i = 1;
    for (int j = 0; j < i; ++j)
        buffer[j] = 'a';
    i++;
}

void Client::SendData() {
    send(clientSocket, buffer, bufferSize, 0);
}

void Client::RecieveData() {
    read(clientSocket, buffer, 1024);
}

void Client::ProcessRecievedData() {
    std::cout << buffer << std::endl;
}

void Client::Play() {
    for (std::size_t i = 0; i < 120; ++i) {
        GetClientActions();
        SendData();
        RecieveData();
        ProcessRecievedData();
    }
}

bool Client::IsValid() {
    return isValid;
}
