#include "game.h"
#include "GL/gl.h"

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
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





