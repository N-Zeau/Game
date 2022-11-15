#ifndef GAME_H
#define GAME_H
#include "iostream"
#include "SDL2/SDL.h"
#include "map.h"

class Game {
public:

    static void verif();

    void loop();

    bool isRunning();

    void create();

    void draw();

    void destroy();

    SDL_Window* thisWindow();

    SDL_Renderer* thisRenderer();

private:
    bool running = true;
};


#endif //GAME_H
