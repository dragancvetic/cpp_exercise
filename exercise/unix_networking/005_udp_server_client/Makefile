
PROGS =	 udpcli01 udpcli04 udpcli06 \
	udpserv01 udpserv06

LIBS = -L../lib -ltcpip
INCLUDES = -I../includes

CC=g++
CCFLAGS= ${INCLUDES} -g -O0 -std=c++0x -D_REENTRANT -Wall -Wextra -pedantic-errors -Wno-variadic-macros -Wpointer-arith -Wshadow -Werror

.PHONY: all clean

all: $(PROGS)

clean:
	rm -f $(PROGS) *.o


udpcli01: udpcli01.cpp
	${CC} ${CCFLAGS} -o $@ $< ${LIBS}
udpcli04: udpcli04.cpp 
	${CC} ${CCFLAGS} -Wno-unused-parameter -o $@ $< dgcliconnect.cpp ${LIBS}
udpcli06: udpcli06.cpp 
	${CC} ${CCFLAGS} -Wno-unused-parameter -o $@ $< dgcliloop1.cpp ${LIBS}

udpserv01: udpserv01.cpp
	${CC} ${CCFLAGS} -o $@ $< ${LIBS}
udpserv06: udpserv06.cpp
	${CC} ${CCFLAGS} -Wno-unused-parameter -o $@ $< dgecholoop1.cpp ${LIBS}

