#include "../Headers/player.h"
#include "../Headers/game.h"

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

    //Le point (playerX, playerY) devient le centre du joueur
    playerX += taillePlayer / 2;
    playerY += taillePlayer / 2;
    //Calcul de a et b
    double a = (mouseX != playerX ? ((mouseY - playerY) / (mouseX - playerX)) : 1);
    double b = playerY - a * playerX;

    int x2 = 0, y2 = 0;

    int mouseCompareY = (mouseY > playerY ? 1 : 0); //Variable ternaire
    int mouseCompareX = (mouseX < playerX ? 1 : 0); //Variable ternaire

//Affichage de la droite directrice
    //Différenciation des cas en fonction de la position de la souris à partir de la formule
    if (mouseY == playerY)
        SDL_RenderDrawLine(renderer, playerX, playerY,
                           WIDTH*mouseCompareX, playerY);

    if(mouseX == playerX) {
        SDL_RenderDrawLine(renderer, playerX, playerY,
                           playerX, HEIGHT * mouseCompareY);

    }else
        SDL_RenderDrawLine(renderer, playerX, playerY,
                       ((HEIGHT * mouseCompareY - b) / a), HEIGHT * mouseCompareY);
    //Fin de la gestion de l'affichage de la demi-droite directrice

}