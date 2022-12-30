CC = g++
CFLAGS = -W -Wall -ansi -std=c++11 -g
LIBS = -L./SDL2_ttf/.libs
LDFLAGS = `sdl2-config --cflags --libs` -lSDL2_ttf
INCLUDES = -I./SDL2_ttf
EXEC = main
SRC = Sources/main.cpp Sources/game.cpp Sources/map.cpp Sources/menu.cpp Sources/player.cpp Sources/settings.cpp
OBJ = $(SRC:.cpp=.o)
all: $(EXEC)
main: $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LIBS) $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -rf Sources/*.o *~
mrproper: clean
	rm -rf $(EXEC)