#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "SDL2/SDL.h"
#include <iostream>

class Menu {

public:
    int menuWIDTH = 700;
    int menuHEIGHT = 700;

    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
    SDL_Rect buttonPlay = {217, 370, 265, 68};
    SDL_Rect buttonSettings = {217, 479, 265, 68};
    SDL_Rect rectMenu = {0, 0, menuWIDTH, menuHEIGHT};

    SDL_Texture *menuEmpty;
    SDL_Texture *menuPlay;
    SDL_Texture *menuSettings;

    bool running = true;
    bool switchGame = false;
    bool switchSettings = false;

    void loop();

    void create();

    void drawMenu();

    void destroy();

    bool mouseInButton(SDL_Rect button);

    SDL_Texture *chargerImage(const char *nomFichier, SDL_Renderer *renderer);
};


#endif //GAME_MENU_H
