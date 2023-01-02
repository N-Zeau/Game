#include "../Headers/player.h"
#include <cmath>
#include <vector>

/*
 * Cette fonction créer et affiche le conne de vision du joueur sur la minimap
 * @param SDL_Renderer le renderer de la fenêtre
 * @param Map la map dans laquelle la vision sera créée
 * @return return un tableau de double
 */
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
    if (playerRect[0].type != 1) {
        const float fov = 68 * M_PI / 180; //Champ de vision du joueur en Radians

        //Affiche chaques lignes qui compose le cône
        for (int i = 0; i < (int) Render3DSize; i += 3) {
            float beta = angle - fov / 2. + i / Render3DSize * fov;
            int t = 0;
            float x = repereX + std::cos(beta) * t;
            float y = repereY + std::sin(beta) * t;
            rectangle *pointRect = rectHere(map, x, y);

            //Affiche le cone de vison
            while (pointRect[0].type == 0) {
                x = repereX + std::cos(beta) * t;
                y = repereY + std::sin(beta) * t;
                t += 3; // Plus le chiffre est bas, plus la qualité du Rendu augmente.
                pointRect = rectHere(map, x, y);
                SDL_RenderDrawPoint(renderer, x, y);
            }
            //Calcul distance entre le joueur la droite i qui s'arrête contre le mur
            //Pythagore :  AB² + BC² = AC²,  AC : Distance recherché
            double ABsquare = pow(std::abs(x - repereX), 2);
            double BCsquare = pow(std::abs(y - repereY), 2);
            double distVision = std::sqrt(ABsquare + BCsquare);
            collision[i] = distVision * std::cos(angle - beta);
        }

    }
    return collision;
}

/*
 * Cette fonctionn affiche la vision 3D du joueur
 * @param SDL_Renderer le renderer de la fenêtre
 * @param Map, map utilisé pour génrer la vision 3D
 */
void Player::vision3DPlayer(SDL_Renderer *renderer, Map map) {
    //Rendu 3D
    auto view3D = visionPlayer(renderer, map);

    constexpr double wall_max = 720;
    for (int i = 0; i < (int) Render3DSize; i += 3) {
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
    int xCross = Render3DSize / 2;
    int yCross = 720 / 2;
    int sizeCross = 10;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, xCross, yCross + sizeCross, xCross, yCross - sizeCross);
    SDL_RenderDrawLine(renderer, xCross - sizeCross, yCross, xCross + sizeCross, yCross);

    //Arme du joueur
    SDL_RenderCopy(renderer, gun, &rectGunFPS, &rectGunScreen);

}

/*
 * Cette fonction initialise le joueur
 * @param SDL_Renderer le renderer de la fenêtre
 * @param Map la map dans laquelle le joueur sera créer
 */
void Player::initPlayer(SDL_Renderer *renderer, Map map) {
    //Valeur du joueur par défaut
    playerColor = {250, 128, 114, 255};
    playerSize = 10;
    angle = 0;
    playerX = (map.WIDTH / 2) - playerSize / 2;
    playerY = (map.HEIGHT / 2) - playerSize / 2;


    //LE JOUEUR
    SDL_SetRenderDrawColor(renderer, playerColor.r, playerColor.g, playerColor.b, playerColor.a);
    SDL_Rect playerRect;
    playerRect.x = playerX, playerRect.y = playerY;
    playerRect.w = playerSize, playerRect.h = playerSize;
    SDL_RenderDrawRect(renderer, &playerRect);

    //Charge l'image de l'arme du joueur
    gun = chargerImage("../Ressources/GamePlay/GunFPS.bmp", renderer);

}

/*
 * Cette fonction mets à jour le joueur
 * @param SDL_Renderer le renderer de la fenêtre
 */
