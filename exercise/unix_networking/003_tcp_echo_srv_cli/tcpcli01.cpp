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
	int					sockfd;
	struct sockaddr_in	servaddr;
	socklen_t addrlen;


	if (argc != 2) {
		cerr << "usage: <EXE> <IPaddress>" << endl;
		return 1;
	}

//	Create TCP socket

//	The socket function creates an Internet (AF_INET) stream (SOCK_STREAM)
//	socket, which is a fancy name for a TCP socket. The function returns a small
//	integer descriptor that we can use to identify the socket in all future
//	function calls (e.g., the calls to connect and read that follow).
	sockfd = Socket(AF_INET, SOCK_STREAM, 0);


//	Specify server's IP address and port

//	The IP address and port number fields in this structure must be in specific
//	formats: We call the library function htons ("host to network short") to
//	convert the	binary port number, and we call the library function inet_pton
//	("presentation to numeric") to convert the ASCII command-line argument into
//	the proper format.
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

//	Establish connection with server

//	The connect function, when applied to a TCP socket, establishes a TCP connection
//	with the server specified by the socket address structure pointed to by the second argument.
//	We must also specify the length of the socket address structure as the third argument to
//	connect.
	Connect(sockfd, (sockaddr *) &servaddr, sizeof(servaddr));

	cout << endl << "getsockname after connect()" << endl;
	getsockname_helper(sockfd, &servaddr, &addrlen);

	str_cli(stdin, sockfd);		/* do it all */

	exit(0);
}
