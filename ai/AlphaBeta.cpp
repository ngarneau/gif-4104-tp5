#include "AlphaBeta.h"
#include "Evaluator.h"
#include "Game.h"
#include "Move.h"
#include <iostream>
#include <limits>
using namespace std;

AlphaBeta::AlphaBeta()
{
	maxDepth = 20;
	evaluator = new Evaluator();
}
 
Move* AlphaBeta::getDecision(Game* game) {
    Move* finalMove = new Move(-1, -1);
    int finalScore = -1;
    int alpha = std::numeric_limits<int>::max();
    int beta = std::numeric_limits<int>::max();
    //if (game->getCurrentPlayer()->getColor() == Square::COLOR::DARK) {
        maxDecision(game, 0, finalScore, finalMove, alpha, beta);
    //}
    //else {
    //    minDecision(game, 0, finalScore, finalMove, alpha, beta);
    //}
    return finalMove;
}

void AlphaBeta::maxDecision(Game* game, int depth, int &finalScore, Move* finalMove, int &alpha, int &beta) {
    //cout << "Max dec" << endl;
    if (depth >= maxDepth) {
        finalScore = evaluator->evaluate(game);
    }
    else {
        std::vector<Move*> legalMoves = game->getLegalMoves(game->getCurrentPlayer()->getColor());
        //cout << "Legal moves: " << legalMoves.size() << endl;
        if (legalMoves.size() == 0) {
            finalScore = evaluator->evaluate(game);
        }
        else {
            int maxScore = std::numeric_limits<int>::min();
            int bestMove = -1;
            for (unsigned int i = 0; i < legalMoves.size(); i++) {
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
            //cout << "I: " << finalMove->getMoveI() << "J: " << finalMove->getMoveJ() << endl;
        }
    }
}

void AlphaBeta::minDecision(Game* game, int depth, int &finalScore, Move* finalMove, int &alpha, int &beta) {
    //cout << "Min dec" << endl;
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
            for (unsigned int i = 0; i < legalMoves.size(); i++) {
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