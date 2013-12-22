/*
** client.cpp -- a stream socket client demo
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

extern "C" {
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
}

using namespace std;


void *get_in_addr(struct sockaddr *sa);
#define PORT "13" // the port client will be connecting to

#define MAXDATASIZE 100 // max number of bytes we can get at once 

int main(int argc, char *argv[])
{
	int sockfd, numbytes;  
	char buf[MAXDATASIZE];
	struct addrinfo hints, *res, *p;
	int status;
	char ipstr[INET6_ADDRSTRLEN];

	if (argc != 2) {
		cerr << "usage: client hostname" << endl;
		return 1;
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
	hints.ai_socktype = SOCK_STREAM;

	if ((status = getaddrinfo(argv[1], PORT, &hints, &res)) != 0) {
		cerr << "getaddrinfo: " << gai_strerror(status) << endl;
		return 2;
	}

	// loop through all the results and connect to the first we can
	for(p = res; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			cerr << "client: socket" << endl;
			continue;
		}

		if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			cerr << "client: connect" << endl;
			continue;
		}

		break;
	}

	if (p == NULL) {
		cerr << "client: failed to connect" << endl;
		return 2;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
			ipstr, sizeof ipstr);
	cout << "client: connecting to " << ipstr << endl;

	freeaddrinfo(res); // all done with this structure

	if ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
	    cerr << "recv" << endl;
	    return 1;
	}

	buf[numbytes] = '\0';

	cout << "client: received numbers " << numbytes << " " << buf << endl;

	close(sockfd);

	return 0;
}

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

