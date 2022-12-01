#include "../Headers/game.h"

void Game::verif() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Echec de l'initialisation de SDL2 : " << SDL_GetError() << std::endl;
    }
    if (window) {
        std::cout << "Echec de la creation de la fenetre : " << SDL_GetError() << std::endl;
    }
}

void Game::loop() {
    Event quit{};
    //Le jeu tourne tant que Echap ou le bouton fermer n'est pas pressé
    if (SDL_WaitEvent(&quit.event))
        switch (quit.event.type) {
            case SDL_KEYDOWN:
                running = quit.event.key.keysym.sym != SDLK_ESCAPE; //verifie si la touche Echap est pressé
                break;
            case SDL_WINDOWEVENT:
                running = quit.event.window.event != SDL_WINDOWEVENT_CLOSE; //verifie si le bouton fermer est pressé
                break;
            default:
                break;
        }
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
    int coefMapW = widthWindow/3;
    int coefMapH = heightWindow/3;
    mapSrc.WIDTH = (nbC * sizeCarre)*coefMapW;
    mapSrc.HEIGHT = (nbL * sizeCarre)*coefMapH;


    //Creation de la fenêtre et du renderer
    SDL_CreateWindowAndRenderer(widthWindow,
                                heightWindow,
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

    //Gère les mouvements du joueur
    player.movePlayer(renderer, mapSrc);
    //Dessine la vision du joueur
    player.visionPlayer(renderer, mapSrc, player);
    //Affichage du personnage
    player.updatePlayer(renderer, mapSrc);

    //Couleur du Background
    SDL_SetRenderDrawColor(renderer, 40, 55, 71, SDL_ALPHA_OPAQUE);

}

void Game::destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::isRunning() {
    return running;
}
