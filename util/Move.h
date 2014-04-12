#ifndef MOVE_H
#define MOVE_H
 
#include <iostream>
using namespace std;
 
class Move
{
private:
	int i = 0;
	int j = 0;

public:

	Move(int, int);
    int getMoveI();
    int getMoveJ();
    void setMove(int, int);
        
};

#endif