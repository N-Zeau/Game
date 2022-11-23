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
    //Couleur de la droite
    SDL_SetRenderDrawColor(renderer, playerColor.r, playerColor.g, playerColor.b, playerColor.a);

    if (mouseY == playerY) {
        SDL_RenderDrawLine(renderer, playerX + playerTaille / 2, playerY + playerTaille / 2,
                           map.WIDTH * mouseCompareX, playerY);

    } else if (mouseX == playerX) {
        SDL_RenderDrawLine(renderer, playerX + playerTaille / 2, playerY + playerTaille / 2,
                           playerX, map.HEIGHT * mouseCompareY);

    } else {
        SDL_RenderDrawLine(renderer, playerX + playerTaille / 2, playerY + playerTaille / 2,
                           ((map.HEIGHT * mouseCompareY - b) / a), map.HEIGHT * mouseCompareY);
    }

    SDL_SetRenderDrawColor(renderer, 40, 55, 71, SDL_ALPHA_OPAQUE);

}

void Player::initPlayer(SDL_Renderer *renderer, Map map) {
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

}

void Player::updatePlayer(SDL_Renderer *renderer, Map map) {

    //LE JOUEUR
    SDL_SetRenderDrawColor(renderer, playerColor.r, playerColor.g, playerColor.b, playerColor.a);
    SDL_Rect playerRect;
    playerRect.x = playerX, playerRect.y = playerY;
    playerRect.w = playerTaille, playerRect.h = playerTaille;
    SDL_RenderDrawRect(renderer, &playerRect);
}


void Player::moovePlayer(SDL_Renderer *renderer, Map map) {
    float speed = 8;

    //LES MOUVEMENTS DU JOUEUR
    SDL_Event keyboard;
    if (SDL_WaitEvent(&keyboard)) {
        if (keyboard.type == SDL_KEYDOWN) {
            switch (keyboard.key.keysym.sym) {
                case SDLK_UP:
                    playerY -= speed;
                    break;
                case SDLK_DOWN:
                    playerY += speed;
                    break;
                case SDLK_LEFT:
                    playerX -= speed;
                    break;
                case SDLK_RIGHT:
                    playerX += speed;
                    break;
            }
        }
    }
}


