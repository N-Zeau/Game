#include "../Headers/main.h"

int WinMain() {
    Game game;
    Menu menu;

    menu.create();
    while (menu.running && !menu.switchGame) {
        //Clear la fenêtre (renderer)
        SDL_RenderClear(menu.renderer);
        menu.loop();
        menu.drawMenu();
        //Montre tout ce qui a été fait sur la fenêtre (renderer)
        SDL_RenderPresent(menu.renderer);
    }
    menu.destroy();

    if(menu.switchGame){
        game.create();
        while (game.running) {
            //Clear la fenêtre (renderer)
            SDL_RenderClear(game.renderer);
            game.handleEvents();
            game.drawMain();
            //Montre tout ce qui a été fait sur la fenêtre (renderer)
            SDL_RenderPresent(game.renderer);
        }
        game.destroy();
    }


    return 0;
}





