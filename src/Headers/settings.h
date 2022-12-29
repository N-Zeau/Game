#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H
#include "SDL2/SDL.h"

class Settings {

public:
    int settingsWIDTH = 700;
    int settingsHEIGHT = 700;

    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
    bool running = true;

    void create();
    void loop();
    void destroy();

};


#endif //GAME_SETTINGS_H
