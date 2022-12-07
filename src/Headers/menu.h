#ifndef GAME_MENU_H
#define GAME_MENU_H
#include "SDL2/SDL.h"

class Menu {

public:
    int menuWIDTH = 700;
    int menuHEIGHT = 700;

    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
    SDL_Rect* buttonTab = new SDL_Rect[2];

    SDL_Color black = {0,0,0,255};
    SDL_Color grey = {100,100,100,255};

    bool running = true;
    bool switchGame = false;

    void loop();

    void create();

    void drawMenu();

    void destroy();

    bool mouseInButton();
};


#endif //GAME_MENU_H
