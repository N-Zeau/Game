#include "game.h"
#include "iostream"
#include "SDL2/SDL.h"

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;


const int width = 1280;
const int height = 720;

void Game::verif() {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Echec de l'initialisation de SDL2 " << std::endl;
    }

    if (window) {
        std::cout << "Echec de la creation de la fenetre" << std::endl;
    }

}

void Game::loop() {

    //Le jeu tourne tant que Echap ou le bouton fermer n'est pas pressé
    SDL_Event event;
    if (SDL_WaitEvent(&event))
        switch (event.type) {
            case SDL_KEYDOWN:
                running = event.key.keysym.sym != SDLK_ESCAPE; //verifie si la touche Echap est pressé
                break;
            case SDL_WINDOWEVENT:
                running = event.window.event != SDL_WINDOWEVENT_CLOSE; //verifie si le bouton fermer est pressé
                break;
            default:
                break;
        }
}

void Game::create() {
    //Creation de la fenêtre et du renderer
    SDL_CreateWindowAndRenderer(width,
                                height,
                                0,
                                &window,
                                &renderer);

    //Initialisation du titre de la fenêtre
    SDL_SetWindowTitle(window, "AimBoost");

}

void Game::draw() {
    //Couleur du Background
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, SDL_ALPHA_OPAQUE);

    //Clear la fenêtre (renderer)
    SDL_RenderClear(renderer);

    //Importation de la map + Dessin de la map
    Game game;
    char **map = game.importMap();
    game.drawMap(map);

    //Montre tout ce qui a été fait sur la fenêtre (renderer)
    SDL_RenderPresent(renderer);

}

char **Game::importMap() {
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

SDL_Texture *chargerImage(const char *nomFichier, SDL_Renderer *renderer) {
    SDL_Surface *wall = nullptr;
    wall = SDL_LoadBMP(nomFichier);

    if (wall == nullptr) {
        std::cout << "Echec du chargement de l'image" << std::endl;
        return nullptr;
    }

    SDL_Texture *texture = nullptr;
    texture = SDL_CreateTextureFromSurface(renderer, wall);

    if (texture == nullptr) {
        std::cout << "Echec du chargement de la texture" << std::endl;
        return nullptr;
    }

    SDL_FreeSurface(wall);
    return texture;

}

void Game::drawMap(char **map) {
    //Import du fichier Mur dans une texture
    SDL_Texture *wall = chargerImage("../Ressources/Bin/Mur.bmp", renderer);
    SDL_Rect srcpave;  //Rectangle correspondant à la source du pavé
    srcpave.x = 0, srcpave.y = 0, srcpave.w = 16, srcpave.h = 16;
    SDL_Rect rect; //Rectangle qui va être afficher dans la fenêtre
    rect.x = 0, rect.y = 0, rect.w = 64, rect.h = 64;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, wall, &srcpave, &rect);
    SDL_RenderPresent(renderer);

}


void Game::destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::isRunning() {
    return running;
}



