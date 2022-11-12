#include "SDL2/SDL.h"

int main(int argc, char *argv[]) {
    bool loop = true;

    SDL_Window *window;
    window = SDL_CreateWindow("SDL2 Window",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              680, 480,
                              0);

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    while (loop) {
        SDL_UpdateWindowSurface(window);
        SDL_Delay(5);
        SDL_Event ev;
        if (SDL_PollEvent(&ev))
            if (ev.type == SDLK_ESCAPE)
                loop = false;
    }
    return 0;
}