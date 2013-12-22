TARGETS=broadcaster client getip ghbn ieee754 listener pack pack2 \
	select selectserver server showip talker

CC=g++
CCOPTS= -g -O0 -std=c++0x -Wall -Wextra -pedantic-errors -Wno-variadic-macros -Wpointer-arith -Wshadow -Werror

.PHONY: all clean

all: $(TARGETS)

clean:
	rm -f $(TARGETS) *.o

%: %.cpp
	$(CC) $(CCOPTS) -o $@ $<
	