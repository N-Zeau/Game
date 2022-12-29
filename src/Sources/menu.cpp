#include "../Headers/menu.h"

void Menu::drawMenu() {
    SDL_Rect rectMenu = {0, 0, menuWIDTH, menuHEIGHT};

    SDL_Texture *menuEmpty = chargerImage("../Menu/1.bmp", renderer);
    SDL_Texture *menuPlay = chargerImage("../Menu/2.bmp", renderer);
    SDL_Texture *menuSettings = chargerImage("../Menu/3.bmp", renderer);


    if (mouseInButton(buttonPlay)) {
        SDL_RenderCopy(renderer, menuPlay, &rectMenu, &rectMenu);
    } else if (mouseInButton(buttonSettings)) {
        SDL_RenderCopy(renderer, menuSettings, &rectMenu, &rectMenu);
    } else {
        SDL_RenderCopy(renderer, menuEmpty, &rectMenu, &rectMenu);
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
                if (mouseInButton(buttonPlay)) {
                    switchGame = true;
                } else if(mouseInButton(buttonSettings)){
                    switchSettings = true;
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

bool Menu::mouseInButton(SDL_Rect button) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    //Coordonnée bouton
    int xMin = button.x, xMax = button.x + button.w;
    int yMin = button.y, yMax = button.y + button.h;

    if (mouseX >= xMin && mouseY >= yMin && mouseX <= xMax && mouseY <= yMax) {
        return true;
    } else {
        return false;
    }
}

SDL_Texture *Menu::chargerImage(const char *nomFichier, SDL_Renderer *renderer) {
    SDL_Surface *menu = nullptr;
    menu = SDL_LoadBMP(nomFichier);

    if (menu == nullptr) {
        std::cout << "Echec du chargement du menu : " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture *texture = nullptr;
    texture = SDL_CreateTextureFromSurface(renderer, menu);

    if (texture == nullptr) {
        std::cout << "Echec du chargement de la texture : " << SDL_GetError() << std::endl;
        return nullptr;
    }

    SDL_FreeSurface(menu);
    return texture;

}



