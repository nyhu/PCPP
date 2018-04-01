#include "Game.hpp"

Game::Game()
{
}

Game::Game(const Game &g)
{
    *this = g;
}

Game::~Game()
{
}

// WARNING each display reference the same ncurse windows.
// Avoid this usage as it's not necessary to run the game.
Game &Game::operator=(const Game &g)
{
    this->display = g.display;
    return *this;
}

void Game::play()
{

    while (42)
    {
        clock_t x_startTime = clock();
        computeMoves();
        computePlayfield();

        if (this->p1.getPv() == 0)
            this->p1.die();
        if (this->p1.getLives() == 0)
            break;

        this->display.printHud(p1.getPv(), p1.getLives(), this->eFactory.getScore());
        while (this->display.render(this->playfield))
            std::cout << "please resize your window";

        takeInputUntilNextFrame(x_startTime);
    }
}

void Game::takeInputUntilNextFrame(clock_t x_startTime)
{
    int time_left = 0;
    clock_t x_countTime;

    this->p1.stop();

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
    this->eFactory.move();
}

void Game::computePlayfield()
{
    std::memset(this->playfield, ' ', PLAYGROUND_H * PLAYGROUND_W);
    this->playfield[this->p1.getPosY()][this->p1.getPosX()] = this->p1.getOutput();
    this->eFactory.computePlayfield(playfield, this->p1);
}