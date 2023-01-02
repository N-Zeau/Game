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

    /*
     *Cette fonction créer les settings
     */
    void create();

    /*
     * Cette fonction gère la fermeture de la fenêtre
     */
    void loop();

    /*
     * Cette fonctionne supprime le renderer et la fenêtre utilisé pour les settings
     */
    void destroy();

};


#endif //GAME_SETTINGS_H
