#include "Game.hpp"

void Game::annonce()
{
    std::cout << "Game start" << std::endl;
}

Game::Game()
{
    this->display = new Display();
    annonce();
}

Game::Game(const Game &g)
{
    *this = g;
    annonce();
}

Game::~Game()
{
    std::cout << "Game over" << std::endl;
}

Game &Game::operator=(const Game &g)
{
    this->display = g.display;
    return *this;
}

void Game::play()
{

}