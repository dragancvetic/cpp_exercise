#ifndef	__local_h
#define	__local_h

#define PORT 	9999 //13 // the port client will be connecting to
#define	MAXLINE		4096	/* max text line length */

void dg_cliloop1(FILE *fp, int sockfd, const struct sockaddr *pservaddr, socklen_t servlen);

#endif
