#include "Player.hpp"

Player::Player(): lives(3)
{
    this->ouput = '>';
    this->posX = 5;
    this->posY = 30;
}

Player::~Player()
{
}

void Player::control(int input)
{
    switch (input)
    {
    case KEY_DOWN:
        this->directionY = 1;
        break;
    case KEY_UP:
        this->directionY = -1;
        break;
    case KEY_LEFT:
        this->directionX = -1;
        break;
    case KEY_RIGHT:
        this->directionX = 1;
        break;
    }
}

void Player::die() {
    this->lives--;
    if (this->lives == 0)
        return;
    this->pv = 100;
    this->posX = 5;
    this->posY = 30;
}

int Player::getLives() {
    return this->lives;
}
