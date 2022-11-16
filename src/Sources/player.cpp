#include "../Headers/player.h"
#include "../Headers/game.h"

#define playerX WIDTH/2
#define playerY HEIGHT/1.3

void Player::createPlayer(SDL_Renderer *renderer, int taille, SDL_Color color) {
    /*
     * Dessine un cercle plein
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer,  WIDTH/2 + dx, HEIGHT/1.3 + dy);
            }
        }
    }*/

    //LE JOUEUR
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect player;
    player.x = playerX, player.y = playerY, player.w = taille; player.h = taille;
    SDL_RenderDrawRect(renderer, &player);

    //TODO : LE CONE DE VISION



}

void Player::drawPlayer(SDL_Renderer *renderer, int radius, SDL_Color color) {

}
