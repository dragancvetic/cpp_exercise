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

#include "local.h"

using namespace std;

void getsockname_helper(int sockfd, struct sockaddr_in *addr, socklen_t *addrlen)
{

	/* We must put the length in a variable. */
	*addrlen = sizeof(addr);
	/* Ask getsockname to fill in this socket's local address. */
	if (getsockname(sockfd, (struct sockaddr *)addr, addrlen) == -1) {
		cerr << "getsockname() failed" << endl;
		return;
	}

	/* Print it. The IP address is often zero because sockets are seldom
	 * bound to a specific local interface. */
	cout << "Local IP address is: " << inet_ntoa(addr->sin_addr) << endl;
	cout << "Local port is: " << (int) ntohs(addr->sin_port) << endl;
}
