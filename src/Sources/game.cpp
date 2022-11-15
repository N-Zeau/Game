#include "../Headers/game.h"

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

    Game game;
    game.verif();



}

void Game::draw() {

    //Couleur du Background
    SDL_SetRenderDrawColor(renderer, 20, 20, 20, SDL_ALPHA_OPAQUE);

    //Clear la fenêtre (renderer)
    SDL_RenderClear(renderer);

    //Dessine la Map
    Map map_;
    map_.drawMap(map_.importMap());


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


SDL_Window* Game::thisWindow() {
    return window;
}

SDL_Renderer* Game::thisRenderer(){
    return renderer;
}


