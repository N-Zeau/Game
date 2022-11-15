#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "SDL2/SDL.h"
#include "game.h"
#include "iostream"

class Map {
public:
    void drawMap(char **map);

    SDL_Texture *chargerImage(const char *nomFichier, SDL_Renderer *renderer);

    char **importMap();

};


#endif //GAME_MAP_H
