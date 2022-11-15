#include "../Headers/map.h"


SDL_Texture* Map::chargerImage(const char *nomFichier, SDL_Renderer *renderer) {
    SDL_Surface *wall = nullptr;
    wall = SDL_LoadBMP(nomFichier);

    if (wall == nullptr) {
        std::cout << "Echec du chargement de l'image : " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture *texture = nullptr;
    texture = SDL_CreateTextureFromSurface(renderer, wall);

    if (texture == nullptr) {
        std::cout << "Echec du chargement de la texture : " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_FreeSurface(wall);
    return texture;

}

void Map::drawMap(char **map) {
    Game game;

    int sizeTexture = 32; //Vrai taille de la texture
    int sizeTextureOnScreen = 64; //Taille de la texture affiché sur la fenêtre
    //Import du fichier Mur dans une texture
    SDL_Texture *wall = chargerImage("../Map/Mur.bmp", game.thisRenderer());

    SDL_Rect srcpave;  //Rectangle correspondant à la source du pavé
    srcpave.x = 0, srcpave.y = 0, srcpave.w = sizeTexture, srcpave.h = sizeTexture;
    SDL_Rect rect; //Rectangle qui va être afficher dans la fenêtre
    rect.x = 0, rect.y = 0, rect.w = sizeTextureOnScreen, rect.h = sizeTextureOnScreen;

    SDL_RenderClear(game.thisRenderer());
    SDL_RenderCopy(game.thisRenderer(), wall, &srcpave, &rect);
    SDL_RenderPresent(game.thisRenderer());
}
char** Map::importMap() {
    FILE *mapTxt = nullptr;
    mapTxt = fopen("../../Ressources/Map/map.txt", "r");

    char cara;
    int nbLigne = 0; //Nombres de Lignes dans le .txt
    int nbColonneTemp = 0;
    int nbColonne = 0; //Nombres de Colonnes dans le .txt

    //Recupération du nombre de lignes et de colonnes du fichier .txt
    if (mapTxt != nullptr) {
        do {
            cara = (char) fgetc(mapTxt);
            if (cara == '\n' || cara == '\r' || cara == EOF) {
                if (cara != EOF)
                    nbLigne++;
                if (nbColonneTemp > nbColonne)
                    nbColonne = nbColonneTemp;
                nbColonneTemp = 0;
            } else {
                nbColonneTemp++;
            }
        } while (cara != EOF);
        nbColonneTemp = nbColonne;

    }

    fclose(mapTxt);

    //Allocation de la mémoire de la map
    char **map = (char **) malloc(sizeof(char *) * nbLigne);
    for (int i = 0; i < nbLigne; i++) {
        map[i] = (char *) malloc(sizeof(char) * nbColonne);
    }

    //Création de la map vide (Tableau de char vide)
    for (int i = 0; i < nbLigne; i++)
        for (int j = 0; j < nbColonneTemp; j++)
            map[i][j] = ' ';

    int ligne;
    int colonne;
    char write;

    //Écriture de la map (Tableau rempli à partir du fichier .txt)
    if (mapTxt != nullptr) {
        do {
            write = (char) fgetc(mapTxt);
            if (write == '\n' || write == '\r' || write == EOF) {
                ligne++;
                colonne = 0;
            } else {
                map[ligne][colonne] = write;
                colonne++;
            }
        } while (write != EOF);

    }

    return map;

}




