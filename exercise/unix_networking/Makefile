#include ../Make.defines

PROGS =	daytimetcpcli 
#		daytimetcpcli1 daytimetcpcli2 daytimetcpcli3 \
#		daytimetcpsrv daytimetcpsrv1 daytimetcpsrv2 daytimetcpsrv3 \
#		daytimetcpcliv6 daytimetcpsrvv6 \
#		byteorder

CC=g++
CCOPTS= -g -O0 -std=c++0x -Wall -Wextra -pedantic-errors -Wno-variadic-macros -Wpointer-arith -Wshadow -Werror

.PHONY: all clean

all: $(TARGETS)

clean:
	rm -f $(PROGS) *.o

%: %.cpp
	$(CC) $(CCOPTS) -o $@ $<
	