#include "../Headers/player.h"
#include "../Headers/game.h"
#include <cmath>

void Player::createPlayer(SDL_Renderer *renderer, int taillePlayer, SDL_Color color) {
    float playerX = (WIDTH / 2) - taillePlayer / 2;
    float playerY = (HEIGHT / 1.3) - taillePlayer / 2;

    //LE JOUEUR
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect player;
    player.x = playerX, player.y = playerY;
    player.w = taillePlayer, player.h = taillePlayer;
    SDL_RenderDrawRect(renderer, &player);

    //LE CONE DE VISION
    //Récupération des coordonnées de la souris
    int mouseX;
    int mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    //Demi-Droite d'équation y = a*x + b du centre du joueur passant par les coordonées de la souris
    playerX += taillePlayer / 2;
    playerY += taillePlayer / 2;
    double a = (mouseY - playerY) / (mouseX - playerX);
    double b = playerY - a * playerX;

    //Affichage de la demi-droite directrice en fonction de la position de la souris
    if (mouseY < playerY) {
        SDL_RenderDrawLine(renderer, playerX, playerY,
                           (-b / a), 0);
    } else {
        if (mouseY > playerY) {
            SDL_RenderDrawLine(renderer, playerX, playerY,
                               ((HEIGHT - b) / a), HEIGHT);
        } else {
            if (mouseY == playerY && mouseX >= playerX)
                SDL_RenderDrawLine(renderer, playerX, playerY,
                                   WIDTH, playerY);
            if (mouseY == playerY && mouseX < playerX)
                SDL_RenderDrawLine(renderer, playerX, playerY,
                                   0, playerY);
        }
    }
    if (mouseX == playerX && mouseY <= playerY)
        SDL_RenderDrawLine(renderer, playerX, playerY,
                           playerX, 0);
    if (mouseX == playerX && mouseY > playerY)
        SDL_RenderDrawLine(renderer, playerX, playerY,
                           playerX, HEIGHT);
    //Fin de la gestion de l'affichage de la demi-droite directrice

}
