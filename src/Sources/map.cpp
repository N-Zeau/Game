#include "../Headers/map.h"

/*
 * Cette fonction charge une image dans une texture et renvoie cette texture
 * @param const char *nomfichier, chemin relatif du fichier
 * @param SDL_Renderer le renderer de la fenêtre
 * @return retourne la texture à partir de l'image
 */
SDL_Texture *Map::chargerImage(const char *nomFichier, SDL_Renderer *renderer) {
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

/*
 * Cette fonction initialise la map
 */
void Map::initialise() {
    tabMap = importMap();
}

/*
 * Cette fonction dessine la map sur la fenêtre
 * @apram SDL_Renderer, le renderer de la fenêtre
 */
void Map::drawMap(SDL_Renderer *renderer) {

    int sizeTexture = 64; //Vrai taille de la texture
    sizeTextureOnScreenWidth = WIDTH / nbC; //Taille de la largeur de la texture affiché sur la fenêtre
    sizeTextureOnScreenHeight = HEIGHT / nbL; //Taille de la hauteur de la texture affiché sur la fenêtre

    //Import du fichier Mur dans une texture
    SDL_Texture *wall = chargerImage("../Ressources/Map/Mur.bmp",
                                     renderer); //Mettre " ../Ressources/Map/Mur.bmp " pour le make sous Linux

    SDL_Rect rectSrc[nbC * nbL];  //Rectangle correspondant à la source du pavé (Celui affiché)
    SDL_Rect rect[nbC * nbL]; //Position et dimension du Rectangle qui va être affiché dans la fenêtre
    int compteur = 0;
    mapCoordinate = new rectangle[nbC * nbL];
    pieces = l_empty();

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
                    rectSrc[compteur].x = 0;
                    rectSrc[compteur].y = 0;
                    rectSrc[compteur].w = sizeTexture;
                    rectSrc[compteur].h = sizeTexture;
                    type = 2;
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
                    type};
            if (type == 2) {
                pieces = add(mapCoordinate[compteur], pieces);
            }
            compteur++;
        }
    }

    nbCase = compteur;

    SDL_Texture *piece = chargerImage("../Ressources/Map/Mur.bmp", renderer);
    SDL_SetTextureColorMod(piece, 255, 255, 50);
    for (int i = 0; i < nbC * nbL; ++i) {
        if (mapCoordinate[i].type == 2)
            SDL_RenderCopy(renderer, piece, &rectSrc[i], &rect[i]);
        else
            SDL_RenderCopy(renderer, wall, &rectSrc[i], &rect[i]);
    }

}

/*
 * Cette fonction importe la map d'un fichier txt dans un tableau/une matrice
 * @return retourne le tableau
 */
char **Map::importMap() {
    FILE *mapTxt = nullptr;
    mapTxt = fopen("../Ressources/Map/map2.txt", "r");
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
    nbL = nbLigne;
    nbC = nbColonneTemp;

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

/*
 * Cette fonction verifie si la liste est vide
 * @param s_liste liste, la liste à verifier
 * @return un boolean si la liste est vide ou non
 */
bool Map::isEmpty(liste_t liste) {
    return liste == nullptr;
}

/*
 * Cette fonction créer une liste vide
 */
liste_t Map::l_empty() {
    return nullptr;
}

/*
 * Cette fonction ajoute un piece à la liste
 * @param rectangle piece, la piece à ajouter
 * @param liste_l la liste dans laquelle il faut ajouter la piece
 * @return la nouvelle liste modifié
 */
liste_t Map::add(rectangle piece, liste_t L) {
    liste_t M = l_empty();
    M = static_cast<liste_t>(malloc(sizeof(struct s_liste)));
    M->next = L;
    M->piece = piece;
    return M;
}

/*
 * Cette fonction lit le prochaine élément de la liste
 * @param liste_l L, la liste à utiliser
 * @return la nouvelle liste modifié
 */
liste_t Map::next(liste_t L) {
    liste_t Suivant = L->next;
    free(L);
    L = Suivant;
    return L;
}

/*
 * Cette fonction supprime le dernier élément de la liste
 * @param liste_l L, la liste à utiliser
 */
void Map::del(liste_t L) {
    L = next(L);
}

/*
 * Cette fonction modifie un caractère du tableau fait à partir du fichier d'entrée
 * @param int n, indice de la colonne
 * @param int m, indice de la ligne
 */
void Map::changeFichier(int n, int m) {
    tabMap[m-1][n] = ' ';
}