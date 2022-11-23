#include "../Headers/player.h"

void Player::visionPlayer(SDL_Renderer *renderer, Map map, Player player) {

    //LE CONE DE VISION
    //Récupération des coordonnées de la souris
    int mouseX;
    int mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    //Demi-Droite d'équation y = a*x + b du centre du joueur passant par les coordonées de la souris
    //Calcul de a (Coef directeur) et b
    double a = (mouseX != playerX ? ((mouseY - playerY) / (mouseX - playerX)) : 1);
    double b = playerY - a * playerX;
    int mouseCompareY = (mouseY > playerY ? 1 : 0); //Variable ternaire
    int mouseCompareX = (mouseX > playerX ? 1 : 0); //Variable ternaire

    //Affichage de la droite directrice
    if (mouseY == playerY) {
        SDL_RenderDrawLine(renderer, playerX, playerY,
                           map.WIDTH * mouseCompareX, playerY);

    } else if (mouseX == playerX) {
        SDL_RenderDrawLine(renderer, playerX, playerY,
                           playerX, map.HEIGHT * mouseCompareY);

    } else {
        SDL_RenderDrawLine(renderer, playerX, playerY,
                           ((map.HEIGHT * mouseCompareY - b) / a), map.HEIGHT * mouseCompareY);
    }
}

void Player::initPlayer(SDL_Renderer* renderer, Map map) {
    //Valeur du joueur par défaut
    playerColor = {250, 128, 114, 255};
    playerTaille = 10;
    playerX = (map.WIDTH / 2) - playerTaille / 2;
    playerY = (map.HEIGHT / 1.4) - playerTaille / 2;

    //LE JOUEUR
    SDL_SetRenderDrawColor(renderer, playerColor.r, playerColor.g, playerColor.b, playerColor.a);
    SDL_Rect playerRect;
    playerRect.x = playerX, playerRect.y = playerY;
    playerRect.w = playerTaille, playerRect.h = playerTaille;
    SDL_RenderDrawRect(renderer, &playerRect);

    //Le point (playerX, playerY) devient le centre du joueur
    playerX += playerTaille / 2;
    playerY += playerTaille / 2;

}

void Player::moovePlayer(SDL_Renderer *renderer, Map map) {
    //LES MOUVEMENTS DU JOUEUR
}
