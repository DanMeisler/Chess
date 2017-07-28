#include "Screen.h"
#include "stdio.h"
#include <stdlib.h>
static void drawBoardSquare( unsigned short x, unsigned short y, unsigned short value )
{
  wmove( win, x, y + 1 );
  switch( value )
    {
    case None:
      wprintw( win, " ");
      break;
    case WhiteKing:
    case BlackKing:
      wprintw( win, "K");
      break;
    case WhiteQueen:
    case BlackQueen:
      wprintw( win, "Q");
      break;
      
    case WhiteSteeple:
    case BlackSteeple:
      wprintw( win, "#");
      break;
      
    case WhiteRunner:
    case BlackRunner:
      wprintw( win, "R");
      break;
      
    case WhiteHorse:
    case BlackHorse:
      wprintw( win, "$");
      break;
      
    case WhiteSolider:
    case BlackSolider:
      wprintw( win, "!");
      break;
    }
}


void initScreen()
{
  initscr();
  start_color();
  init_pair( 1, COLOR_YELLOW, COLOR_BLUE );
  win = newwin(20, 20, 0, 0);
  refreshScreen();
  wgetch( win );
}


void refreshScreen()
{
  werase( win );
  char str[2];
  for( int i = 1; i < 9; ++i )
    {
      
      wmove( win, 8, i );
      sprintf( str, "%d", i );
      wprintw( win, str );
    }
  for( int i = 0; i < 8; ++i )
    {
      wmove( win, i, 0 );
      sprintf( str, "%c", (8 - i) + 64 );
      wprintw( win, str );
    }
  
  for( int i = 0; i < 8 ; ++i )
    {
      for( int j = 0 ; j < 8 ; ++j )
	{
	  drawBoardSquare( i, j, board[i][j] );
	}
    }
  wbkgd( win, COLOR_PAIR(1) );
  wmove( win, 1, 0 );
  wrefresh( win );
}

void endScreen()
{
  endwin();
  delwin( win );
}
