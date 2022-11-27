#include "../Headers/player.h"

void Player::visionPlayer(SDL_Renderer *renderer, Map map, Player player) {

    //LE CONE DE VISION
    //Récupération des coordonnées de la souris
    int mouseX;
    int mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    //Permet de placer le " repère " de la droite au centre du joueur
    mouseX -= playerSize/2;
    mouseY -= playerSize/2;

    //Demi-Droite d'équation y = a*x + b du centre du joueur passant par les coordonées de la souris
    //Calcul de a (Coef directeur) et b
    double a = (mouseX != playerX ? ((mouseY - playerY) / (mouseX - playerX)) : 1);
    double b = playerY - a * playerX;
    int mouseCompareY = (mouseY > playerY ? 1 : 0);
    int mouseCompareX = (mouseX > playerX ? 1 : 0);

    int repereX = playerX + playerSize/2;
    int repereY = playerY + playerSize/2;



    //Affichage de la droite directrice
    //Couleur de la droite
    SDL_SetRenderDrawColor(renderer, playerColor.r, playerColor.g, playerColor.b, playerColor.a);

    if (mouseY == playerY) {
        SDL_RenderDrawLine(renderer, repereX, repereY,
                           map.WIDTH * mouseCompareX + playerSize/2, repereY);

    } else if (mouseX == playerX) {
        SDL_RenderDrawLine(renderer, repereX, repereY,
                           repereX, map.HEIGHT * mouseCompareY + playerSize/2);

    } else {
        SDL_RenderDrawLine(renderer, repereX, repereY,
                           ((map.HEIGHT * mouseCompareY - b) / a) + playerSize/2,
                           ((map.HEIGHT * mouseCompareY) + playerSize/2));
    }

    SDL_SetRenderDrawColor(renderer, 40, 55, 71, SDL_ALPHA_OPAQUE);

}

void Player::initPlayer(SDL_Renderer *renderer, Map map) {
    //Valeur du joueur par défaut
    playerColor = {250, 128, 114, 255};
    playerSize = 10;
    playerX = (map.WIDTH / 2) - playerSize / 2;
    playerY = (map.HEIGHT / 2) - playerSize / 2;

    //LE JOUEUR
    SDL_SetRenderDrawColor(renderer, playerColor.r, playerColor.g, playerColor.b, playerColor.a);
    SDL_Rect playerRect;
    playerRect.x = playerX, playerRect.y = playerY;
    playerRect.w = playerSize, playerRect.h = playerSize;
    SDL_RenderDrawRect(renderer, &playerRect);
}

void Player::updatePlayer(SDL_Renderer *renderer, Map map) {

    //LE JOUEUR
    SDL_SetRenderDrawColor(renderer, playerColor.r, playerColor.g, playerColor.b, playerColor.a);
    SDL_Rect playerRect;
    playerRect.x = playerX, playerRect.y = playerY;
    playerRect.w = playerSize, playerRect.h = playerSize;
    SDL_RenderDrawRect(renderer, &playerRect);
}





void Player::movePlayer(SDL_Renderer *renderer, Map map) {
    float speed = 4;

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

rectangle *Player::rectHere(SDL_Renderer *renderer, int x, int y, Map map) {
    rectangle* mapCoord = new rectangle[4];

    for (int i = 0; i < sizeof(&map.mapCoordinate); ++i) {
        if (map.mapCoordinate->type == 1){
            if (x >= map.mapCoordinate->xMin &&
                y >= map.mapCoordinate->yMin &&
                x <= map.mapCoordinate->xMax &&
                y <= map.mapCoordinate->yMax)
                continue;
        }
    }

}


