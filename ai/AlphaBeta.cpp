#include "AlphaBeta.h"
#include "Evaluator.h"
#include "Game.h"
#include "Move.h"
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
    int finalScore = -1;
    int alpha = std::numeric_limits<int>::min();
    int beta = std::numeric_limits<int>::max();

    omp_set_num_threads(nbCores);
    maxDecision(game, 0, finalScore, finalMove, alpha, beta);

    return finalMove;
}

void AlphaBeta::maxDecision(Game* game, int depth, int &finalScore, Move* finalMove, int &alpha, int &beta) {
    if (depth >= maxDepth) {
        finalScore = evaluator->evaluate(game);
    }
    else {
        std::vector<Move*> legalMoves = game->getLegalMoves(game->getCurrentPlayer()->getColor());
        if (legalMoves.size() == 0) {
            finalScore = evaluator->evaluate(game);
        }
        else {
            int maxScore = std::numeric_limits<int>::min();
            int bestMove = -1;
            unsigned int i;
            bool run = true;
            #pragma omp parallel for
	        for (i = 0; i < legalMoves.size(); i++) {
               	if(run){
	                Game* newGame = new Game(game);
	                newGame->applyMove(legalMoves.at(i), false);
	                int score = 0;
	                Move* move = new Move(-1, -1);
	            	minDecision(newGame, depth + 1, score, move, alpha, beta);
	                if (score >= beta) {
	                    run = false;
	                }
	                if (score > maxScore) {
	                    maxScore = score;
	                    bestMove = i;
	                }
	                if (score > alpha) {
	                    alpha = score;
	                }
            	}
        	}
            finalScore = maxScore;
            finalMove->setMove(legalMoves.at(bestMove)->getMoveI(), legalMoves.at(bestMove)->getMoveJ());
        }
    }
}

void AlphaBeta::minDecision(Game* game, int depth, int &finalScore, Move* finalMove, int &alpha, int &beta) {
    if (depth >= maxDepth) {
        finalScore = evaluator->evaluate(game);
    }
    else {
        std::vector<Move*> legalMoves = game->getLegalMoves(game->getCurrentPlayer()->getColor());
        if (legalMoves.size() == 0) {
            finalScore = evaluator->evaluate(game);
        }
        else {
            int minScore = std::numeric_limits<int>::max();
            int bestMove = -1;
            unsigned int i;
            bool run  = true;
            #pragma omp parallel for
            for (i = 0; i < legalMoves.size(); i++) {
                if(run) {
	                Game* newGame = new Game(game);
	                newGame->applyMove(legalMoves.at(i), false);
	                int score = 0;
	                Move* move = new Move(-1, -1);
	            	maxDecision(newGame, depth + 1, score, move, alpha, beta);
	                if (score <= alpha) {
	                    run = false;
	                }
	                if (score < minScore) {
	                    minScore = score;
	                    bestMove = i;
	                }
	                if (score < beta) {
	                    score = beta;
	                }
	            }       
            }
            finalScore = minScore;
            finalMove->setMove(legalMoves.at(bestMove)->getMoveI(), legalMoves.at(bestMove)->getMoveJ());
        }
    }
}

void AlphaBeta::setMaxDepth(int depth)
{
	maxDepth = depth;
}

void AlphaBeta::setCores(int cores)
{
	nbCores = cores;
}