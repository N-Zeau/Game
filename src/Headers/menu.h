#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "SDL2/SDL.h"
#include <iostream>

class Menu {

public:
    int menuWIDTH = 700;
    int menuHEIGHT = 700;

    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
    SDL_Rect buttonPlay = {217, 370, 265, 68};
    SDL_Rect buttonSettings = {217, 479, 265, 68};
    SDL_Rect rectMenu = {0, 0, menuWIDTH, menuHEIGHT};

    SDL_Texture *menuEmpty;
    SDL_Texture *menuPlay;
    SDL_Texture *menuSettings;

    bool running = true;
    bool switchGame = false;
    bool switchSettings = false;

    /*
     * Cette fonction gère le changement de fenêtre entre le menu et le Jeu ou les Settings
     */
    void loop();

    /*
     * Cette fonction créer le Menu
     */
    void create();

    /*
     * Cette fonction dessine le Menu
     */
    void drawMenu();

    /*
     * Cette fonction supprime le renderer et la fneêtre utilisé pour créer le Menu
     */
    void destroy();

    /*
     * Cette fonction verifie si la souris est dans un rectangle
     * @param SDL_Rect button, le rectangle à tester
     * @return return si la souris est dans le rectangle
     */
    bool mouseInButton(SDL_Rect button);

    /*
     * Cette fonction charge une image dans une texture et renvoie cette texture
     * @param const char *nomfichier, chemin relatif du fichier
     * @param SDL_Renderer le renderer de la fenêtre
     * @return retourne la texture à partir de l'image
     */
    SDL_Texture *chargerImage(const char *nomFichier, SDL_Renderer *renderer);
};


#endif //GAME_MENU_H
