
PROGS =	checkopts

LIBS = -L../lib -ltcpip
INCLUDES = -I../includes

CC=g++
CCFLAGS= ${INCLUDES} -g -O0 -std=c++0x -D_REENTRANT -Wall -Wextra -pedantic-errors -Wno-variadic-macros -Wpointer-arith -Wshadow -Werror

.PHONY: all clean

all: $(PROGS)

clean:
	rm -f $(PROGS) *.o


checkopts: checkopts.cpp
	${CC} ${CCFLAGS} -o $@ $< ${LIBS}

	