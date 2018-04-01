#include "Display.hpp"

Display::Display() : hudP2(NULL)
{
    initscr(); // init ncurse
    // cbreak();              // desactivate input buffering: one char at a time
    curs_set(0);           // hide cursor
    noecho();              // doesn't echo input characters
    nodelay(stdscr, TRUE); // getch() return imediatly if no key is pressed
    keypad(stdscr, TRUE);  // get special char like arrows and delete

    start_color(); // init color usage
    init_pair(NORMAL_COLOR, COLOR_WHITE, COLOR_BLACK);
    init_pair(BORDER_COLOR, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(BACKGROUND_COLOR, COLOR_BLUE, COLOR_BLACK);
    init_pair(ENEMY_COLOR, COLOR_RED, COLOR_BLACK);
    init_pair(P1_COLOR, COLOR_CYAN, COLOR_BLACK);
    init_pair(P2_COLOR, COLOR_GREEN, COLOR_BLACK);

    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    this->maxH = w.ws_row;
    this->maxW = w.ws_col;
    this->mainWinH = (this->maxH - PLAYGROUND_H) / 2;
    this->mainWinW = (this->maxW - PLAYGROUND_W) / 2;
    this->win = newwin(PLAYGROUND_H, PLAYGROUND_W, this->mainWinH, this->mainWinW); // init a game window

    this->hud = newwin(2, PLAYGROUND_W, this->mainWinH - 2, this->mainWinW);              // init a hud window
    this->hudP2 = newwin(2, PLAYGROUND_W, this->mainWinH + PLAYGROUND_H, this->mainWinW); // init a hud window
}

Display::Display(const Display &d)
{
    *this = d;
}

Display::~Display()
{
    delwin(this->win); // delete win from memory
    delwin(this->hud); // delete win from memory
    endwin();          // reset default term settings
}

Display &Display::operator=(const Display &d)
{
    this->win = d.win;
    this->maxH = d.maxH;
    this->maxW = d.maxW;
    this->mainWinH = d.mainWinH;
    this->mainWinW = d.mainWinW;
    this->hud = d.hud;
    this->hudP2 = d.hudP2;
    return *this;
}

int Display::resizeHandler()
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    if (w.ws_row < PLAYGROUND_H + 4 || w.ws_col < PLAYGROUND_W) // for hight we had huds total size
        return 1;
    if (this->maxH == w.ws_row && this->maxW == w.ws_col)
        return 0;
    wborder(this->win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); // erase borders
    wrefresh(this->win);                                        // erase win content
    delwin(this->win);                                          // free win in memory

    wborder(this->hud, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); // erase borders
    wrefresh(this->hud);                                        // erase hud content
    delwin(this->hud);                                          // free hud in memory

    wborder(this->hudP2, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '); // erase borders
    wrefresh(this->hudP2);                                        // erase hud content
    delwin(this->hudP2);                                          // free hud in memory

    this->maxH = w.ws_row;
    this->maxW = w.ws_col;
    this->mainWinH = (this->maxH - PLAYGROUND_H) / 2;
    this->mainWinW = (this->maxW - PLAYGROUND_W) / 2;
    this->win = newwin(PLAYGROUND_H, PLAYGROUND_W, this->mainWinH, this->mainWinW);

    this->hud = newwin(2, PLAYGROUND_W, this->mainWinH - 2, this->mainWinW);              // init a hud window
    this->hudP2 = newwin(2, PLAYGROUND_W, this->mainWinH + PLAYGROUND_H, this->mainWinW); // init a hud window

    return 0;
}

void Display::renderBorders(WINDOW *w, int color)
{
    wattron(w, COLOR_PAIR(color));
    wborder(w, '|', '|', '-', '-', '*', '*', '*', '*');
    wattron(w, COLOR_PAIR(NORMAL_COLOR));
}

int Display::menu(int nbPlayer)
{
    if (resizeHandler())
        return 1;
    renderBorders(this->win, BORDER_COLOR);

    wattron(this->win, COLOR_PAIR(nbPlayer ? NORMAL_COLOR : BORDER_COLOR));
    wmove(this->win, PLAYGROUND_H / 2 - 2, PLAYGROUND_W / 2 - 3);
    waddstr(this->win, "1 PLAYER");
    wattron(this->win, COLOR_PAIR(nbPlayer ? BORDER_COLOR : NORMAL_COLOR));
    wmove(this->win, PLAYGROUND_H / 2 + 2, PLAYGROUND_W / 2 - 3);
    waddstr(this->win, "2 PLAYER");
    wattron(this->win, COLOR_PAIR(NORMAL_COLOR));

    wrefresh(this->win);
    return 0;
}

void Display::printBgPlayfield(t_playfield playfield)
{
    wattron(this->win, COLOR_PAIR(BACKGROUND_COLOR));

    for (int y = 1; y < PLAYGROUND_H - 1; y++)
        for (int x = 1; x < PLAYGROUND_W - 1; x++)
            mvwaddch(this->win, y, x, playfield[y][x]);

    wattron(this->win, COLOR_PAIR(NORMAL_COLOR));
}

void Display::printPlayfield(t_playfield playfield, int color)
{
    wattron(this->win, COLOR_PAIR(color));
    for (int y = 1; y < PLAYGROUND_H - 1; y++)
        for (int x = 1; x < PLAYGROUND_W - 1; x++)
            if (playfield[y][x] != ' ')
                mvwaddch(this->win, y, x, playfield[y][x]);
    wattron(this->win, COLOR_PAIR(NORMAL_COLOR));                
}

void Display::printHud(int pv, int lives, int score, int enemyNb)
{
 std::ostringstream s;
    s << "  PV : " << std::right << std::setw(3) << pv << " / " << 100;
    s << "  LIVES : " << std::right << std::setw(3) << lives << " / " << 3;
    s << "  SCORE : " << std::left << std::setw(20) << score;
    s << "  ENEMIES LEFT BEFORE NEXT WAVE: " << std::left << std::setw(20) << enemyNb;

    wattron(this->hud, COLOR_PAIR(BORDER_COLOR));
    wborder(this->hud, '|', '|', '-', '-', '*', '*', '*', '*');
    wattron(this->hud, COLOR_PAIR(NORMAL_COLOR));

    wmove(this->hud, 1, 2);
    waddstr(this->hud, s.str().c_str());

    wrefresh(this->hud);
}

void Display::printHudP2(int pv, int lives, int score, int enemyNb)
{
    std::ostringstream s;
    s << "  PV : " << std::right << std::setw(3) << pv << " / " << 100;
    s << "  LIVES : " << std::right << std::setw(3) << lives << " / " << 3;
    s << "  SCORE : " << std::left << std::setw(20) << score;
    s << "  ENEMIES LEFT BEFORE NEXT WAVE: " << std::left << std::setw(20) << enemyNb;

    wattron(this->hudP2, COLOR_PAIR(BORDER_COLOR));
    wborder(this->hudP2, '|', '|', '-', '-', '*', '*', '*', '*');
    wattron(this->hudP2, COLOR_PAIR(NORMAL_COLOR));

    wmove(this->hudP2, 0, 2);
    waddstr(this->hudP2, s.str().c_str());

    wrefresh(this->hudP2);
}

int Display::render(t_playfield playfield, t_playfield bgPlayfield, t_playfield playfP1, t_playfield playfP2)
{
    if (resizeHandler())
        return 1;
    renderBorders(this->win, BORDER_COLOR);
    printBgPlayfield(bgPlayfield);
    printPlayfield(playfield, ENEMY_COLOR);
    printPlayfield(playfP1, P1_COLOR);
    printPlayfield(playfP2, P2_COLOR);
    wrefresh(this->win);
    return 0;
}
