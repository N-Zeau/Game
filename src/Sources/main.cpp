#include "../Headers/main.h"

int WinMain() {
    Game game;
    game.create();

    while(game.isRunning()) {
        game.loop();
        game.drawMain();
    }

    game.destroy();
    return 0;
}





