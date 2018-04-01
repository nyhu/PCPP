#include "Game.hpp"

Game::Game() : p2(NULL)
{
}

Game::Game(const Game &g)
{
    *this = g;
}

Game::~Game()
{
    if (p2)
        delete p2;
}

// WARNING each display reference the same ncurse windows.
// Avoid this usage as it's not necessary to run the game.
Game &Game::operator=(const Game &g) 
{
    this->display = g.display;
    return *this;
}

void Game::menu()
{
    bool twoPlayer = false;
    while (42)
    {
        display.menu(twoPlayer);

        int input = 0;
        while ((input = getch()) != ERR)
            switch (input)
            {
            case KEY_DOWN:
                twoPlayer = true;
                break;
            case KEY_UP:
                twoPlayer = false;
                break;
            case 10:
                if (twoPlayer)
                    p2 = new Player(30, MAX_H - 20);
                return;
            }
    }
}

void Game::play()
{
    while (42)
    {
        clock_t x_startTime = clock();
        computeMoves();
        computeAttacks();
        computePlayfield();

        if (this->p1.getPv() == 0)
            this->p1.die();
        if (this->p1.getLives() == 0)
            break;

        this->display.printHud(p1.getPv(), p1.getLives(), p1.score, this->eFactory.getEnemyNb());
        if (p2)
            this->display.printHudP2(p2->getPv(), p2->getLives(), p2->score, this->eFactory.getEnemyNb());
        while (this->display.render(this->playfield, this->bgPlayfield))
            std::cout << "please resize your window";

        if (takeInputUntilNextFrame(x_startTime))
            break;
    }
}

bool Game::takeInputUntilNextFrame(clock_t x_startTime)
{
    int time_left = 0;
    clock_t x_countTime;

    p1.stop();
    if (p2)
        p2->stop();

    time_left = FRAME_CLOCK;
    while (time_left > 0)
    {
        int input = 0;
        while ((input = getch()) != ERR) {
            if (this->p1.control(input))
                return true;
            if (p2 && this->p2->controlP2(input))
                return true;
        }
        x_countTime = clock();
        time_left = FRAME_CLOCK + x_startTime - x_countTime;
    }
    return false;
}

void Game::computeMoves()
{
    this->bg.move();
    this->p1.move();
    if (p2)
        p2->move();
    this->eFactory.move();
}

void Game::computeAttacks()
{
    p1.bullets.pushBullet(p1.attack());
    if (p2)
        p2->bullets.pushBullet(p2->attack());
    eFactory.attack();
}

void Game::computePlayfield()
{
    std::memset(this->playfield, ' ', PLAYGROUND_H * PLAYGROUND_W);
    std::memset(this->bgPlayfield, ' ', PLAYGROUND_H * PLAYGROUND_W);

    this->bg.computePlayfield(this->bgPlayfield);
    eFactory.collide(this->p1);
    this->playfield[this->p1.getPosY()][this->p1.getPosX()] = this->p1.getOutput();
    if (p2)
    {
        eFactory.collide(*this->p2);
        this->playfield[this->p2->getPosY()][this->p2->getPosX()] = this->p2->getOutput();
    }
    this->eFactory.computePlayfield(this->playfield, this->p1, this->p2);
}
