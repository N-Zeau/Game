#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <SDL2/SDL.h>
#include "map.h"
#include <vector>

class Player {

public:
    float playerX{};
    float playerY{};
    float angle = 0;
    int playerSize{};
    float Render3DSize;
    SDL_Color playerColor{};
    SDL_Rect rectGunFPS = {0,0,733,526};
    SDL_Rect rectGunScreen = {645,420,418,300};
    SDL_Texture *gun;

    std::vector<double> visionPlayer(SDL_Renderer *renderer, Map map);

    void initPlayer(SDL_Renderer *renderer, Map map);

    rectangle *rectHere(Map map, float x, float y);

    void updatePlayer(SDL_Renderer *renderer);

    void vision3DPlayer(SDL_Renderer *renderer, Map map);

    SDL_Texture *chargerImage(const char *nomFichier, SDL_Renderer *renderer);


};

#endif //GAME_PLAYER_H
