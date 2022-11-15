#include "../Headers/game.h"

int WinMain() {
    Game game;
    game.create();

    while(game.isRunning()) {
        game.loop();
        game.draw();
    }

    game.destroy();
    return 0;
}





