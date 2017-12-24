//
// Created by kostarubtsov1990 on 04/12/17.
//

#ifndef EX4SERVER_SERVER_H
#define EX4SERVER_SERVER_H

#include "CommandsManager.h"

enum player {firstPlayer, secondPlayer};
enum gameStatus {inProgress, finished};

class Server {
public:

    Server(CommandsManager* commandMap);
    Server(int port);
    void start();
    void stop();

private:
    int port;
    int serverSocket; // the socket's file descriptor
    CommandsManager* commandMap;

    void handleGame(int firstPlayerClientSocket, int secondPlayerClientSocket);
    int connectPlayer (player player);
    gameStatus handleDirection(int from, int to);
    void* ClientHandler (void* args);
};


#endif //EX4SERVER_SERVER_H
