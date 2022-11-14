#ifndef GAME_H
#define GAME_H
#include "SDL2/SDL.h"

class Game {
    public:

        void verif();
        void loop();
        bool isRunning();
        void create();
        void draw();
        char** importMap();
        void destroy();

    private:
        bool running = true;
};


#endif //GAME_H
