#ifndef __DISPLAY__
#define __DISPLAY__

#include <curses.h>
#include "../settings/settings.hpp"

class Display
{
  public:
    Display();
    Display(const Display &d);
    ~Display();

    Display &operator=(const Display &d);

  private:
    WINDOW *win;
};

#endif