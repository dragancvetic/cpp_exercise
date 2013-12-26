#include ../Make.defines

CC=gcc
CCOPTS= -c -O0 -Wall

# Source files that are part of this
SOURCES = $(notdir $(wildcard *.c))
# Create the list of objects from the source files
OBJS    = $(addprefix ,$(SOURCES:%.c=%.o))

INCLUDES = -I../includes

LIB=libtcpip.so

.PHONY: all clean

all: $(OBJS)
	$(CC) -shared -o $(LIB) $(OBJS) 

%.o: %.c
	$(CC) $(CCOPTS) $(INCLUDES) -o $@ $<

clean:
	rm -f $(OBJS) $(LIB) *.o




