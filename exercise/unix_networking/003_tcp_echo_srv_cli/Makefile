
PROGS =	tcpcli01 tcpcli04 \
	tcpserv01 tcpserv02 tcpserv03 tcpserv04

LIBS = -L../lib -ltcpip
INCLUDES = -I../includes

CC=g++
CCFLAGS= ${INCLUDES} -g -O0 -std=c++0x -D_REENTRANT -Wall -Wextra -pedantic-errors -Wno-variadic-macros -Wpointer-arith -Wshadow -Werror

.PHONY: all clean

all: $(PROGS)

clean:
	rm -f $(PROGS) *.o


tcpcli01: tcpcli01.cpp
	${CC} ${CCFLAGS} -o $@ $< ${LIBS}
tcpcli04: tcpcli04.cpp
	${CC} ${CCFLAGS} -o $@ $< ${LIBS}

tcpserv01: tcpserv01.cpp
	${CC} ${CCFLAGS} -o $@ $< ${LIBS}
tcpserv02: tcpserv02.cpp 
	${CC} ${CCFLAGS} -Wno-unused-parameter -o $@ $< sigchldwait.cpp ${LIBS}
tcpserv03: tcpserv03.cpp
	${CC} ${CCFLAGS} -Wno-unused-parameter -o $@ $< sigchldwait.cpp ${LIBS}
tcpserv04: tcpserv04.cpp
	${CC} ${CCFLAGS} -Wno-unused-parameter -o $@ $< sigchldwaitpid.cpp ${LIBS}


