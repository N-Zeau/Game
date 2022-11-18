#include "../Headers/player.h"
#include "../Headers/game.h"

#define playerX (WIDTH/2)
#define playerY (HEIGHT/1.3)

void Player::createPlayer(SDL_Renderer *renderer, int taillePlayer, SDL_Color color) {

    //LE JOUEUR
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect player;
    player.x = playerX, player.y = playerY, player.w = taillePlayer;
    player.h = taillePlayer;
    SDL_RenderDrawRect(renderer, &player);

    //LE CONE DE VISION
    int mouseX;
    int mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    float a = (mouseY - playerY)/(mouseX - playerX);
    float b = playerY - a*playerX;
    if (mouseY < playerY)
    SDL_RenderDrawLine(renderer, playerX + taillePlayer / 2, playerY + taillePlayer / 2,
                       -b/a, 0);
    if (mouseY > playerY)
        SDL_RenderDrawLine(renderer, playerX + taillePlayer / 2, playerY + taillePlayer / 2,
                           (HEIGHT-b)/a, HEIGHT);


}
