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
    SDL_Rect rect[nbC * nbL]; //Position et dimension du Rectangle qui va être affiché dans la fenêtre
    int compteur = 0;
    mapCoordinate = new rectangle[nbC*nbL];

    //Affichage de la map
    for (int i = 0; i < nbC; i++) {
        for (int j = 0; j < nbL; j++) {
            int type;
            //Rectangle qui divise la map
            int x = rect[compteur].x = i * sizeTextureOnScreenWidth;
            int y = rect[compteur].y = j * sizeTextureOnScreenHeight;
            int w = rect[compteur].w = sizeTextureOnScreenWidth;
            int h = rect[compteur].h = sizeTextureOnScreenHeight;

            switch (tabMap[j][i]) {
                case '2':
                    rectSrc[compteur].x = sizeTexture;
                    rectSrc[compteur].y = 0;
                    rectSrc[compteur].w = sizeTexture;
                    rectSrc[compteur].h = sizeTexture;
                    break;
                case '1':
                    rectSrc[compteur].x = 0;
                    rectSrc[compteur].y = 0;
                    rectSrc[compteur].w = sizeTexture;
                    rectSrc[compteur].h = sizeTexture;
                    type = 1;

                    break;
                case '0':
                case ' ':
                    rectSrc[compteur].x = 0;
                    rectSrc[compteur].y = 0;
                    rectSrc[compteur].w = 0;
                    rectSrc[compteur].h = 0;
                    type = 0;
                    break;
            }

            mapCoordinate[compteur] = rectangle{
                    x,
                    y,
                    x + w,
                    y + h,
                    type };

            compteur++;

            //Trace le cadrillage
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(renderer, 0, j*sizeTextureOnScreenHeight ,
                               WIDTH, j*sizeTextureOnScreenHeight);
            SDL_RenderDrawLine(renderer, i*sizeTextureOnScreenWidth, 0,
                               i*sizeTextureOnScreenWidth, HEIGHT);
        }
    }

    nbCase = compteur;

    for (int i = 0; i < nbC * nbL; ++i)
        SDL_RenderCopy(renderer, wall, &rectSrc[i], &rect[i]);

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
    nbLigne++;
    *nbL = nbLigne;
    *nbC = nbColonneTemp;

    rewind(mapTxt); //Revenir au début du fichier .txt

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




