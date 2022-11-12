#include <SDL2/SDL.h>
#include "iostream"

SDL_Window *window;


void GameLoop() {
    bool run = true;

    while (run) {
        SDL_Event event;
        if (SDL_WaitEvent(&event))
            switch (event.type) {
                case SDL_KEYDOWN:
                    run = event.key.keysym.sym != SDLK_ESCAPE;
                    break;
                case SDL_WINDOWEVENT:
                    run = event.window.event != SDL_WINDOWEVENT_CLOSE;
                    break;
                default:
                    break;
            }
    }
}


void GameDraw() {
    SDL_Renderer *renderer;
}


int WinMain(int argc, char *argv[]) {
    bool running = true;

    const int width = 1280;
    const int height = 720;


    SDL_CreateWindow("AimBoost",
                     SDL_WINDOWPOS_CENTERED,
                     SDL_WINDOWPOS_CENTERED,
                     width,
                     height,
                     0);

    GameLoop();
    GameDraw();
    SDL_QUIT;

    return 0;
}





