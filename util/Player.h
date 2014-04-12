#ifndef PLAYER_H
#define PLAYER_H
 
#include <iostream>
#include "Square.h"
using namespace std;
 
class Player
{
private:
	Square::COLOR color;

public:

	Player(Player*);
	Player(Square::COLOR color);
    void setColor(Square::COLOR color);
    Square::COLOR getColor();
    Square::COLOR getAdversaryColor();
    void switchColor();
        
};

#endif