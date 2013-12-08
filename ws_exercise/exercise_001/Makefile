
OBJDIR = obj
INCDIR	= -I./includes

LIBS =
LIBFLAGS = #-lGL -lglut 


TARGET = exercise_001.cgi


CC_FLAGS += -g -c -std=c++0x -Wall -pedantic-errors -Wno-variadic-macros -Wpointer-arith -Wshadow -Werror

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

all: mkobjdir target  cp_to_cgi

target: $(TARGET)

mkobjdir:
	mkdir -p $(OBJDIR)

$(TARGET): $(OBJ_FILES)
	g++ $(LD_FLAGS) -o $@ $^ $(LIBS) $(LIBFLAGS)

obj/%.o: src/%.cpp
	g++ $(CC_FLAGS) $(INCDIR) -c -o $@ $<

cp_to_cgi:
	sudo cp $(TARGET) /usr/lib/cgi-bin

clean:
	rm -fr $(OBJDIR)
	rm -f $(TARGET)
	
