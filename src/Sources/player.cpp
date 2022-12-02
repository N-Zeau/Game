#include "../Headers/player.h"
#include <cmath>

int *Player::visionPlayer(SDL_Renderer *renderer, Map map, Player player) {
    //LE CONE DE VISION

    // Le point (repereX, repereY) est le point au milieu de joueur (Centre du joueur)
    int repereX = playerX + playerSize / 2;
    int repereY = playerY + playerSize / 2;

    //Couleur du cône
    SDL_SetRenderDrawColor(renderer, playerColor.r, playerColor.g, playerColor.b, playerColor.a);

    //Récupère le carré où est le joueur et ceux adjacents
    rectangle *playerRect = player.rectHere(map, playerX, playerY);


    float sizeRender = 100;  //Largeur de fentre de rendu
    int *collision = (int *) malloc(
            sizeRender * sizeof(int)); //Tableau des Points qui va créer la vision 3D du jouer

    //Affiche le cône si le joueur n'est pas dans un mur
    if (playerRect[0].type == 0) {
        //Récupération des coordonnées de la souris
        int mouseX;
        int mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        float dx = mouseX - repereX;
        float dy = mouseY - repereY;
        float len = std::sqrt(dx * dx + dy * dy);
        dx /= len;
        dy /= len;
        float alpha = std::atan2(dy, dx);
        const float fov = M_PI / 2.5; //Champ de vision du joueur en Radians

        //Affiche chaques lignes qui compose le cône
        for (int i = 0; i < (int) sizeRender; i++) {
            float beta = alpha - fov / 2. + i / sizeRender * fov;
            int t = 0;
            float x = repereX + std::cos(beta) * t;
            float y = repereY + std::sin(beta) * t;
            rectangle *pointRect = player.rectHere(map, x, y);

            //Afficher le cone avec la colision contre le mur
            while (pointRect[0].type == 0 && t < map.WIDTH) {
                x = repereX + std::cos(beta) * t;
                y = repereY + std::sin(beta) * t;
                SDL_RenderDrawPoint(renderer, x, y);
                t += 2;
                pointRect = player.rectHere(map, x, y);
            }
            SDL_Point pointCol;
            pointCol.x = x;
            pointCol.y = y; //Point de collision en la vision est le mur
            //Calcul distance entre le joueur la droite i qui s'arrête contre le mur
            //Pythagore :  AB² + BC² = AC²,  AC : Distance recherché
            int AB2 = x - repereX;
            int BC2 = y - repereY;
            int distVision = std::abs(std::sqrt(AB2 + BC2));
            collision[i] = distVision;
        }

    }
    //Remet la couleur du background
    SDL_SetRenderDrawColor(renderer, 40, 55, 71, SDL_ALPHA_OPAQUE);
    return collision;
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

void Player::updatePlayer(SDL_Renderer *renderer, Player player) {
    //LE JOUEUR
    SDL_SetRenderDrawColor(renderer, playerColor.r, playerColor.g, playerColor.b, playerColor.a);
    SDL_Rect playerRect;
    playerRect.x = playerX, playerRect.y = playerY;
    playerRect.w = playerSize, playerRect.h = playerSize;
    SDL_RenderDrawRect(renderer, &playerRect);
}

rectangle *Player::rectHere(Map map, float x, float y) {
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

void Player::vision3DPlayer(SDL_Renderer *renderer, Map map, Player player, int *collisionPoint) {
    //
}


