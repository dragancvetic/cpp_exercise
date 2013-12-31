#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cerrno>

extern "C" {
#include	"unp.h"
}

#include "local.h"

using namespace std;

int main(int argc, char *argv[])
{
	int					i, sockfd[5];
	struct sockaddr_in	servaddr;


	if (argc != 2) {
		cerr << "usage: <EXE> <IPaddress>" << endl;
		return 1;
	}

//	Create TCP socket

	for (i = 0; i < 5; i++) {
		sockfd[i] = Socket(AF_INET, SOCK_STREAM, 0);

//	Specify server's IP address and port

		memset(&servaddr, 0, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(SERV_PORT);
		Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

//	Establish connection with server

		Connect(sockfd[i], (sockaddr *) &servaddr, sizeof(servaddr));
	}

	str_cli(stdin, sockfd[0]);		/* do it all */

	exit(0);
}
