#ifndef __BOARD_H__
#include "Basics.h"

typedef struct
{
  unsigned short x;
  unsigned short y;
  unsigned short value;
} Square;

Square board[8][8];


void initBoard();

void boardDiff( Diff diff );


#endif
