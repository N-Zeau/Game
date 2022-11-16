#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include "SDL2/SDL.h"
#include "../Headers/game.h"

class Player{
    int x;
    int y;
    float rad;

    public:
        void drawPlayer(SDL_Renderer *renderer, int x, int y, int radius, SDL_Color color);
    private:
        void createPlayer();

};

#endif //GAME_PLAYER_H
