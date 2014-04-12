#ifndef GAME_H
#define GAME_H
 
#include <iostream>
#include <vector> 
#include "Square.h"
#include "Player.h"
#include "Move.h"
using namespace std;
 
class Game
{
private:
        int dim;
        int totalDiskNum;
        vector< vector<Square*> > board;
        int currentDisksNum;
        int darkDisksNum;
        int lightDisksNum;
        Player* currentPlayer;
public:
        
        Game();

        Game(Game*);

        ~Game();

        void output();
        
        void play();
        
        void applyMove(Move*, bool);

        void switchSingleDirection(int, int, int, int, bool);

        void switchDisk(int, int, bool);
        
        bool endCondition();

        bool testLegal(int, int, Square::COLOR);

        bool testSingleDirection(int, int, int, int, Square::COLOR);
        
        vector<Move*> getLegalMoves(Square::COLOR color);
        
        int getBoardDim();

        vector< vector<Square*> > getBoard();
        
        Player getCurrentPlayer();
        
        int getTotalDisksNum();
        
        int getCurrentDisksNum();
        
        int getDarkDisksNum();
        
        int getLightDisksNum();

        void increment(Square::COLOR);
        void decrement(Square::COLOR);
        
};

#endif