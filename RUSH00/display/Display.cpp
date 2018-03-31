#include "Display.hpp"

Display::Display()
{
    initscr();            // init ncurse
    cbreak();             // desactivate input buffering: one char at a time
    noecho();             // doesn't echo input characters
    nodelay(stdscr, TRUE);// getch() return imediatly if no key is pressed
    keypad(stdscr, TRUE); // get special char like arrows and delete

    start_color(); // init color usage
    init_pair(NORMAL_COLOR, COLOR_WHITE, COLOR_BLACK);
    init_pair(BORDER_COLOR, COLOR_BLACK, COLOR_MAGENTA);

    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    this->maxH = w.ws_row;
    this->maxW = w.ws_col;
    this->mainWinH = (this->maxH - PLAYGROUND_H) / 2;
    this->mainWinW = (this->maxW - PLAYGROUND_W) / 2;
    this->win = newwin(PLAYGROUND_H, PLAYGROUND_W, this->mainWinH, this->mainWinW); // init a window
}

Display::Display(const Display &d)
{
    *this = d;
}

Display::~Display()
{
    delwin(this->win); // delete win from memory
    endwin();          // reset default term settings
}

Display &Display::operator=(const Display &d)
{
    this->win = d.win;
    this->maxH = d.maxH;
    this->maxW = d.maxW;
    this->mainWinH = d.mainWinH;
    this->mainWinW = d.mainWinW;
    return *this;
}

int Display::resizeHandler()
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    if (this->maxH == w.ws_row && this->maxW == w.ws_col)
        return 0;
    if (w.ws_row < PLAYGROUND_H || w.ws_col < PLAYGROUND_W)
        return 1;
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); // erase borders
    wrefresh(this->win);                                  // erase win content
    delwin(this->win);                                    // free win in memory

    this->maxH = w.ws_row;
    this->maxW = w.ws_col;
    this->mainWinH = (this->maxH - PLAYGROUND_H) / 2;
    this->mainWinW = (this->maxW - PLAYGROUND_W) / 2;
    this->win = newwin(PLAYGROUND_H, PLAYGROUND_W, this->mainWinH, this->mainWinW);

    return 0;
}

void Display::renderBorders()
{
    wattron(win, COLOR_PAIR(BORDER_COLOR));
    wborder(win, '|', '|', '-', '-', '*', '*', '*', '*');
    wattron(win, COLOR_PAIR(NORMAL_COLOR));
}

int Display::render()
{
    if (resizeHandler())
        return 1;
    renderBorders();
    wrefresh(this->win);
    return 0;
}
