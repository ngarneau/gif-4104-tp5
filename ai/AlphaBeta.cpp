#include "AlphaBeta.h"
#include "Evaluator.h"
#include "Game.h"
#include "Move.h"
#include "Chrono.hpp"
#include <omp.h>
#include <iostream>
#include <limits>
using namespace std;

AlphaBeta::AlphaBeta()
{
	maxDepth = 5;
	evaluator = new Evaluator();
}
 
Move* AlphaBeta::getDecision(Game* game) {
    Move* finalMove = new Move(-1, -1);
    int maxScore = 0;

    omp_set_num_threads(nbCores);

    std::vector<Move*> firstSetOfMoves = game->getLegalMoves(game->getCurrentPlayer()->getColor());
    if (firstSetOfMoves.size() > 0) {
        unsigned int i = 0;
        int bestMove = 0;
        int score = std::numeric_limits<int>::min();

        int alpha = std::numeric_limits<int>::min();
        int beta = std::numeric_limits<int>::max();

        #pragma omp for
        for (i = 0; i < firstSetOfMoves.size(); i++) {

            Game* newGame = new Game(game);
            newGame->applyMove(firstSetOfMoves.at(i), false);

            score = minDecision(newGame, 0, alpha, beta);
            if(score > maxScore){
                //cout << "thread: " << omp_get_thread_num() << " score: " << score << endl;
                #pragma omp critical
                {
                    maxScore = score;
                    bestMove = i;
                }
            }

        }
        finalMove->setMove(firstSetOfMoves.at(bestMove)->getMoveI(), firstSetOfMoves.at(bestMove)->getMoveJ());
    }

    return finalMove;
}

int AlphaBeta::maxDecision(Game* game, int depth, int& alpha, int& beta) {
    /*if(omp_get_thread_num() == 1)
        cout << "thread: " << omp_get_thread_num() << " depth: " << depth << endl;*/

    int finalScore = 0;

    if (depth >= maxDepth) {
        finalScore = evaluator->evaluate(game);
    }
    else {
        std::vector<Move*> legalMoves = game->getLegalMoves(game->getCurrentPlayer()->getColor());
        if (legalMoves.size() == 0) {
            finalScore = evaluator->evaluate(game);
        }
        else {
            int val = std::numeric_limits<int>::min();
            unsigned int i;
	        for (i = 0; i < legalMoves.size(); i++) {
                Game* newGame = new Game(game);
                newGame->applyMove(legalMoves.at(i), false);
                int score = 0;

            	score = minDecision(newGame, depth + 1, alpha, beta);

                if (score > val) {
                    val = score;
                }

                if(val >= beta){
                    return val;
                }

                if(val > alpha){
                    //cout << "thread: " << omp_get_thread_num() << " alpha: " << val << endl;
                    alpha = val;
                }

        	}
            finalScore = val;
        }
    }

    return finalScore;
}

int AlphaBeta::minDecision(Game* game, int depth, int& alpha, int& beta) {
    /*if(omp_get_thread_num() == 1)
        cout << "thread: " << omp_get_thread_num() << " depth: " << depth << endl;*/

    int finalScore = 0;

    if (depth >= maxDepth) {
        finalScore = evaluator->evaluate(game);
    }
    else {
        Square::COLOR color = Square::COLOR::DARK;
        if(game->getCurrentPlayer()->getColor() == Square::COLOR::DARK){
            color = Square::COLOR::LIGHT;
        }
        std::vector<Move*> legalMoves = game->getLegalMoves(color);
        if (legalMoves.size() == 0) {
            finalScore = evaluator->evaluate(game);
        }
        else {
            int val = std::numeric_limits<int>::max();
            unsigned int i;
            //bool run  = true;
            for (i = 0; i < legalMoves.size(); i++) {
                Game* newGame = new Game(game);
                newGame->applyMove(legalMoves.at(i), false);
                int score = 0;

            	score = maxDecision(newGame, depth + 1, alpha, beta);

                if (score < val) {
                    val = score;
                }

                if(alpha >= val){
                    return val;
                }

                if(val < beta){
                    //cout << "thread: " << omp_get_thread_num() << " beta: " << val << endl;
                    beta = val;
                }

            }
            finalScore = val;
        }
    }

    return finalScore;
}

void AlphaBeta::setMaxDepth(int depth)
{
	maxDepth = depth;
}

void AlphaBeta::setCores(int cores)
{
	nbCores = cores;
}