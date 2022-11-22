#include "../Headers/player.h"

void Player::createPlayer(SDL_Renderer *renderer, Map map, int taillePlayer, SDL_Color color) {

    float playerX = (map.WIDTH / 2) - taillePlayer / 2;
    float playerY = (map.HEIGHT / 1.4) - taillePlayer / 2;
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
    //Calcul de a (Coef directeur) et b
    double a = (mouseX != playerX ? ((mouseY - playerY) / (mouseX - playerX)) : 1);
    double b = playerY - a * playerX;
    int mouseCompareY = (mouseY > playerY ? 1 : 0); //Variable ternaire
    int mouseCompareX = (mouseX > playerX ? 1 : 0); //Variable ternaire

    //Affichage de la droite directrice
    if (mouseY == playerY)
        SDL_RenderDrawLine(renderer, playerX, playerY,
                           map.WIDTH*mouseCompareX, playerY);

    if(mouseX == playerX) {
        SDL_RenderDrawLine(renderer, playerX, playerY,
                           playerX, map.HEIGHT * mouseCompareY);

    }else{SDL_RenderDrawLine(renderer, playerX, playerY,
                       ((map.HEIGHT * mouseCompareY - b) / a), map.HEIGHT * mouseCompareY);
    }
    
    //Mouvement du joueur
    
    
}