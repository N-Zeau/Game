#ifndef GAME_H
#define GAME_H
#include "iostream"
#include "SDL2/SDL.h"
#include "map.h"
#include "player.h"

#define WIDTH 1280
#define HEIGHT 720

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

class Game {
public:

    static void verif();

    void loop();

    bool isRunning();

    void create();

    void drawMain();

    void destroy();

    SDL_Window* thisWindow();

    SDL_Renderer* thisRenderer();

private:
    bool running = true;
};


#endif //GAME_H
