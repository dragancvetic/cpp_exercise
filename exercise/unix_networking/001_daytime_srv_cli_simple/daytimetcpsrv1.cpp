#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cerrno>

extern "C" {
#include "unp.h"
#include <time.h>
}

#include "daytime.h"

using namespace std;

int main(void)
{
	int					listenfd, connfd;
	socklen_t			len;
	struct sockaddr_in	servaddr, cliaddr;
	char				buff[MAXLINE];
	time_t				ticks;


//	Create a TCP socket

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(PORT);	/* daytime server */


//	Bind server's well-known port to socket

//	The server's well-known port (13 for the daytime service) is bound to the socket by
//	filling in an Internet socket address structure and calling bind. We specify the IP address as
//	INADDR_ANY, which allows the server to accept a client connection on any interface, in case
//	the server host has multiple interfaces.
	Bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));


//	Convert socket to listening socket

//	By calling listen, the socket is converted into a listening socket, on which incoming
//	connections from clients will be accepted by the kernel. These three steps, socket, bind,
//	and listen, are the normal steps for any TCP server to prepare what we call the listening
//	descriptor (listenfd in this example).
	Listen(listenfd, LISTENQ);


//	Accept client connection, send reply

//	Normally, the server process is put to sleep in the call to accept, waiting for a client
//	connection to arrive and be accepted. A TCP connection uses what is called a three-way
//	handshake to establish a connection. When this handshake completes, accept returns, and
//	the return value from the function is a new descriptor (connfd) that is called the connected
//	descriptor. This new descriptor is used for communication with the new client. A new
//	descriptor is returned by accept for each client that connects to our server.
	for ( ; ; ) {
		len = sizeof(cliaddr);
		connfd = Accept(listenfd, (struct sockaddr *) &cliaddr, &len);
		printf("connection from %s, port %d\n",
			   Inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)),
			   ntohs(cliaddr.sin_port));

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		Write(connfd, buff, strlen(buff));


//		Terminate connection

//		The server closes its connection with the client by calling close. This initiates the normal
//		TCP connection termination sequence: a FIN is sent in each direction and each FIN is
//		acknowledged by the other end. We will say much more about TCP's three-way handshake
//		and the four TCP packets used to terminate a TCP connection in Section 2.6.
		Close(connfd);
	}
}
