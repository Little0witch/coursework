#include "../Headers/socket.h"


char *getCode() {
    system("hostname -I > ip.txt");
    FILE *file = fopen("ip.txt", "r");
    if (file == nullptr) {
        logError("Error 2: file opening error, the place where the error occurred: /Sources/Socket.cpp, line 6");
        exit(1);
    }
    char *code = nullptr;
    if (!(code = (char *) malloc(15))) {
        logError("Error 1: memory allocation error, the place where the error occurred: /Sources/Socket.cpp, line 12");
        exit(1);
    }
    char ip[15];
    fscanf(file, "%s", ip);
    fclose(file);
    remove("ip.txt");
    strcpy(code, ip);
    if (strlen(code) < 7) {
        logError(
                "Error 5: error getting an ip address, the place where the error occurred: /Sources/Socket.cpp, line 5");
        return nullptr;
    } else
        return code;
}

struct dataOfSocket createServer() {
    int sockfd, connfd;
    socklen_t len;
    struct sockaddr_in servaddr, cli;

    struct dataOfSocket data_of_socket{};
    data_of_socket.connfd = -1;
    data_of_socket.sockfd = -1;


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        logError("Error 6: socket creation error, the place where the error occurred: /Sources/Socket.cpp, line 39");
        data_of_socket.connfd = data_of_socket.sockfd = 404;
        return data_of_socket;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
//    int reuse = 1;
//    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    if ((bind(sockfd, (SA *) &servaddr, sizeof(servaddr))) != 0) {
        logError("Error 7: socket bind error, the place where the error occurred: /Sources/Socket.cpp, line 53");
        data_of_socket.connfd = data_of_socket.sockfd = 400;
        return data_of_socket;
    }

    if ((listen(sockfd, 5)) != 0) {
        logError("Error 8: listen error, the place where the error occurred: /Sources/Socket.cpp, line 59");
        data_of_socket.connfd = data_of_socket.sockfd = 404;
        return data_of_socket;
    }

    len = sizeof(cli);

    connfd = accept(sockfd, (SA *) &cli, &len);

    if (connfd < 0) {
        logError("Error 9: server accept failed, the place where the error occurred: /Sources/Socket.cpp, line 67");
        data_of_socket.connfd = data_of_socket.sockfd = 404;
        return data_of_socket;
    } else {
        data_of_socket.connfd = connfd;
        data_of_socket.sockfd = sockfd;
        return data_of_socket;
    }
}

void *createServerThread(void *arg) {
    auto *dataOfSocket = (struct dataOfSocket *) arg;
    struct dataOfSocket dataOfSocket1{};
    dataOfSocket1 = createServer();
    dataOfSocket->sockfd = dataOfSocket1.sockfd;
    dataOfSocket->connfd = dataOfSocket1.connfd;
    return dataOfSocket;
}

bool isCorrectIP(std::string string) {

    int valueOfPoint = 0;
    int flag = 1;

    for (int i = 0; i < string.size(); ++i) {
        if (string[i] == '.')
            valueOfPoint++;
    }
    for (int i = 0; i < string.size(); ++i) {
        if (string[i] != '.' && !(string[i] <= '9' && '0' <= string[i])) {
            flag = 0;
            break;
        }
    }

    if (valueOfPoint == 3 && flag)
        return true;
    else
        return false;
}

struct dataOfSocket createClient(const char *ip) {
    struct dataOfSocket data_of_socket{};
    int sockfd;
    struct sockaddr_in servaddr, cli;
    data_of_socket.sockfd = -1;
    data_of_socket.connfd = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        logError("Error 6: socket creation error, the place where the error occurred: /Sources/Socket.cpp, line 118");
        exit(0);
    }

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(PORT);


    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        logError("Error 10: F_GETFL error, the place where the error occurred: /Sources/Socket.cpp, line 131");
        return data_of_socket;
    }
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
        logError("Error 10: F_SETFL error, the place where the error occurred: /Sources/Socket.cpp, line 136");
        return data_of_socket;
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == 0) {
        return data_of_socket;
    }

    struct timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    fd_set writefds;
    FD_ZERO(&writefds);
    FD_SET(sockfd, &writefds);

    int selectResult = select(sockfd + 1, NULL, &writefds, NULL, &timeout);
    if (selectResult == -1) {
        logError("Error 12: select error, the place where the error occurred: /Sources/Socket.cpp, line 153");
        return data_of_socket;
    } else if (selectResult == 0) {
        logError("Error 13: connection timeout, the place where the error occurred: /Sources/Socket.cpp, line 153");
        return data_of_socket;
    } else if (FD_ISSET(sockfd, &writefds)) {
        data_of_socket.sockfd = sockfd;
        return data_of_socket;
    }

    return data_of_socket;
}

