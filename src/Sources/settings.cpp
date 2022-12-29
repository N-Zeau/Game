#include "../Headers/settings.h"

void Settings::create() {
    //Creation de la fenêtre et du renderer
    SDL_CreateWindowAndRenderer(settingsWIDTH,
                                settingsHEIGHT,
                                0,
                                &window,
                                &renderer);

    //Initialisation du titre de la fenêtre
    SDL_SetWindowTitle(window, "AimBoost");
}

void Settings::destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Settings::loop() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                running = event.key.keysym.sym != SDLK_ESCAPE;
                break;
            case SDL_WINDOWEVENT:
                running = event.window.event != SDL_WINDOWEVENT_CLOSE;
                break;
        }
    }
}
