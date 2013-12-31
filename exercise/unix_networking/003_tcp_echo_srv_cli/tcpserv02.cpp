#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cerrno>

extern "C" {
#include "unp.h"
}

#include "local.h"

using namespace std;

int main(void)
{
	int					listenfd, connfd;
	pid_t				childpid;
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;
	void				sig_chld(int);
	char				buff[MAXLINE];


//	Create a TCP socket

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(SERV_PORT);


//	Bind server's well-known port to socket

	Bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));


//	Convert socket to listening socket

	Listen(listenfd, LISTENQ);

	Signal(SIGCHLD, sig_chld);


//	Accept client connection, send reply

	for ( ; ; ) {
		clilen = sizeof(cliaddr);
		connfd = Accept(listenfd, (struct sockaddr *) &cliaddr, &clilen);
		cout << "connection from ";
		cout << Inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff));
		cout << ", port " << ntohs(cliaddr.sin_port) << endl;
		if ( (childpid = Fork()) == 0) {	/* child process */
			Close(listenfd);	/* close listening socket */
			str_echo(connfd);	/* process the request */
			exit(0);
		}

//		Terminate connection

		Close(connfd);			/* parent closes connected socket */
	}
}
