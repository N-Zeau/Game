#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "SDL2/SDL.h"
#include "iostream"

struct rectangle {
    int xMin;
    int yMin;
    int xMax;
    int yMax;
    int type;
};

struct s_liste {
    rectangle piece;
    s_liste *next;

};
typedef s_liste *liste_t;


class Map {
public:
    int WIDTH;
    int HEIGHT;
    int nbCase;
    char **tabMap;
    int nbL;
    int nbC;
    int sizeTextureOnScreenWidth;
    int sizeTextureOnScreenHeight;

    struct rectangle *mapCoordinate;
    liste_t pieces;

    /*
     * Cette fonction dessine la map sur la fenêtre
     * @apram SDL_Renderer, le renderer de la fenêtre
     */
    void drawMap(SDL_Renderer *renderer);

    /*
    * Cette fonction charge une image dans une texture et renvoie cette texture
    * @param const char *nomfichier, chemin relatif du fichier
    * @param SDL_Renderer le renderer de la fenêtre
    * @return retourne la texture à partir de l'image
    */
    SDL_Texture *chargerImage(const char *nomFichier, SDL_Renderer *renderer);

    /*
     * Cette fonction importe la map d'un fichier txt dans un tableau/une matrice
     * @return retourne le tableau
     */
    char **importMap();

    /*
     * Cette fonction initialise la map
     */
    void initialise();

    /*
     * Cette fonction verifie si la liste est vide
     * @param s_liste liste, la liste à verifier
     * @return un boolean si la liste est vide ou non
     */
    bool isEmpty(s_liste *liste);

    /*
     * Cette fonction créer une liste vide
     */
    liste_t l_empty();

    /*
     * Cette fonction ajoute un piece à la liste
     * @param rectangle piece, la piece à ajouter
     * @param liste_l la liste dans laquelle il faut ajouter la piece
     * @return la nouvelle liste modifié
     */
    liste_t add(rectangle piece, liste_t L);

    /*
     * Cette fonction lit le prochaine élément de la liste
     * @param liste_l L, la liste à utiliser
     * @return la nouvelle liste modifié
     */
    liste_t next(liste_t L);

    /*
     * Cette fonction supprime le dernier élément de la liste
     * @param liste_l L, la liste à utiliser
     */
    void del(liste_t L);

    /*
     * Cette fonction modifie un caractère du tableau fait à partir du fichier d'entrée
     * @param int n, indice de la colonne
     * @param int m, indice de la ligne
     */
    void changeFichier(int n, int m);
};


#endif //GAME_MAP_H
