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
        delete this->display;
    this->display = new Display(*g.display);
    return *this;
}

void Game::play()
{
    while (42)
    {
        takeInputUntilNextFrame();

        computeMoves();
        computePlayfield();

        while (this->display->render(this->playfield))
            std::cout << "please resize your window";
    }
}

void Game::takeInputUntilNextFrame()
{
    int time_left = 0;
    clock_t x_startTime, x_countTime;

    this->p1.resetControl();

    x_startTime = clock();
    time_left = FRAME_CLOCK;
    while (time_left > 0)
    {
        int input = 0;
        while ((input = getch()) != ERR)
            this->p1.control(input);

        x_countTime = clock();
        time_left = FRAME_CLOCK + x_startTime - x_countTime;
    }
}

void Game::computeMoves()
{
    this->p1.move();
}

void Game::computePlayfield()
{
    std::memset(this->playfield, ' ', PLAYGROUND_H * PLAYGROUND_W);
    this->playfield[this->p1.getPosY()][this->p1.getPosX()] = this->p1.getOutput();
}