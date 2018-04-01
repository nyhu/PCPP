#include "Player.hpp"

Player::Player() : score(0), lives(3)
{
    this->ouput = '>';
    this->posX = 30;
    this->posY = 20;
}

Player::Player(int x, int y) : score(0), lives(3)
{
    this->ouput = '>';
    this->posX = x;
    this->posY = y;
}

Player::~Player()
{
}

Player::Player(const Player &p)
{
      *this = p;
}

Player &Player::operator=(const Player &rhs)
{
    this->lives = rhs.lives;
    this->pv = rhs.pv ;
    this->ouput = rhs.ouput;
    this->posX = rhs.posX;
    this->posY = rhs.posY;
    this->directionX = rhs.directionY;
    this->directionY = rhs.directionX;
    this->frameSinceLastAttack = rhs.frameSinceLastAttack;
    return(*this);
}

bool Player::control(int input)
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
    case 27:
        return true;
    }
    return false;
}

bool Player::controlP2(int input)
{
    switch (input)
    {
    case 's':
        this->directionY = 1;
        break;
    case 'z':
        this->directionY = -1;
        break;
    case 'q':
        this->directionX = -1;
        break;
    case 'd':
        this->directionX = 1;
        break;
    case 27:
        return true;
    }
    return false;
}

void Player::die()
{
    this->lives--;
    if (this->lives == 0)
        return;
    this->pv = 100;
    this->posX = 5;
    this->posY = 30;
}

int Player::getLives()
{
    return this->lives;
}

void Player::move()
{
    AShip::move();
    bullets.moveBullets();
}

void Player::attack(BulletList &b)
{
    if (frameSinceLastAttack > 10 / (this->lives + 1))
    {
        frameSinceLastAttack = 0;
        b.pushBullet(new AShip(40 / (this->lives + 1), '-', this->posX + 1, this->posY, 1, 0));
        return;
    }
    ++frameSinceLastAttack;
}

void Player::respawn()
{
    return;
}