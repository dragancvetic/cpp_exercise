#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cerrno>

extern "C" {
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
}

using namespace std;

#define PORT 	13 // the port client will be connecting to
#define	MAXLINE		4096	/* max text line length */

int main(int argc, char *argv[])
{
	int					sockfd, n, m=0;
	char				recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr;

	if (argc != 2) {
		cerr << "usage: <EXE> <IPaddress>" << endl;
		return 1;
	}

//	Create TCP socket

//	The socket function creates an Internet (AF_INET) stream (SOCK_STREAM)
//	socket, which is a fancy name for a TCP socket. The function returns a small
//	integer descriptor that we can use to identify the socket in all future
//	function calls (e.g., the calls to connect and read that follow).
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		cerr << "socket error: " << strerror(errno) << endl;

//	Specify server's IP address and port

//	The IP address and port number fields in this structure must be in specific
//	formats: We call the library function htons ("host to network short") to
//	convert the	binary port number, and we call the library function inet_pton
//	("presentation to numeric") to convert the ASCII command-line argument into
//	the proper format.
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(PORT);	/* daytime server */
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
		cerr << "inet_pton error for " << argv[1] << endl;
		return 2;
	}

//	Establish connection with server

//	The connect function, when applied to a TCP socket, establishes a TCP connection
//	with the server specified by the socket address structure pointed to by the second argument.
//	We must also specify the length of the socket address structure as the third argument to
//	connect.
	if (connect(sockfd, (sockaddr *) &servaddr, sizeof(servaddr)) < 0)
		cerr << "connect error: " << strerror(errno) << endl;

//	Read and display server's reply

//	We read the server's reply and display the result using the standard I/O fputs
//	function. We must be careful when using TCP because it is a byte-stream protocol with no
//	record boundaries. The server's reply is normally a 26-byte string of the form
//	Mon May 26 20 : 58 : 40 2003\r\n
//	where \r is the ASCII carriage return and \n is the ASCII linefeed. With a byte-stream
//	protocol, these 26 bytes can be returned in numerous ways: a single TCP segment containing
//	all 26 bytes of data, in 26 TCP segments each containing 1 byte of data, or any other
//	combination that totals to 26 bytes. Normally, a single segment containing all 26 bytes of data
//	is returned, but with larger data sizes, we cannot assume that the server's reply will be
//	returned by a single read. Therefore, when reading from a TCP socket, we always need to
//	code the read in a loop and terminate the loop when either read returns 0 (i.e., the other end
//	closed the connection) or a value less than 0 (an error).
	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		recvline[n] = 0;	/* null terminate */
		m+=n;
		cout << "num of bytes recved: " << m << endl;
		cout << "message received: "<< recvline << endl;
	}
	if (n < 0)
		cerr << "read error" << endl;

	exit(0);
}
