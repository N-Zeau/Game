#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "map.h"
#include "player.h"
#include <SDL2/SDL.h>


class Game {
    Map mapSrc{};
    Player player;

public:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool running = true;

    void verif();

    bool isRunning();

    void create();

    void drawMain();

    void destroy();

    void handleEvents();



};


#endif //GAME_H
