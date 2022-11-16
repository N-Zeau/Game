#ifndef GAME_MAP_H
#define GAME_MAP_H
#include "game.h"

#define NB_CASE_HORI 16
#define NB_CASE_VERTI 16

#include "SDL2/SDL.h"
#include "game.h"
#include "iostream"

class Map {
public:
    void drawMap(char **map);

    SDL_Texture *chargerImage(const char *nomFichier, SDL_Renderer *renderer);

    char **importMap(int* nbL, int* nbC);

};


#endif //GAME_MAP_H
