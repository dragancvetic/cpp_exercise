
OBJDIR = obj
INCDIR	= -I./includes

LIBS =
LIBFLAGS =


TARGET = showip


CC_FLAGS += -g -c -std=c++0x -Wall -pedantic-errors -Wno-variadic-macros -Wpointer-arith -Wshadow -Werror

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

all: target

target: $(OBJDIR) $(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TARGET): $(OBJ_FILES)
	g++ $(LD_FLAGS) -o $@ $^ $(LIBS) $(LIBFLAGS)

obj/%.o: src/%.cpp
	g++ $(CC_FLAGS) $(INCDIR) -c -o $@ $<

clean:
	rm -fr $(OBJDIR)
	rm -f $(TARGET)
	
