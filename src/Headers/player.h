#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include <SDL2/SDL.h>
#include "map.h"
#include "event.h"

class Player {

public:
    float playerX;
    float playerY;
    int playerSize;
    SDL_Color playerColor;

    void visionPlayer(SDL_Renderer *renderer, Map map, Player player);
    void initPlayer(SDL_Renderer* renderer, Map map);
    rectangle* rectHere(SDL_Renderer* renderer, Map map, int x, int y);
    void movePlayer(SDL_Renderer* renderer, Map map);
    void updatePlayer(SDL_Renderer* renderer, Map map);

};

#endif //GAME_PLAYER_H
