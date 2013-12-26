#include ../Make.defines

# Source files that are part of this
SOURCES 	= $(notdir $(wildcard *.cpp))
# Create the list of objects from the source files
OBJS    	= $(addprefix ,$(SOURCES:%.cpp=%))

LIBS = -L../lib
LIBFLAGS = -ltcpip
INCLUDES = -I../includes

CC=g++
CCOPTS= -g -O0 -std=c++0x -Wall -Wextra -pedantic-errors -Wno-variadic-macros -Wpointer-arith -Wshadow -Werror

.PHONY: all cleanmake clean

all: $(OBJS)

clean:
	rm -f $(OBJS) *.o

%: %.cpp
	$(CC) $(CCOPTS) $(INCLUDES) -o $@ $< $(LIBS) $(LIBFLAGS)
	