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

    std::vector<Move*> firstSetOfMoves = game->getLegalMoves(game->getCurrentPlayer()->getColor());
    if (firstSetOfMoves.size() == 0) {
        finalScore = evaluator->evaluate(game);
    }
    else{
        int maxScore = std::numeric_limits<int>::min();
        int bestMove = -1;
        unsigned int i = 0;
        int depth = 0;
        cout << "moves: " << firstSetOfMoves.size() << endl;
        #pragma omp parallel for shared(i)
        for (i = 0; i < firstSetOfMoves.size(); i++) {
            /*if(omp_get_thread_num() == 1)
                cout << "thread: " << omp_get_thread_num() << " getting move: " << i << endl;*/
            Game* newGame = new Game(game);
            newGame->applyMove(firstSetOfMoves.at(i), false);
            Move* move = new Move(-1, -1);
            int score = 0;
            minDecision(game, depth, score, move, alpha, beta);
            if (score >= beta) {
                continue;
            }
            if (score > maxScore) {
                maxScore = score;
                bestMove = i;
            }
            if (score > alpha) {
                alpha = score;
            }
        }
        //finalScore = maxScore;
        finalMove->setMove(firstSetOfMoves.at(bestMove)->getMoveI(), firstSetOfMoves.at(bestMove)->getMoveJ());
    }

    return finalMove;
}

void AlphaBeta::maxDecision(Game* game, int depth, int &finalScore, Move* finalMove, int &alpha, int &beta) {
    /*if(omp_get_thread_num() == 1)
        cout << "thread: " << omp_get_thread_num() << " alpha: " << alpha << endl;*/
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
            //bool run = true;
	        for (i = 0; i < legalMoves.size(); i++) {
                Game* newGame = new Game(game);
                newGame->applyMove(legalMoves.at(i), false);
                int score = 0;
                Move* move = new Move(-1, -1);

            	minDecision(newGame, depth + 1, score, move, alpha, beta);

                if (score >= beta) {
                    return;
                }
                if (score > maxScore) {
                    maxScore = score;
                    bestMove = i;
                }
                if (score > alpha) {
                    alpha = score;
                }
        	}
            finalScore = maxScore;
            finalMove->setMove(legalMoves.at(bestMove)->getMoveI(), legalMoves.at(bestMove)->getMoveJ());
        }
    }
}

void AlphaBeta::minDecision(Game* game, int depth, int &finalScore, Move* finalMove, int &alpha, int &beta) {
    /*if(omp_get_thread_num() == 1)
        cout << "thread: " << omp_get_thread_num() << " depth: " << depth << endl;*/
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
            int minScore = std::numeric_limits<int>::max();
            int bestMove = -1;
            unsigned int i;
            //bool run  = true;
            for (i = 0; i < legalMoves.size(); i++) {
                Game* newGame = new Game(game);
                newGame->applyMove(legalMoves.at(i), false);
                int score = 0;
                Move* move = new Move(-1, -1);

            	maxDecision(newGame, depth + 1, score, move, alpha, beta);

                if (score <= alpha) {
                    return;
                }
                if (score < minScore) {
                    minScore = score;
                    bestMove = i;
                }
                if (score < beta) {
                    score = beta;
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