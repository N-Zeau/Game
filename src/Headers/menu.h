#ifndef GAME_MENU_H
#define GAME_MENU_H
#include "SDL2/SDL.h"

class Menu {

public:
        SDL_Renderer *renderer = nullptr;
        bool running = false;

        bool isRunning();

        void create();

        void drawMenu(SDL_Renderer* renderer);

};


#endif //GAME_MENU_H
