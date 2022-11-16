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
    //Verifie l'initialisation de SDL2 et de la fenêtre
    Game::verif();

    //Creation de la fenêtre et du renderer
    SDL_CreateWindowAndRenderer(WIDTH,
                                HEIGHT,
                                0,
                                &window,
                                &renderer);

    //Initialisation du titre de la fenêtre
    SDL_SetWindowTitle(window, "AimBoost");
}

void Game::drawMain() {
    //Clear la fenêtre (renderer)
    SDL_RenderClear(renderer);

    //Couleur du Background
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, SDL_ALPHA_OPAQUE);

    //Dessine la Map
    int nbL;
    int nbC;
    Map map;
    map.drawMap(renderer, map.importMap(&nbL, &nbC));

    //Dessine le joueur
    Player player;
    SDL_Color red = {220, 0, 0, 255};
    player.createPlayer(renderer, 10, red);

    //Montre tout ce qui a été fait sur la fenêtre (renderer)
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
