#ifndef CLIENT_SERVER_INCLUDE_HPP
#define CLIENT_SERVER_INCLUDE_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

using socket_t = int;

const std::size_t bufferSize = 1024;

const std::string defaultServerIP   = "212.67.15.172";
const std::string defaultServerPort = "5000";

const std::size_t maxPlayerCount = 2;

#endif // CLIENT_SERVER_INCLUDE_HPP