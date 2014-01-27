#include ../Make.defines

# Source files that are part of this
SOURCES 	= $(notdir $(wildcard *.cpp))
# Create the list of objects from the source files
OBJS    	= $(addprefix ,$(SOURCES:%.cpp=%))

LIBS = -L//usr/include/cgicc/
LIBFLAGS = -l/usr/lib/libcgicc.so
INCLUDES = -I../includes -I/usr/include/cgicc/

CC=g++
CCOPTS= -g -O0 -std=c++0x -Wall -Wextra -pedantic-errors -Wno-variadic-macros -Wpointer-arith -Wshadow -Werror

.PHONY: all clean

all: $(OBJS)

clean:
	rm -f $(OBJS) *.o

%: %.cpp
	$(CC) $(CCOPTS) $(INCLUDES) -o $@ $< $(LIBS) $(LIBFLAGS)
	sudo cp $@ /usr/lib/cgi-bin/$@.cgi
	sudo chmod 755 /usr/lib/cgi-bin/$@.cgi
	