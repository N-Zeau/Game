#include "../Headers/player.h"
#include <cmath>
#include <vector>

std::vector<double> Player::visionPlayer(SDL_Renderer *renderer, Map map) {
    //LE CONE DE VISION

    // Le point (repereX, repereY) est le point au milieu de joueur (Centre du joueur)
    int repereX = playerX + playerSize / 2;
    int repereY = playerY + playerSize / 2;

    //Couleur du cône
    SDL_SetRenderDrawColor(renderer, playerColor.r, playerColor.g, playerColor.b, playerColor.a);

    //Récupère le carré où est le joueur et ceux adjacents
    rectangle *playerRect = rectHere(map, playerX, playerY);


    Render3DSize = 1280;  //Largeur de fentre de rendu
    std::vector<double> collision(Render3DSize);//Tableau des Points qui va créer la vision 3D du jouer
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
        const float fov = 68 * M_PI / 180; //Champ de vision du joueur en Radians

        //Affiche chaques lignes qui compose le cône
        for (int i = 0; i < (int) Render3DSize; i++) {
            float beta = alpha - fov / 2. + i / Render3DSize * fov;
            int t = 0;
            float x = repereX + std::cos(beta) * t;
            float y = repereY + std::sin(beta) * t;
            rectangle *pointRect = rectHere(map, x, y);

            //Afficher le cone avec la colision contre le mur
            while (pointRect[0].type == 0 && t < map.WIDTH) {
                x = repereX + std::cos(beta) * t;
                y = repereY + std::sin(beta) * t;
                t += 5;
                pointRect = rectHere(map, x, y);
                SDL_RenderDrawPoint(renderer, x, y);
            }
            //Calcul distance entre le joueur la droite i qui s'arrête contre le mur
            //Pythagore :  AB² + BC² = AC²,  AC : Distance recherché
            double AB2 = pow(std::abs(x - repereX), 2);
            double BC2 = pow(std::abs(y - repereY), 2);
            double distVision = std::sqrt(AB2 + BC2);
            collision[i] = distVision * std::cos(alpha - beta);
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

void Player::updatePlayer(SDL_Renderer *renderer) {
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

void Player::vision3DPlayer(SDL_Renderer *renderer, Map map) {
    //Rendu 3D
    auto view3D = visionPlayer(renderer, map);

    constexpr double wall_max = 720;
    for (int i = 0; i < (int) Render3DSize; i++) {
        double wallSize = round(wall_max / (1 + view3D[i] / 100.) / 2);

        //trace le contour en haut et en bas du mur en noir
        for (int j = 0; j < 3; ++j) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderDrawPoint(renderer, i, 360 + wallSize + j);
            SDL_RenderDrawPoint(renderer, i, 360 - wallSize - j);
        }
        //Trace les lignes verticales de la vision 3D
        SDL_SetRenderDrawColor(renderer, 255 - view3D[i] * 0.7, 255 - view3D[i] * 0.7, 255 - view3D[i] * 0.7, 255);
        SDL_RenderDrawLine(renderer, i, 360 + wallSize, i, 360 - wallSize);
    }

    //Crosshair
    int xCross = Render3DSize/2;
    int yCross = 720/2;
    int sizeCross = 10;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, xCross, yCross + sizeCross, xCross, yCross - sizeCross);
    SDL_RenderDrawLine(renderer, xCross - sizeCross, yCross, xCross + sizeCross, yCross);

}


