#include "../Headers/game.h"

void Game::verif() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Echec de l'initialisation de SDL2 : " << SDL_GetError() << std::endl;
    }
    if (window) {
        std::cout << "Echec de la creation de la fenetre : " << SDL_GetError() << std::endl;
    }
}

void Game::create() {
    //Verifie l'initialisation de SDL2 et de la fenêtre
    verif();

    int nbL;
    int nbC;
    mapSrc.importMap(&nbL, &nbC);
    int sizeCarre = 64;

    //Taille de la miniMap en fonction de la taille de la window
    mapSrc.WIDTH = (nbC * sizeCarre) / 3;
    mapSrc.HEIGHT = (nbL * sizeCarre) / 3;

    //Creation de la fenêtre et du renderer
    SDL_CreateWindowAndRenderer(gameWIDTH,
                                gameHEIGHT,
                                0,
                                &window,
                                &renderer);

    //Initialisation du titre de la fenêtre
    SDL_SetWindowTitle(window, "AimBoost");

    //Initialisation et dessine le Joueur
    player.initPlayer(renderer, mapSrc);

}

void Game::drawMain() {
    //Vision3D
    player.vision3DPlayer(renderer, mapSrc);
    //Dessine la vision du joueur sur la minimap
    player.visionPlayer(renderer, mapSrc);
    //Affichage du personnage
    player.updatePlayer(renderer);
    //Dessine la Map
    int nbL, nbC;
    mapSrc.drawMap(renderer, mapSrc.importMap(&nbL, &nbC));

    //Couleur du Background
    SDL_SetRenderDrawColor(renderer, 40, 55, 71, SDL_ALPHA_OPAQUE);

}

void Game::destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::handleEvents() {
    float speed = 5;
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                running = event.key.keysym.sym != SDLK_ESCAPE;
                switch (event.key.keysym.sym) {
                    case SDLK_z:
                        if (player.rectHere(mapSrc, player.playerX, player.playerY - speed)->type != 1
                            &&
                            player.rectHere(mapSrc, player.playerX + player.playerSize, player.playerY - speed)->type !=
                            1)
                            player.playerY -= speed;
                        break;
                    case SDLK_s:
                        if (player.rectHere(mapSrc, player.playerX, player.playerY + player.playerSize + speed)->type !=
                            1
                            && player.rectHere(mapSrc, player.playerX + player.playerSize,
                                               player.playerY + player.playerSize + speed)->type != 1)
                            player.playerY += speed;
                        break;
                    case SDLK_q:
                        if (player.rectHere(mapSrc, player.playerX - speed, player.playerY)->type != 1
                            &&
                            player.rectHere(mapSrc, player.playerX - speed, player.playerY + player.playerSize)->type !=
                            1)
                            player.playerX -= speed;
                        break;
                    case SDLK_d:
                        if (player.rectHere(mapSrc, player.playerX + speed + player.playerSize, player.playerY)->type !=
                            1
                            && player.rectHere(mapSrc, player.playerX + speed + player.playerSize,
                                               player.playerY + player.playerSize)->type != 1)
                            player.playerX += speed;
                        break;
                }
                break;
            case SDL_WINDOWEVENT:
                running = event.window.event != SDL_WINDOWEVENT_CLOSE;
                break;
        }
    }
}