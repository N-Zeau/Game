#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include "SDL2/SDL.h"
#include "map.h"
#include "cmath"

class Player {

public:
    void createPlayer(SDL_Renderer *renderer, int taillePlayer, SDL_Color color);

};

#endif //GAME_PLAYER_H
