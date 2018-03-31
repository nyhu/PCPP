#include "Display.hpp"

Display::Display()
{
    initscr();            // init ncurse
    cbreak();             // desactivate input buffering: one char at a time
    noecho();             // doesn't echo input characters
    keypad(stdscr, TRUE); // get special char like arrows and delete

    this->win = newwin(WINSIZE_Y, WINSIZE_X, 0, 0);
}

Display::Display(const Display &d)
{
    *this = d;
}

Display::~Display()
{
    endwin(); // delete memory used by ncurse
}

Display &Display::operator=(const Display &d) {
    this->win = d.win;
    return *this;
}