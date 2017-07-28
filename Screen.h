#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "Board.h"

#include <ncurses.h>

WINDOW *win;
void initScreen();

void refreshScreen();

void drawDiff( Diff diff );

void endScreen();

#endif
