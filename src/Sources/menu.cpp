#include "../Headers/menu.h"

/*
 * Cette fonction dessine le Menu
 */
void Menu::drawMenu() {
    //Affiche l'image du Menu en fonction de la position de la souris
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

/*
 * Cette fonction créer le Menu
 */
void Menu::create() {
    //Creation de la fenêtre et du renderer
    SDL_CreateWindowAndRenderer(menuWIDTH,
                                menuHEIGHT,
                                0,
                                &window,
                                &renderer);

    //Initialisation du titre de la fenêtre
    SDL_SetWindowTitle(window, "AimBoost");

    menuEmpty = chargerImage("../Ressources/Menu/1.bmp", renderer);
    menuPlay = chargerImage("../Ressources/Menu/2.bmp", renderer);
    menuSettings = chargerImage("../Ressources/Menu/3.bmp", renderer);

}

/*
 * Cette fonction gère le changement de fenêtre entre le menu et le Jeu ou les Settings
 */
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
                } else if (mouseInButton(buttonSettings)) {
                    switchSettings = true;
                }
                break;
        }
    }
}

/*
 * Cette fonction supprime le renderer et la fneêtre utilisé pour créer le Menu
 */
void Menu::destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

/*
 * Cette fonction verifie si la souris est dans un rectangle
 * @param SDL_Rect button, le rectangle à tester
 * @return return si la souris est dans le rectangle
 */
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

/*
 * Cette fonction charge une image dans une texture et renvoie cette texture
 * @param const char *nomfichier, chemin relatif du fichier
 * @param SDL_Renderer le renderer de la fenêtre
 * @return retourne la texture à partir de l'image
 */
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



