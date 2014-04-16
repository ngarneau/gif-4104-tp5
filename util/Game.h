#ifndef GAME_H
#define GAME_H
 
#include <iostream>
#include <vector> 
#include "Square.h"
#include "Player.h"
#include "Move.h"
using namespace std;

class AlphaBeta;

class Game
{
private:
        int dim = 8;
        int totalDiskNum;
        vector< vector<Square*> > board;
        int currentDisksNum;
        int darkDisksNum;
        int lightDisksNum;
        Player* currentPlayer;
        AlphaBeta* ai;
        float timeDark = 0.0;
        float timeLight = 0.0;
public:
        
        Game(int boardDim);

        Game(Game*);

        ~Game();

        void output();
        
        void play();
        void playInteractive();
        
        void applyMove(Move*, bool);

        void switchSingleDirection(int, int, int, int, bool);

        void switchDisk(int, int, bool);
        
        bool endCondition();

        bool testLegal(int, int, Square::COLOR);

        bool testSingleDirection(int, int, int, int, Square::COLOR);
        
        vector<Move*> getLegalMoves(Square::COLOR color);
        
        int getBoardDim();

        vector< vector<Square*> > getBoard();
        
        Player* getCurrentPlayer();
        
        int getTotalDisksNum();
        
        int getCurrentDisksNum();
        
        int getDarkDisksNum();
        
        int getLightDisksNum();

        void increment(Square::COLOR);
        void decrement(Square::COLOR);

        void sleep(unsigned int);

        void setBoardDim(int);
        void setMaxDepth(int);
        void setCores(int);

        Move* getUserDecision();
        void printPossibleMoves(std::vector<Move*>);
        bool isLegal(Move*, std::vector<Move*>);

        void getWinner();

        void addTime(Square::COLOR, float);
        void getTime();
        
};

#endif