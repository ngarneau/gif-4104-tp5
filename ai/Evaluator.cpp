#include "Evaluator.h"
#include <iostream>
using namespace std;

Evaluator::Evaluator(){
	
}
 
int Evaluator::evaluate(Game* game)
{
    int score = 0;
	if (game->endCondition()) {
        score = game->getDarkDisksNum() - game->getLightDisksNum();
	}
	else {
        // mobility
        int darkMobility = game->getLegalMoves(Square::COLOR::DARK).size();
        int lightMobility = game->getLegalMoves(Square::COLOR::LIGHT).size();
        int mobility = darkMobility - lightMobility;
        // stability
        int darkStability = 0;
        int lightStability = 0;
        for (int i = 0; i < game->getBoardDim(); i++) {
            for (int j = 0; j < game->getBoardDim(); j++) {
                if ( (game->getBoard()[i][j])->getColor() != Square::COLOR::NONE) {
                    if ( (stableDirection(game, i, j, 1, 0) || stableDirection(game, i, j, -1, 0) ) &&
                         (stableDirection(game, i, j, 0, 1) || stableDirection(game, i, j, 0, -1) ) &&
                         (stableDirection(game, i, j, 1, 1) || stableDirection(game, i, j, -1, -1) ) &&
                         (stableDirection(game, i, j, 1, -1) || stableDirection(game, i, j, -1, 1) ) ) {
                
                        if ( (game->getBoard()[i][j])->getColor() == Square::COLOR::DARK) {
                            darkStability++;
                        }
                        else {
                            lightStability++;
                        }
                    }
                }
            }
        }
        int stability = darkStability - lightStability;
        // disks difference
        int disksDiff = game->getDarkDisksNum() - game->getLightDisksNum();
        // total score
        score = (100 * mobility) + (10 * stability) + (1 * disksDiff);
	}
	return score;
}
 
bool Evaluator::stableDirection(Game* game, int i, int j, int v, int h)
{
    Square::COLOR color = (game->getBoard()[i][j])->getColor();
    bool stable = true;
    while (i+v < game->getBoardDim() && j+h < game->getBoardDim() &&
           i+v >= 0 && j+h >= 0 &&
           stable) {
        
        if ( (game->getBoard()[i+v][j+h])->getColor() != color) {
            stable = false;
        }
        i = i + v;
        j = j + h;
    }
    return stable;
    return true;
}