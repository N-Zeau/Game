#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "map.h"
#include "player.h"
#include <SDL2/SDL.h>


class Game {
    Map mapSrc{};
    Player player;
    int gameWIDTH = 1280;
    int gameHEIGHT = 720;

public:
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    bool running = true;

    /*
     * Cette fonction verifie si le jeu est bien initialise
     */
    void verif();

    /*
     * Cette fonction créer la fenêtre du jeu et ses données utiles
     */
    void create();

    /*
     * Cette fonction affiche l'état du jeu
     */
    void drawMain();

    /*
     * Cette fonction permet de supprimer le renderer et la fenêtre utiliser lors du jeu
     */
    void destroy();

    /*
     * Cette fonction gère les input clavier pour le joueur et pour fermé la fenêtre
     */
    void handleEvents();


};


#endif //GAME_H