void Player::updatePlayer(SDL_Renderer *renderer) {
    //LE JOUEUR
    SDL_SetRenderDrawColor(renderer, playerColor.r, playerColor.g, playerColor.b, playerColor.a);
    SDL_Rect playerRect;
    playerRect.x = playerX, playerRect.y = playerY;
    playerRect.w = playerSize, playerRect.h = playerSize;
    SDL_RenderDrawRect(renderer, &playerRect);
}

/*
 * Cette fonction retourne la les coordonnées du carré dans lequel le point (x,y) se situe
 * @param float x, abscisse
 * @param float y, ordonnée
 * @return return un rectangle
 */
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

/*
  * Cette fonction charge une image dans une texture et renvoie cette texture
  * @param const char *nomfichier, chemin relatif du fichier
  * @param SDL_Renderer le renderer de la fenêtre
  * @return retourne la texture à partir de l'image
  */
SDL_Texture *Player::chargerImage(const char *nomFichier, SDL_Renderer *renderer) {
    SDL_Surface *player = nullptr;
    player = SDL_LoadBMP(nomFichier);

    if (player == nullptr) {
        std::cout << "Echec du chargement du player : " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture *texture = nullptr;
    texture = SDL_CreateTextureFromSurface(renderer, player);

    if (texture == nullptr) {
        std::cout << "Echec du chargement de la texture : " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_FreeSurface(player);
    return texture;

}

/*
 * Cette fonction verifie la collision du joueur avec un piece
 * @param Map, map dans laquelle est le joueur
 * @return return si le joueur est en collision avec la piece ou non
 */
bool Player::collisionPiece(Map map, int speed, int sens) {
    for (int i = 0; i < map.nbCase; i++) {
        if (sens == 0) {
            if (rectHere(map, playerX + speed + playerSize, playerY)->type == 2
                || rectHere(map, playerX + speed + playerSize, playerY + playerSize)->type == 2) {
                return true;
            }
        } else if (sens == 1) {
            if (rectHere(map, playerX - speed, playerY)->type == 2
                || rectHere(map, playerX - speed, playerY + playerSize)->type == 2) {
                return true;
            }
        } else if (sens == 2) {
            if (rectHere(map, playerX, playerY + playerSize + speed)->type == 2
                || rectHere(map, playerX + playerSize, playerY + playerSize + speed)->type == 2) {
                return true;
            }
        } else if (sens == 3) {
            if (rectHere(map, playerX, playerY - speed)->type == 2
                || rectHere(map, playerX + playerSize, playerY - speed)->type == 2) {
                return true;
            }
        }
    }
    return false;
}


/*
 * Cette fonction enlève la piece de la map
 * @param Map, map dans laquelle il y a le joueur les pieces et le joueur
 * @param int speed, vitesse du joueur
 * @param int sens, sens dans lequel arrive le joueur sur un bloc
 */
void Player::attrapePiece(Map map, int speed, int sens){
    rectangle *rect;
    switch (sens)
    {
        case 0:
            rect = rectHere(map, playerX + speed + playerSize, playerY);
            map.changeFichier((rect->xMin)/map.sizeTextureOnScreenWidth, ((rect->yMax)/map.sizeTextureOnScreenHeight));
            map.del(map.pieces);
            break;
        case 1:
            rect = rectHere(map, playerX - speed, playerY);
            map.changeFichier((rect->xMin)/map.sizeTextureOnScreenWidth, ((rect->yMax)/map.sizeTextureOnScreenHeight));
            map.del(map.pieces);
            break;
        case 2:
            rect = rectHere(map, playerX, playerY+ speed + playerSize);
            map.changeFichier((rect->xMin)/map.sizeTextureOnScreenWidth, ((rect->yMax)/map.sizeTextureOnScreenHeight));
            map.del(map.pieces);
            break;
        default:
            rect = rectHere(map, playerX, playerY-speed);
            map.changeFichier((rect->xMin)/map.sizeTextureOnScreenWidth, ((rect->yMax)/map.sizeTextureOnScreenHeight));
            map.del(map.pieces);
            break;
    }
}