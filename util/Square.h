#ifndef SQUARE_H
#define SQUARE_H
 
#include <iostream>
using namespace std;
 
class Square
{
private:
        
public:
		enum COLOR{NONE, DARK, LIGHT};
        void setColor(Square::COLOR color);
        Square::COLOR getColor();
        void switchColor();
        Square::COLOR color = Square::COLOR::NONE;
        
};

#endif