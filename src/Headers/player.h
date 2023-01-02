#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <SDL2/SDL.h>
#include "map.h"
#include <vector>

class Player {

public:
    float playerX;
    float playerY;
    float angle;
    int playerSize;
    float Render3DSize;
    SDL_Color playerColor;
    SDL_Rect rectGunFPS = {0, 0, 733, 526};
    SDL_Rect rectGunScreen = {645, 420, 418, 300};
    SDL_Texture *gun;

    /*
     * Cette fonction créer et affiche le conne de vision du joueur sur la minimap
     * @param SDL_Renderer le renderer de la fenêtre
     * @param Map la map dans laquelle la vision sera créée
     * @return return un tableau de double
     */
    std::vector<double> visionPlayer(SDL_Renderer *renderer, Map map);

    /*
     * Cette fonction initialise le joueur
     * @param SDL_Renderer le renderer de la fenêtre
     * @param Map la map dans laquelle le joueur sera créer
     */
    void initPlayer(SDL_Renderer *renderer, Map map);

    /*
     * Cette fonction retourne la les coordonnées du carré dans lequel le point (x,y) se situe
     * @param float x, abscisse
     * @param float y, ordonnée
     * @return return un rectangle
     */
    rectangle *rectHere(Map map, float x, float y);

    /*
     * Cette fonction mets à jour le joueur
     * @param SDL_Renderer le renderer de la fenêtre
     */
    void updatePlayer(SDL_Renderer *renderer);

    /*
     * Cette fonctionn affiche la vision 3D du joueur
     * @param SDL_Renderer le renderer de la fenêtre
     * @param Map, map utilisé pour génrer la vision 3D
     */
    void vision3DPlayer(SDL_Renderer *renderer, Map map);

    /*
     * Cette fonction charge une image dans une texture et renvoie cette texture
     * @param const char *nomfichier, chemin relatif du fichier
     * @param SDL_Renderer le renderer de la fenêtre
     * @return retourne la texture à partir de l'image
     */
    SDL_Texture *chargerImage(const char *nomFichier, SDL_Renderer *renderer);

    /*
     * Cette fonction verifie la collision du joueur avec un piece
     * @param Map, map dans laquelle est le joueur
     * @return return si le joueur est en collision avec la piece ou non
     */
    bool collisionPiece(Map map, int speed, int sens);

    /*
     * Cette fonction enlève la piece de la map
     * @param Map, map dans laquelle il y a le joueur les pieces et le joueur
     * @param int speed, vitesse du joueur
     * @param int sens, sens dans lequel arrive le joueur sur un bloc
     */
    void attrapePiece(Map map, int speed, int sens);

};

#endif //GAME_PLAYER_H
