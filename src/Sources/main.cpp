#include "../Headers/main.h"

int main() {
    Game game;
    Settings settings;
    Menu menu;

    menu.create();
    while (menu.running && !menu.switchGame && !menu.switchSettings) {
        //Clear la fenêtre (renderer)
        SDL_RenderClear(menu.renderer);
        menu.loop();
        menu.drawMenu();
        //Montre tout ce qui a été fait sur la fenêtre (renderer)
        SDL_RenderPresent(menu.renderer);
    }
    menu.destroy();

    if (menu.switchGame) {
        game.create();
        while (game.running) {
            //Clear la fenêtre (renderer)
            SDL_RenderClear(game.renderer);
            game.handleEvents();
            game.drawMain();
            //Montre tout ce qui a été fait sur la fenêtre (renderer)
            SDL_RenderPresent(game.renderer);
            //Delay
            SDL_Delay(10);
        }
        game.destroy();

    } else if (menu.switchSettings) {
        settings.create();
        while (settings.running) {
            //Clear la fenêtre (renderer)
            SDL_RenderClear(settings.renderer);
            settings.loop();
            //Montre tout ce qui a été fait sur la fenêtre (renderer)
            SDL_RenderPresent(settings.renderer);
        }
        settings.destroy();

    }


    return 0;
}





