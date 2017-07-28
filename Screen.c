#include "Screen.h"
#include "stdio.h"
#include <ncurses.h>

void initScreen()
{
  initscr();
}

static void drawBoardSquare( unsigned short x, unsigned short y, Square s )
{
  switch( s.value )
    {
    case None:
      printf(" ");
      break;
    case WhiteKing:
    case BlackKing:
      printf("K");
      break;
    case WhiteQueen:
    case BlackQueen:
      printf("Q");
      break;
      
    case WhiteSteeple:
    case BlackSteeple:
      printf("#");
      break;
      
    case WhiteRunner:
    case BlackRunner:
      printf("R");
      break;
      
    case WhiteHorse:
    case BlackHorse:
      printf("$");
      break;
      
    case WhiteSolider:
    case BlackSolider:
      printf("!");
      break;
    }
}

void refreshScreen()
{
  for( int i = 0; i < 8 ; ++i )
    {
      for( int j = 0 ; j < 8 ; ++j )
	{
	  drawBoardSquare( i, j, board[i][j] );
	}
    }
}
