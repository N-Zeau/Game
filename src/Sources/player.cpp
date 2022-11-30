#include "../Headers/player.h"
#include <cmath>

void Player::visionPlayer(SDL_Renderer *renderer, Map map, Player player) {

    //LE CONE DE VISION
    //Récupération des coordonnées de la souris
    int mouseX;
    int mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    //Permet de placer le " repère " de la droite au centre du joueur
    mouseX -= playerSize / 2;
    mouseY -= playerSize / 2;

    //Demi-Droite d'équation y = a*x + b du centre du joueur passant par les coordonées de la souris
    //Calcul de a (Coef directeur) et b
    double a = (mouseX != playerX ? ((mouseY - playerY) / (mouseX - playerX)) : 1);
    double b = playerY - a * playerX;
    int mouseCompareY = (mouseY > playerY ? 1 : 0);
    int mouseCompareX = (mouseX > playerX ? 1 : 0);

    int repereX = playerX + playerSize / 2;
    int repereY = playerY + playerSize / 2;

    //Affichage de la droite directrice
    //Couleur de la droite
    SDL_SetRenderDrawColor(renderer, playerColor.r, playerColor.g, playerColor.b, playerColor.a);

    //Récupère le carré où est le joueur et ceux adjacents
    rectangle *playerRect = player.rectHere(renderer, map, playerX, playerY);

    //Affiche la droite si le joueur n'est pas dans un mur
    if (playerRect[0].type == 0) {
        /*
        if (mouseY == playerY) {
            SDL_RenderDrawLine(renderer, repereX, repereY,
                               map.WIDTH * mouseCompareX + playerSize / 2, repereY);

        } else if (mouseX == playerX) {
            SDL_RenderDrawLine(renderer, repereX, repereY,
                               repereX, map.HEIGHT * mouseCompareY + playerSize / 2);

        } else {
            SDL_RenderDrawLine(renderer, repereX, repereY,
                               ((map.HEIGHT * mouseCompareY - b) / a) + playerSize / 2,
                               ((map.HEIGHT * mouseCompareY) + playerSize / 2));
        }
        */
        float dx = mouseX - repereX;
        float dy = mouseY - repereY;
        float len = std::sqrt(dx * dx + dy * dy);
        dx /= len;
        dy /= len;
        float alpha = std::atan2(dy, dx);
        const float fov = 1.7530987;

        for (int i = 0; i < 100; i++) { // largeur de fentre de rendu
            float beta = alpha - fov / 2. + i / 100. * fov;
            for (float t = 0; t < 1000; t += 5) {
                float x = repereX + std::cos(beta) * t;
                float y = repereY + std::sin(beta) * t;
                rectangle *pointRect = player.rectHere(renderer, map, x, y);
                if (pointRect[0].type == 0) {
                    SDL_RenderDrawPoint(renderer, x, y);
                }
            }
        }

        //Remet la couleur du background
        SDL_SetRenderDrawColor(renderer, 40, 55, 71, SDL_ALPHA_OPAQUE);
    }

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
    float speed = 8;

    //LES MOUVEMENTS DU JOUEUR
    Event move{};
    if (SDL_WaitEvent(&move.event)) {
        if (move.event.type == SDL_KEYDOWN) {
            switch (move.event.key.keysym.sym) {
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

rectangle *Player::rectHere(SDL_Renderer *renderer, Map map, int x, int y) {
    rectangle *mapCoord = new rectangle[5]; // rectangle joueur, haut, droite, bas, gauche

    int wRect = map.mapCoordinate[0].xMax - map.mapCoordinate[0].xMin;
    int hRect = map.mapCoordinate[0].yMax - map.mapCoordinate[0].yMin;

    for (int i = 0; i < map.nbCase; ++i) {
        if (x >= map.mapCoordinate[i].xMin && x <= map.mapCoordinate[i].xMax &&
            y >= map.mapCoordinate[i].yMin && y <= map.mapCoordinate[i].yMax) {

            //Rectangle où se situe le joueur
            mapCoord[0] = map.mapCoordinate[i];

            //Rectangle au dessus de joueur
            mapCoord[1] = rectangle{
                    map.mapCoordinate[i].xMin,
                    map.mapCoordinate[i].yMin - hRect,
                    map.mapCoordinate[i].xMax,
                    map.mapCoordinate[i].yMax - hRect,
                    map.mapCoordinate[i].type,
            };

            //Rectangle à droite du joueur
            mapCoord[2] = rectangle{
                    map.mapCoordinate[i].xMin + wRect,
                    map.mapCoordinate[i].yMin,
                    map.mapCoordinate[i].xMax + wRect,
                    map.mapCoordinate[i].yMax,
                    map.mapCoordinate[i].type,
            };

            //Rectangle en bas du joueur
            mapCoord[3] = rectangle{
                    map.mapCoordinate[i].xMin,
                    map.mapCoordinate[i].yMin + hRect,
                    map.mapCoordinate[i].xMax,
                    map.mapCoordinate[i].yMax + hRect,
                    map.mapCoordinate[i].type,
            };

            //Rectangle à gauche du joueur
            mapCoord[4] = rectangle{
                    map.mapCoordinate[i].xMin - wRect,
                    map.mapCoordinate[i].yMin,
                    map.mapCoordinate[i].xMax - wRect,
                    map.mapCoordinate[i].yMax,
                    map.mapCoordinate[i].type,
            };

            /*
            // Affiche la case où le joueur se situe
            std::cerr << "Le joueur est dans le rectangle : {(xMin) " << map.mapCoordinate[i].xMin
                      << ", (yMin) " << map.mapCoordinate[i].yMin
                      << ", (xMax) " << map.mapCoordinate[i].xMax
                      << ", (yMax) " << map.mapCoordinate[i].yMax
                      << "}" << std::endl;
            */
        }
    }
    return mapCoord;
}