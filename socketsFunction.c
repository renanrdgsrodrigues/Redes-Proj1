#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <time.h>

#include "socketsFunction.h"

void error(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

/*
    SOCKETS
*/
int createSocket(void)
{
    int socketfd;

    if((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
    {
        error("ERROR opening socket");
    }

    return socketfd;
}

int writeToSocket(int socketfd, char *msg)
{
    return (write(socketfd, msg, strlen(msg)));
}

int readFromSocket(int socketfd, char *buffer, int buffersize)
{
    return (read(socketfd, buffer, buffersize));
}

/*
    SERVER
*/
void bindToAddress(int serverSocket, struct sockaddr_in *server_address)
{
    if(bind(serverSocket, (struct sockaddr *) server_address, sizeof(struct sockaddr)) == -1) 
    {
        error("ERROR on binding socket");
    }
}

void listenToConnections(int serverSocket)
{
    if(listen(serverSocket, BACKLOG) < 0) 
    {
        error("ERROR on listening");
    }
}

int acceptConnection(int serverSocket, struct sockaddr_in *client_address, unsigned int *clientLength)
{
    int clientSocket;

    if((clientSocket = accept(serverSocket, (struct sockaddr *) client_address, clientLength)) < 0)
    {
        error("ERROR on accept");
    }

    return clientSocket;
}

/*
    CLIENT
*/
void connectToServer(int clientSocket, struct sockaddr_in *server_address)
{
    if(connect(clientSocket, (struct sockaddr *) server_address, sizeof(struct sockaddr)) == -1) 
    {   
        error("ERROR connecting");
    }
}


int numeroPessoas(int c1, int c2, int c3){
	return c1 + c2 + c3;
}


int notCintos(int c1, int c2, int c3, int base1, int base2, int base3){
	
	srand(time(NULL));

	if(c1 > base1) c1 = rand()%base1;

	if(c2 > base2) c2 = rand()%base2;

	if(c3 > base3) c3 = rand()%base3;

	return c1 + c2 + c3;
}
