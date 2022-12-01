#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <SDL2/SDL.h>
#include "map.h"

class Player {

public:
    float playerX{};
    float playerY{};
    int playerSize{};
    SDL_Color playerColor{};
    bool quit = true;

    int* visionPlayer(SDL_Renderer *renderer, Map map, Player player);

    void initPlayer(SDL_Renderer *renderer, Map map);

    rectangle *rectHere(Map map, float x, float y);

    void movePlayer(Player player);

    void updatePlayer(SDL_Renderer *renderer);

    void vision3DPlayer(SDL_Renderer *renderer, Map map, Player player, int* collisionPoint);

    void handleEvents();
};

#endif //GAME_PLAYER_H
