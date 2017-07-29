#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "Board.h"

#include <ncurses.h>

#define SQUARE_SIZE 2



WINDOW *squareWindows[8][8];
WINDOW *ioWindow;

void initScreen();

void refreshScreen();

void drawDiff( Diff diff );

void endScreen();

#endif