void closeSockets(struct dataOfSocket data_of_socket) {
    if (data_of_socket.connfd == 0) {
        write(data_of_socket.sockfd, "404", sizeof("404"));

        if (close(data_of_socket.sockfd) == -1)
            logError(
                    "Error 14: error close of socket, the place where the error occurred: /Sources/Socket.cpp, line 172");

    } else {
        write(data_of_socket.connfd, "404", sizeof("404"));

        if (close(data_of_socket.sockfd) == -1)
            logError(
                    "Error 14: error close of socket, the place where the error occurred: /Sources/Socket.cpp, line 179");

    }
    sleep(1);
}

struct dataOfBool isActiveSocket(struct dataOfSocket data_of_socket) {
    char buff[MAX];
    int number;
    ssize_t bytesRead;
    struct dataOfBool data_of_bool{};
    data_of_bool.flagToExit = false;
    data_of_bool.readyToPlay = false;

    memset(buff, 0, sizeof(buff));
    if (data_of_socket.connfd == 0) {
        while (1) {
            bytesRead = read(data_of_socket.sockfd, buff, sizeof(buff));
            if (bytesRead > 0)
                break;
        }
        number = atoi(buff);
        if (number == 404) {
            data_of_bool.flagToExit = true;
            return data_of_bool;
        }
        if (number == 200) {
            data_of_bool.readyToPlay = true;
            return data_of_bool;
        }
    } else {
        while (1) {
            bytesRead = read(data_of_socket.connfd, buff, sizeof(buff));
            if (bytesRead > 0)
                break;
        }
        number = atoi(buff);
        if (number == 404) {
            data_of_bool.flagToExit = true;
            return data_of_bool;
        }

        if (number == 200) {
            data_of_bool.readyToPlay = true;
            return data_of_bool;
        }
    }

    return data_of_bool;
}

void *isActiveSocketThread(void *arg) {
    auto *threadData = (struct threadDataOfSocket *) arg;
    struct dataOfSocket socketData = threadData->socketData;
    threadData->dataOfBool = isActiveSocket(socketData);
    return threadData;
}

void sendSignalOfReadyToPlay(struct dataOfSocket data_of_socket) {
    char buff[MAX];
    memset(buff, 0, sizeof(buff));
    int number = 200;
    sprintf(buff, "%d", number);

    if (data_of_socket.connfd == 0) {
        write(data_of_socket.sockfd, buff, sizeof(buff));
    } else {
        write(data_of_socket.connfd, buff, sizeof(buff));
    }
}

void closeSocket(struct dataOfSocket data_of_socket) {
    if (close(data_of_socket.sockfd) == -1)
        logError(
                "Error 14: error close of socket, the place where the error occurred: /Sources/Socket.cpp, line 179");

    sleep(1);
}

struct coord getCoordFromClient(int connfd) {
    struct coord coord{};
    int number = 0;
    char buff[MAX];
    ssize_t bytesRead;

    memset(buff, 0, sizeof(buff));

    while (true) {
        bytesRead = read(connfd, buff, sizeof(buff));
        if (bytesRead > 0)
            break;
    }
    number = atoi(buff);

    coord.y = number % 10;
    coord.x = number / 10;

    return coord;
}

int getIsHitFromClient(int connfd) {
    int isHit = 0;
    char buff[MAX];
    ssize_t bytesRead;
    memset(buff, 0, sizeof(buff));

    while (true) {
        bytesRead = read(connfd, buff, sizeof(buff));
        if (bytesRead > 0)
            break;
    }
    isHit = atoi(buff);

    return isHit;
}

void sendCoordToClient(int connfd, struct coord coord) {
    char buff[MAX];
    int number = coord.x * 10 + coord.y;
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%d", number);
    write(connfd, buff, sizeof(buff));
}

void sendIsHitToClient(int connfd, int isHit) {
    char buff[MAX];
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%d", isHit);
    write(connfd, buff, sizeof(buff));
}

struct coord getCoordFromServer(int sockfd) {
    struct coord coord{};
    ssize_t bytesRead;
    int number = 0;
    char buff[MAX];
    memset(buff, 0, sizeof(buff));
    while (true) {
        bytesRead = read(sockfd, buff, sizeof(buff));
        if (bytesRead > 0)
            break;
    }
    number = atoi(buff);

    coord.y = number % 10;
    coord.x = number / 10;
    return coord;
}

int getIsHitFromServer(int sockfd) {
    int isHit = 0;
    char buff[MAX];
    ssize_t bytesRead;
    memset(buff, 0, sizeof(buff));
    while (true) {
        bytesRead = read(sockfd, buff, sizeof(buff));
        if (bytesRead > 0)
            break;
    }
    isHit = atoi(buff);

    return isHit;
}

void sendCoordToServer(int sockfd, struct coord coord) {
    char buff[MAX];
    int number = coord.x * 10 + coord.y;
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%d", number);
    write(sockfd, buff, sizeof(buff));
}

void sendIsHitToServer(int sockfd, int isHit) {
    char buff[MAX];
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%d", isHit);
    write(sockfd, buff, sizeof(buff));
}

void handle_alarm(int signal, struct dataOfSocket dataOfSocket){
    closeSockets(dataOfSocket);
}
