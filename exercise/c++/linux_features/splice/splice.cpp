/*

Simple file copy program using splice(2).

usage: splice <destination>

Based on Copyright (C) 2014 Dragan Cvetic.


This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cerrno>

extern "C" {
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/uio.h>
}

using namespace std;

long fsize (char *filename);
void read_file (char* argv, char *buf, long length);
void write_file (char* argv, char *buf, long length);
void write_file_loop( char *argv, char *buf, long length);

int main (int argc, char* argv[])
{
	long length;
	char *buf;

	/* check for two command line arguments */
	if (argc != 3) {
		cerr << "usage: " << argv[0] << "s <source> <destination>\n" << endl;
		exit(1);
	}

	length = fsize (argv[1]);			// detect an input file length
	buf = (char *)malloc(length+1);		// allocate buffer
	read_file (argv[1], buf, length);	// read input file

	for(int i=0; i<100;i++) {
		write_file_loop( argv[2], buf, length);
	}

	return 0;
}

void write_file_loop( char *argv, char *buf, long length)
{
//	remove(argv);					// remove file first
	write_file (argv, buf, length);	// write file
}

long fsize (char *filename)
{
	FILE *fp;
	long length;

	cout << "input file name is:" << filename << endl;
	fp=fopen(filename,"rb");
	if(fp==NULL) {
		cerr << "file not found!" << endl;
	}
	else {
		fseek(fp,0L,SEEK_END);
		length=ftell(fp);
		cout << "the file's length is " << length << "B" << endl;
	}
	fclose(fp);
	return length;
}

void read_file (char* argv, char *buf, long length)
{
	int src;               /* file descriptor for source file */
	ssize_t bytes_read;

	/* check that source file exists and can be opened */
	src = open(argv, O_RDONLY);
	if (src == -1) {
		cerr << "unable to open '" << argv << "': " << strerror(errno) << endl;
		exit(1);
	}

	bytes_read = read(src, buf, length);
	if (bytes_read == -1) {
		cerr << "unable to read '" << argv << "': " << strerror(errno) << endl;
		exit(1);
	}

	close(src);
}

void write_file (char* argv, char *buf, long length)
{
	int pfd[2];				/* pipe descriptor as a source */
	int dest;				/* file descriptor for destination file */
	int rc;					/* return code from sendfile */
	struct iovec iov;

	pipe(pfd);
	iov.iov_base = buf;
	iov.iov_len = length;

	/* open destination file */
	dest = open(argv, O_WRONLY|O_CREAT, (S_IRWXU | S_IRWXG | S_IRWXO));
	if (dest == -1) {
		cerr << "unable to open '" << argv << "': " << strerror(errno) << endl;
		exit(1);
	}

	/* map the buffer to a pipe */
	rc = vmsplice(pfd[1], &iov, 1, 0);
	if (rc == -1) {
		cerr << "error from splice: " << strerror(errno) << endl;
		exit(1);
	}
	if (rc != (int)iov.iov_len) {
		cerr << "incomplete transfer from splice: " << rc << " of " << (int)iov.iov_len << " bytes" << endl;
		exit(1);
	}

	/* copy buffer to a file using splice */
	rc = splice(pfd[0], NULL, dest, NULL, length, SPLICE_F_MOVE);
	if (rc == -1) {
		cerr << "error from splice: " << strerror(errno) << endl;
		exit(1);
	}
	if (rc != (int)iov.iov_len) {
		cerr << "incomplete transfer from splice: " << rc << " of " << (int)iov.iov_len << " bytes" << endl;
		exit(1);
	}

	/* clean up and exit */
	close(dest);
}

