#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include "SDL2/SDL.h"
#include "map.h"

class Player {
    float playerX;
    float playerY;
    int playerSize;
    SDL_Color playerColor;

public:
    void visionPlayer(SDL_Renderer *renderer, Map map, Player player);
    void initPlayer(SDL_Renderer* renderer, Map map);
    void movePlayer(SDL_Renderer* renderer, Map map);
    void updatePlayer(SDL_Renderer* renderer, Map map);

};

#endif //GAME_PLAYER_H
