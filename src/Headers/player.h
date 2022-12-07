#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <SDL2/SDL.h>
#include "map.h"
#include <vector>

class Player {

public:
    float playerX{};
    float playerY{};
    int playerSize{};
    float Render3DSize;
    SDL_Color playerColor{};

    std::vector<double> visionPlayer(SDL_Renderer *renderer, Map map);

    void initPlayer(SDL_Renderer *renderer, Map map);

    rectangle *rectHere(Map map, float x, float y);

    void updatePlayer(SDL_Renderer *renderer);

    void vision3DPlayer(SDL_Renderer *renderer, Map map, std::vector<double> &view3D);

};

#endif //GAME_PLAYER_H
