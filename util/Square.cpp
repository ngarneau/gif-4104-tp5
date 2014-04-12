#include "Square.h"

void Square::setColor(Square::COLOR newColor){
	color = newColor;
}

Square::COLOR Square::getColor(){
	return color;
}

void Square::switchColor() {
    if (color == Square::COLOR::DARK) {
            color = Square::COLOR::LIGHT;
    }
    else if (color == Square::COLOR::LIGHT) {
            color = Square::COLOR::DARK;
    }
}