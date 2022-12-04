#include "../Headers/main.h"

int WinMain() {
    Game game;
    Menu menu;



    while(menu.isRunning()){
        //Clear la fenêtre (renderer)
        SDL_RenderClear(menu.renderer);
        menu.drawMenu(menu.renderer);
    }

    game.create();

    while(game.isRunning()) {
        //Clear la fenêtre (renderer)
        SDL_RenderClear(game.renderer);
        game.handleEvents();
        game.drawMain();
        //Montre tout ce qui a été fait sur la fenêtre (renderer)
        SDL_RenderPresent(game.renderer);
    }

    game.destroy();
    return 0;
}





