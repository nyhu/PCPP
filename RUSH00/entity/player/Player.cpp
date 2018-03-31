#include "Player.hpp"

Player::Player(): AShip()
{
    this->ouput = '>';
    this->posX = 5;
    this->posY = 30;
}

Player::~Player()
{
}

void Player::resetControl()
{
    this->directionY = 0;
    this->directionX = 0;
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