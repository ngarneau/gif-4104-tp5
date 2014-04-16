#include <iostream>
#include "Game.h"
using namespace std;

int main(int argc, char *argv[])
{
    int withHuman = 1;
    int boardDim = 8;
    int maxDepth = 5;
    int nbCores = 1;

    if (argc >= 2) {
        withHuman = atoi(argv[1]);
    }

    if (argc >= 3) {
        boardDim = atoi(argv[2]);
    }

    if (argc >= 4) {
        maxDepth = atoi(argv[3]);
    }

    if (argc >= 5) {
        nbCores = atoi(argv[4]);
    }

    Game* game = new Game(boardDim);

    game->setMaxDepth(maxDepth);
    game->setCores(nbCores);

    if(withHuman == 1){
        game->playInteractive();
    }
    else{
        game->play();
    }
}
