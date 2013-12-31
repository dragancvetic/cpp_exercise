#ifndef	__local_h
#define	__local_h

#define PORT 	9999 //13 // the port client will be connecting to
#define	MAXLINE		4096	/* max text line length */

void getsockname_helper(int sockfd, struct sockaddr_in *addr, socklen_t *addrlen);

#endif
