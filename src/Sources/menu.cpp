#include <iostream>
#include "../Headers/menu.h"

void Menu::drawMenu() {

    //Bouton Play
    buttonTab[0] = {menuWIDTH / 2 - 100, menuHEIGHT / 2 - 25, 200, 50};
    if (mouseInButton()){
        SDL_SetRenderDrawColor(renderer, grey.r, grey.g, grey.b, grey.a);
        SDL_RenderDrawRect(renderer, &buttonTab[0]);
    }else{
        SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b, black.a);
        SDL_RenderDrawRect(renderer, &buttonTab[0]);
    }



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
                if(mouseInButton())
                    switchGame = true;
                break;
        }
    }
}

void Menu::destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Menu::mouseInButton(){
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    //Coordonnée bouton play
    int xMin = buttonTab[0].x, xMax = buttonTab[0].x + buttonTab[0].w;
    int yMin = buttonTab[0].y, yMax = buttonTab[0].y + buttonTab[0].h;
    if (mouseX >= xMin && mouseY >= yMin && mouseX <= xMax && mouseY <= yMax) {
        return true;
    }else{
        return false;
    }
}



