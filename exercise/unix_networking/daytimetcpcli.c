#include <iostream>
#include <cstring>
#include <cstdlib>

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
	
	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		cerr << "socket error" << endl;

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(PORT);	/* daytime server */
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
		cerr << "inet_pton error for " << argv[1] << endl;
		return 2;
	}

	if (connect(sockfd, (sockaddr *) &servaddr, sizeof(servaddr)) < 0)
		cerr << "connect error" << endl;

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
