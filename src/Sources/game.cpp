#include "../Headers/game.h"

/*
 * Cette fonction verifie si le jeu est bien initialise
 */
void Game::verif() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Echec de l'initialisation de SDL2 : " << SDL_GetError() << std::endl;
    }
    if (window) {
        std::cout << "Echec de la creation de la fenetre : " << SDL_GetError() << std::endl;
    }
}

/*
 * Cette fonction créer la fenêtre du jeu et ses données utiles
 */
void Game::create() {
    //Verifie l'initialisation de SDL2 et de la fenêtre
    verif();

    mapSrc.initialise();
    int sizeCarre = 64;

    //Taille de la miniMap en fonction de la taille de la window
    mapSrc.WIDTH = (mapSrc.nbC * sizeCarre) / 3;
    mapSrc.HEIGHT = (mapSrc.nbL * sizeCarre) / 3;

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


/*
 * Cette fonction affiche l'état du jeu
 */
void Game::drawMain() {
    //Vision3D
    player.vision3DPlayer(renderer, mapSrc);
    //Dessine la vision du joueur sur la minimap
    player.visionPlayer(renderer, mapSrc);
    //Affichage du personnage
    player.updatePlayer(renderer);
    //Dessine la Map
    mapSrc.drawMap(renderer);


    if (mapSrc.isEmpty(mapSrc.pieces)) {//toutes les pièces ont été prise
        running = false;
    }
    //Couleur du Background
    SDL_SetRenderDrawColor(renderer, 40, 55, 71, SDL_ALPHA_OPAQUE);

}

/*
 * Cette fonction permet de supprimer le renderer et la fenêtre utiliser lors du jeu
 */
void Game::destroy() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

/*
 * Cette fonction gère les input clavier pour le joueur et pour fermé la fenêtre
 */
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
                            && player.rectHere(mapSrc, player.playerX + player.playerSize, player.playerY - speed)->type != 1) {

                            if (!player.collisionPiece(mapSrc, speed, 3))
                                player.playerY -= speed;
                            else
                                player.attrapePiece(mapSrc, speed, 3);
                        }
                        break;
                    case SDLK_s:
                        if (player.rectHere(mapSrc, player.playerX, player.playerY + player.playerSize + speed)->type != 1
                            && player.rectHere(mapSrc, player.playerX + player.playerSize,player.playerY + player.playerSize + speed)->type != 1) {

                            if (!player.collisionPiece(mapSrc, speed, 2))
                                player.playerY += speed;
                            else
                                player.attrapePiece(mapSrc, speed, 2);
                        }
                        break;
                    case SDLK_q:
                        if (player.rectHere(mapSrc, player.playerX - speed, player.playerY)->type != 1
                            && player.rectHere(mapSrc, player.playerX - speed, player.playerY + player.playerSize)->type != 1) {

                            if (!player.collisionPiece(mapSrc, speed, 1))
                                player.playerX -= speed;
                            else
                                player.attrapePiece(mapSrc, speed, 1);

                        }
                        break;
                    case SDLK_d:
                        if (player.rectHere(mapSrc, player.playerX + speed + player.playerSize, player.playerY)->type != 1
                            && player.rectHere(mapSrc, player.playerX + speed + player.playerSize,player.playerY + player.playerSize)->type != 1) {

                            if (!player.collisionPiece(mapSrc, speed, 0))
                                player.playerX += speed;
                            else
                                player.attrapePiece(mapSrc, speed, 0);
                        }
                        break;
                    case SDLK_LEFT:
                        player.angle -= 0.2;
                        break;
                    case SDLK_RIGHT:
                        player.angle += 0.2;
                        break;
                }
                break;
            case SDL_WINDOWEVENT:
                running = event.window.event != SDL_WINDOWEVENT_CLOSE;
                break;
        }
    }
}
