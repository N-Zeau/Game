#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include "SDL2/SDL.h"
#include "map.h"

class Player {
    float playerX;
    float playerY;

public:
    void createPlayer(SDL_Renderer *renderer, Map map, int taillePlayer, SDL_Color color);

};

#endif //GAME_PLAYER_H
