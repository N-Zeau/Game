#ifndef GAME_MAP_H
#define GAME_MAP_H
#include "SDL2/SDL.h"
#include "iostream"

struct rectangle {
    int xMin;
    int yMin;
    int xMax;
    int yMax;
    int type;
};

struct s_piece{
    SDL_Rect * piece;
};
typedef s_piece * piece_t;

struct s_liste{
    piece_t ele;
    s_liste * next;
};
typedef s_liste * liste_t;


class Map {
public:
    int WIDTH;
    int HEIGHT;
    int nbCase;

    struct rectangle* mapCoordinate;
    liste_t pieces;

    void drawMap(SDL_Renderer* renderer);

    SDL_Texture *chargerImage(const char *nomFichier, SDL_Renderer* renderer);

    char **importMap(int* nbL, int* nbC);

};


#endif //GAME_MAP_H
