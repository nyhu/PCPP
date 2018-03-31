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
    this->display = NULL;
    *this = g;
    annonce();
}

Game::~Game()
{
    delete this->display;
    std::cout << "Game over" << std::endl;
}

// WARNING each display reference the same ncurse windows.
// Avoid this usage as it's not necessary to run the game.
Game &Game::operator=(const Game &g)
{
    if (this->display)
    {
        delete this->display;
    }
    this->display = new Display(*g.display);
    return *this;
}

void Game::play()
{
    while (42)
    {
        while (this->display->render()) { // on error ask to resize
            std::cout << "please resize your window";
        }
    }
}
