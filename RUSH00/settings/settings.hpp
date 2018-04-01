#ifndef __SETTINGS__
#define __SETTINGS__

#define WINSIZE_W 300 // n_line
#define WINSIZE_H 100 // n_col
#define PLAYGROUND_W 150 // n_col
#define PLAYGROUND_H 50 // n_col
#define MAX_W PLAYGROUND_W - 2 // n_col
#define MAX_H PLAYGROUND_H - 2 // n_col
#define MIN_W 1
#define MIN_H 1

#define FRAME_CLOCK 100000

typedef char t_playfield[PLAYGROUND_H][PLAYGROUND_W] ;

#endif