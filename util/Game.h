#ifndef GAME_H
#define GAME_H
 
#include <iostream>
#include <vector> 
#include "Square.h"
#include "Player.h"
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

        void output();
        
        void play();
        
        //void applyMove(MoveI move, boolean draw);
        
        bool endCondition();
        
        //vector<Move> getLegalMoves(COLOR color);
        
        //Square[][] getBoard();
        
        int getBoardDim();
        
        //Player getCurrentPlayer();
        
        int getTotalDisksNum();
        
        int getCurrentDisksNum();
        
        int getDarkDisksNum();
        
        int getLightDisksNum();
        
};

#endif