#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "map.h"
#include "player.h"
#include <SDL2/SDL.h>


class Game {
    Map mapSrc;
    Player player;
    SDL_Event event;

public:

    void verif();

    void loop();

    bool isRunning();

    void create();

    void drawMain();

    void destroy();

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

private:
    bool running = true;
};


#endif //GAME_H
