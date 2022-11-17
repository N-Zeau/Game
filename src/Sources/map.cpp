#include "../Headers/map.h"

SDL_Texture *Map::chargerImage(const char *nomFichier, SDL_Renderer* renderer) {
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

void Map::drawMap(SDL_Renderer* renderer, char **map) {
    int nbL;
    int nbC;
    char **tabMap = importMap(&nbL, &nbC);

    int sizeTexture = 64; //Vrai taille de la texture
    int sizeTextureOnScreenWidth = WIDTH / nbC; //Taille de la largeur de la texture affiché sur la fenêtre
    int sizeTextureOnScreenHeight = HEIGHT / nbL; //Taille de la hauteur de la texture affiché sur la fenêtre

    //Import du fichier Mur dans une texture
    SDL_Texture *wall = chargerImage("../Map/Mur.bmp", renderer);

    SDL_Rect rectSrc[nbC * nbL];  //Rectangle correspondant à la source du pavé (Celui affiché)
    SDL_Rect rect[nbC * nbL]; //Position et dimaension du Rectangle qui va être afficher dans la fenêtre
    int compteur = 0;


    for (int i = 0; i < nbC; i++) {
        for (int j = 0; j < nbL; j++) {
            rect[compteur].x = i * sizeTextureOnScreenWidth, rect[compteur].y = j * sizeTextureOnScreenHeight;
            rect[compteur].w = sizeTextureOnScreenWidth, rect[compteur].h = sizeTextureOnScreenHeight;

            switch (tabMap[j][i]) {
                case '1':
                    rectSrc[compteur].x = 0, rectSrc[compteur].y = 0;
                    rectSrc[compteur].w = sizeTexture, rectSrc[compteur].h = sizeTexture;
                    break;
                case ' ':
                    rectSrc[compteur].x = 0, rectSrc[compteur].y = 0;
                    rectSrc[compteur].w = 0, rectSrc[compteur].h = 0;
                    break;
            }
            compteur++;
        }
    }

    SDL_RenderClear(renderer);

    for (int i = 0; i < nbC * nbL; ++i)
        SDL_RenderCopy(renderer, wall, &rectSrc[i], &rect[i]);

    SDL_RenderPresent(renderer);
}

char **Map::importMap(int *nbL, int *nbC) {
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
    nbLigne++; // TODO
    *nbL = nbLigne;
    *nbC = nbColonneTemp;

    rewind(mapTxt);

    //Allocation de la mémoire de la map
    char **map = (char **) malloc(sizeof(char *) * nbLigne);
    for (int i = 0; i < nbLigne; i++) {
        map[i] = (char *) malloc(sizeof(char) * nbColonne);
    }

    //Création de la map vide (Tableau de char vide)
    for (int i = 0; i < nbLigne; i++)
        for (int j = 0; j < nbColonneTemp; j++)
            map[i][j] = ' ';

    int ligne = 0;
    int colonne = 0;
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
    fclose(mapTxt);
    return map;

}




