#include "Move.h"

Move::Move(int newI, int newJ) {
        i = newI;
        j = newJ;
}

int Move::getMoveI() {
        return i;
}

int Move::getMoveJ() {
        return j;
}

void Move::setMove(int newI, int newJ) {
        i = newI;
        j = newJ;     
}