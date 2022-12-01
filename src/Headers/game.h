#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "map.h"
#include "player.h"
#include <SDL2/SDL.h>


class Game {
    Map mapSrc;
    Player player;

public:

    void verif();

    bool isRunning();

    void create();

    void drawMain();

    void destroy();

    void handleEvents();

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool running = true;

};


#endif //GAME_H
