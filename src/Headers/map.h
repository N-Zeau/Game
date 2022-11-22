#ifndef GAME_MAP_H
#define GAME_MAP_H
#include "SDL2/SDL.h"
#include "iostream"

class Map {
public:
    int WIDTH;
    int HEIGHT;

    void drawMap(SDL_Renderer* renderer, char **map);

    SDL_Texture *chargerImage(const char *nomFichier, SDL_Renderer* renderer);

    char **importMap(int* nbL, int* nbC);

};


#endif //GAME_MAP_H
