
PROGS =	daytimetcpcli daytimetcpsrv daytimetcpsrv1 

LIBS = -L../lib -ltcpip
INCLUDES = -I../includes

CC=g++
CCFLAGS= ${INCLUDES} -g -O0 -std=c++0x -D_REENTRANT -Wall -Wextra -pedantic-errors -Wno-variadic-macros -Wpointer-arith -Wshadow -Werror

.PHONY: all clean

all: $(PROGS)

clean:
	rm -f $(PROGS) *.o


daytimetcpcli: daytimetcpcli.cpp
	${CC} ${CCFLAGS} -o $@ $< tools.cpp ${LIBS}

daytimetcpsrv: daytimetcpsrv.cpp
	${CC} ${CCFLAGS} -o $@ $< ${LIBS}
daytimetcpsrv1: daytimetcpsrv1.cpp
	${CC} ${CCFLAGS} -o $@ $< ${LIBS}
