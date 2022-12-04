#ifndef GAME_MENU_H
#define GAME_MENU_H
#include "SDL2/SDL.h"

class Menu {

public:
    int menuWIDTH = 700;
    int menuHEIGHT = 700;
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
    SDL_Rect* button = new SDL_Rect[2];
    bool running = true;
    bool switchGame = false;

    void loop();

    void create();

    void drawMenu();

    void destroy();
};


#endif //GAME_MENU_H
