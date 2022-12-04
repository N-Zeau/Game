#ifndef GAME_MAP_H
#define GAME_MAP_H
#include "SDL2/SDL.h"
#include "map.h"
#include "iostream"

struct rectangle {
    int xMin;
    int yMin;
    int xMax;
    int yMax;
    int type;
};

class Map {
public:
    int WIDTH;
    int HEIGHT;
    int nbCase;

    struct rectangle* mapCoordinate;

    void drawMap(SDL_Renderer* renderer, char **map);

    SDL_Texture *chargerImage(const char *nomFichier, SDL_Renderer* renderer);

    char **importMap(int* nbL, int* nbC);

};


#endif //GAME_MAP_H
