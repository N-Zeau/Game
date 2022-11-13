#include "game.h"
#include "iostream"
#include "SDL2/SDL.h"

SDL_Window *window;
SDL_Renderer *renderer;


const int width = 1280;
const int height = 720;

void Game::verif() {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Echec de l'initialisation de SDL2" << std::endl;
    }

    if (!window) {
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


    //creation de la fenêtre
    SDL_CreateWindow("AimBoost",
                     SDL_WINDOWPOS_CENTERED,
                     SDL_WINDOWPOS_CENTERED,
                     width,
                     height,
                     0);

    //Creation du renderer
    renderer = SDL_CreateRenderer(window,
                                  -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


}

void Game::draw() {

}

void Game::destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::isRunning() {
    return running;
}


