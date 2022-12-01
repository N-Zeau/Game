#include "../Headers/main.h"

int WinMain() {
    Game game;
    game.create();

    while(game.isRunning()) {
        //Clear la fenêtre (renderer)
        SDL_RenderClear(game.renderer);
        game.drawMain();
        //Montre tout ce qui a été fait sur la fenêtre (renderer)
        SDL_RenderPresent(game.renderer);
    }

    game.destroy();
    return 0;
}





