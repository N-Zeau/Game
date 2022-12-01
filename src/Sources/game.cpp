#include "../Headers/game.h"

void Game::verif() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Echec de l'initialisation de SDL2 : " << SDL_GetError() << std::endl;
    }
    if (window) {
        std::cout << "Echec de la creation de la fenetre : " << SDL_GetError() << std::endl;
    }
}

bool Game::isRunning() {
    return running;
}

void Game::create() {
    //Verifie l'initialisation de SDL2 et de la fenêtre
    verif();

    int nbL;
    int nbC;
    mapSrc.importMap(&nbL, &nbC);
    int sizeCarre = 64;

    //Taille de la fenêtre
    int widthWindow = 1280;
    int heightWindow = 720;

    //Taille de la miniMap en fonction de la taille de la window
    mapSrc.WIDTH = (nbC * sizeCarre);
    mapSrc.HEIGHT = (nbL * sizeCarre);


    //Creation de la fenêtre et du renderer
    SDL_CreateWindowAndRenderer(mapSrc.WIDTH,
                                mapSrc.HEIGHT,
                                0,
                                &window,
                                &renderer);



    //Initialisation du titre de la fenêtre
    SDL_SetWindowTitle(window, "AimBoost");

    //Initialisation et dessine le Joueur
    player.initPlayer(renderer, mapSrc);

}

void Game::drawMain() {
    //Dessine la Map
    int nbL, nbC;
    mapSrc.drawMap(renderer, mapSrc.importMap(&nbL, &nbC));

    //Dessine la vision du joueur
    player.visionPlayer(renderer, mapSrc, player);


    //Mouvement du joueur
    player.movePlayer(player);

    //Affichage du personnage
    player.updatePlayer(renderer);

    //Couleur du Background
    SDL_SetRenderDrawColor(renderer, 40, 55, 71, SDL_ALPHA_OPAQUE);

}

void Game::destroy() const {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
