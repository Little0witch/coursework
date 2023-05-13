#include "../Headers/socket.h"


char *getCode() {
    system("hostname -I > ip.txt");
    FILE *file = fopen("ip.txt", "r");
    if (file == NULL) {
        printf("Ошибка 1 файл не открылся");
        return NULL;
    }
    char *code = NULL;
    if (!(code = (char *) malloc(15))) {
        printf("Error 1: bad allocate memory");
        return NULL;
    }
    char ip[15];
    fscanf(file, "%s", ip);
    fclose(file);
    remove("ip.txt");
    strcpy(code, ip);
    if (strlen(code) < 7) {
        printf("connect the inet");
        return NULL;
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
        printf("socket creation failed...\n");
        return data_of_socket;
    } else
        printf("Socket successfully created..\n");


    bzero(&servaddr, sizeof(servaddr));


    servaddr.sin_family = AF_INET;
    //servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);


    if ((bind(sockfd, (SA *) &servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        return data_of_socket;
    } else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        return data_of_socket;
    } else
        printf("Server listening..\n");

    len = sizeof(cli);

    connfd = accept(sockfd, (SA *) &cli, &len);

    if (connfd < 0) {
        printf("server accept failed...\n");
        return data_of_socket;
    } else {
        printf("server accept to client");
        data_of_socket.connfd = connfd;
        data_of_socket.sockfd = sockfd;
        exit(0);
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


    // socket create and varification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    } else
        printf("Socket successfully created..\n");

    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(PORT);


    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl F_GETFL error");
        return data_of_socket;
    }
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl F_SETFL error");
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
        perror("select error");
        return data_of_socket;
    } else if (selectResult == 0) {
        printf("Connection timeout\n");
        return data_of_socket;
    } else if (FD_ISSET(sockfd, &writefds)) {
        data_of_socket.sockfd = sockfd;
        printf("ura");
        return data_of_socket;
    }

    return data_of_socket;
}
