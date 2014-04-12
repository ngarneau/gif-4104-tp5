#include "Player.h"

Player::Player(Square::COLOR newColor) {
        color = newColor;
}

Square::COLOR Player::getColor() {
        return color;
}

void Player::setColor(Square::COLOR newColor) {
        color = newColor;
}

Square::COLOR Player::getAdversaryColor() {
        if (color == Square::COLOR::DARK) {
                return Square::COLOR::LIGHT;
        }
        else {
                return Square::COLOR::DARK;
        }
}

void Player::switchColor() {
        if (color == Square::COLOR::DARK) {
                color = Square::COLOR::LIGHT;
        }
        else {
                color = Square::COLOR::DARK;
        }
}