#include "../Headers/player.h"
#include <cmath>

void Player::visionPlayer(SDL_Renderer *renderer, Map map, Player player) {

    //LE CONE DE VISION
    //Récupération des coordonnées de la souris
    int mouseX;
    int mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    // Le point (repereX, repereY) est le point au milieu de joueur
    int repereX = playerX + playerSize / 2;
    int repereY = playerY + playerSize / 2;

    //Couleur du cône
    SDL_SetRenderDrawColor(renderer, playerColor.r, playerColor.g, playerColor.b, playerColor.a);

    //Récupère le carré où est le joueur et ceux adjacents
    rectangle *playerRect = player.rectHere(renderer, map, playerX, playerY);

    //Affiche le cône si le joueur n'est pas dans un mur
    if (playerRect[0].type == 0) {
        float dx = mouseX - repereX;
        float dy = mouseY - repereY;
        float len = std::sqrt(dx * dx + dy * dy);
        dx /= len;
        dy /= len;
        float alpha = std::atan2(dy, dx);
        const float fov = 1.39626; //Champ de vision du joueur en Radians
        float sizeRender = 200;  //Largeur de fentre de rendu

        //Affiche chaques lignes qui compose le cône
        for (int i = 0; i < (int) sizeRender; i++) {
            float beta = alpha - fov / 2. + i / sizeRender * fov;
            int t = 0;
            float x = repereX + std::cos(beta) * t;
            float y = repereY + std::sin(beta) * t;
            rectangle *pointRect = player.rectHere(renderer, map, x, y);

            //Afficher le cone avec la colision contre le mur
            while (pointRect[0].type == 0 && t < map.WIDTH) {
                x = repereX + std::cos(beta) * t;
                y = repereY + std::sin(beta) * t;
                SDL_RenderDrawPoint(renderer, x, y);
                t += 2;
                pointRect = player.rectHere(renderer, map, x, y);
            }
        }
    }

    //Remet la couleur du background
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
    float speed = 5;

    //LES MOUVEMENTS DU JOUEUR
    Event move{};
    if (SDL_WaitEvent(&move.event)) {
        if (move.event.type == SDL_KEYDOWN) {
            switch (move.event.key.keysym.sym) {
                case SDLK_z:
                    playerY -= speed;
                    break;
                case SDLK_s:
                    playerY += speed;
                    break;
                case SDLK_q:
                    playerX -= speed;
                    break;
                case SDLK_d:
                    playerX += speed;
                    break;
            }
        }
    }
}

rectangle *Player::rectHere(SDL_Renderer *renderer, Map map, int x, int y) {
    rectangle *mapCoord = new rectangle[1]; // rectangle joueur, haut, droite, bas, gauche

    for (int i = 0; i < map.nbCase; ++i) {
        if (x >= map.mapCoordinate[i].xMin && x <= map.mapCoordinate[i].xMax &&
            y >= map.mapCoordinate[i].yMin && y <= map.mapCoordinate[i].yMax) {
            //Rectangle où se situe le joueur
            mapCoord[0] = map.mapCoordinate[i];
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