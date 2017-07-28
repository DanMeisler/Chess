#ifndef __SCREEN_H__

#include "Board.h"

typedef struct
{
  unsigned short x;
  unsigned short y;
} Position;

typedef struct
{
  Position *positions;
  unsigned short value;
  unsigned short numOfDiff;
} ScreenDiff;


void refresh();

void drawDiff( ScreenDiff diff );

#endif
