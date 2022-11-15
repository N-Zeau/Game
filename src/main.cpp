#include "game.h"
#include "iostream"

int WinMain() {

    Game game;
    game.verif();
    game.create();

    while(game.isRunning()) {
        game.loop();
        game.draw();
    }

    game.destroy();
    return 0;
}





