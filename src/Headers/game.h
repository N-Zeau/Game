#ifndef GAME_H
#define GAME_H

#include "iostream"
#include "map.h"
#include "player.h"
#include "SDL2/SDL.h"



class Game {

public:

    void verif();

    void loop();

    bool isRunning();

    void create();

    void drawMain();

    void destroy();

private:
    bool running = true;
     SDL_Window *window = nullptr;
     SDL_Renderer *renderer = nullptr;
};


#endif //GAME_H
