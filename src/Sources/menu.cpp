#include <iostream>
#include "../Headers/menu.h"

void Menu::drawMenu() {

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    button[0] = {menuWIDTH / 2 - 100, menuHEIGHT / 2 - 25, 200, 50};
    SDL_RenderDrawRect(renderer, &button[0]);

    //Couleur du Background du Menu
    SDL_SetRenderDrawColor(renderer, 40, 55, 71, SDL_ALPHA_OPAQUE);

}

void Menu::create() {

    //Creation de la fenêtre et du renderer
    SDL_CreateWindowAndRenderer(menuWIDTH,
                                menuHEIGHT,
                                0,
                                &window,
                                &renderer);

    //Initialisation du titre de la fenêtre
    SDL_SetWindowTitle(window, "AimBoost");


}

void Menu::loop() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                running = event.key.keysym.sym != SDLK_ESCAPE;
                break;
            case SDL_WINDOWEVENT:
                running = event.window.event != SDL_WINDOWEVENT_CLOSE;
                break;
            case SDL_MOUSEBUTTONDOWN:
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                int xMin = button[0].x, xMax = button[0].x + button[0].w;
                int yMin = button[0].y, yMax = button[0].y + button[0].h;
                if (mouseX >= xMin && mouseY >= yMin && mouseX <= xMax && mouseY <= yMax) {
                    switchGame = true;
                }
                break;
        }
    }
}

void Menu::destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}



