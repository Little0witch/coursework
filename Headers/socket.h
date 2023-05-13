#ifndef COURSEWORK_SOCKET_H
#define COURSEWORK_SOCKET_H

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include "string"
#include <arpa/inet.h>
#include <fcntl.h>
#include "pthread.h"
#include <csignal>

struct dataOfSocket{
    int sockfd;
    int connfd;
};

void* createServerThread(void* arg);
struct dataOfSocket createServer();
char* getCode();
bool isCorrectIP(std::string);




#endif //COURSEWORK_SOCKET_H
