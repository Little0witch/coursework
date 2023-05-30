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
#include "logs.h"

struct coord{
    int x;
    int y;
};

struct dataOfSocket {
    int sockfd;
    int connfd;
};

struct dataOfBool{
    bool flagToExit;
    bool readyToPlay;
};

struct threadDataOfSocket{
    struct dataOfSocket socketData;
    struct dataOfBool dataOfBool;
};

void *createServerThread(void *arg);

struct dataOfSocket createServer();

char *getCode();

bool isCorrectIP(std::string);

struct dataOfSocket createClient(const char *ip);

void closeSockets(struct dataOfSocket data_of_socket);

void closeSocket(struct dataOfSocket data_of_socket);

struct dataOfBool isActiveSocket(struct dataOfSocket);

void* isActiveSocketThread(void* arg);

void sendSignalOfReadyToPlay(struct dataOfSocket data_of_socket);

struct coord getCoordFromClient(int);

int getIsHitFromClient(int);

void sendCoordToClient(int, struct coord);

void sendIsHitToClient(int, int);

struct coord getCoordFromServer(int);

int getIsHitFromServer(int);

void sendCoordToServer(int, struct coord);

void sendIsHitToServer(int, int);



#endif //COURSEWORK_SOCKET_H
