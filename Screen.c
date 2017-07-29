#include "Screen.h"
#include "stdio.h"
#include <stdlib.h>
static void drawBoardSquare( unsigned short value, WINDOW *square )
{
  chtype currentColor = getbkgd( square );
  chtype newColor = COLOR_PAIR( value % 2 ?
				( currentColor > 2 ? 3 : 1 ) :
				( currentColor > 2 ? 4 : 2 )
				);
  printf("%ul",(unsigned int) newColor);
  
  switch( value )
    {
    case None:
      wprintw( square, " ");
      break;
    case WhiteKing:
    case BlackKing:
      wprintw( square, "KKKK");
      break;
    case WhiteQueen:
    case BlackQueen:
      wprintw( square, "Q");
      break;
      
    case WhiteSteeple:
    case BlackSteeple:
      wprintw( square, "#");
      break;
      
    case WhiteRunner:
    case BlackRunner:
      wprintw( square, "R");
      break;
      
    case WhiteHorse:
    case BlackHorse:
      wprintw( square, "$");
      break;
      
    case WhiteSolider:
    case BlackSolider:
      wprintw( square, "!");
      break;
    }
  wbkgdset( square, newColor );
  wrefresh( square );
}


void initScreen()
{
  initscr();
  start_color();
  init_pair( 1, COLOR_WHITE, COLOR_GREEN );
  init_pair( 2, COLOR_BLACK, COLOR_GREEN );
  init_pair( 3, COLOR_WHITE, COLOR_YELLOW );  
  init_pair( 4, COLOR_BLACK, COLOR_YELLOW );

  ioWindow = newwin( 1, 0, LINES - 1, 0 );
  wbkgd( ioWindow, COLOR_PAIR(1) );
  wrefresh( ioWindow );
  for( int i = 0; i < 8; ++i )
    {
          for( int j = 0; j < 8; ++j )
  	    {
  	      squareWindows[i][j] = newwin( SQUARE_SIZE, SQUARE_SIZE, i * SQUARE_SIZE, j * SQUARE_SIZE );
  	      wbkgd( squareWindows[i][j], ( i + j ) % 2 ? COLOR_PAIR( 1 ) : COLOR_PAIR( 3 ) );
  	      wrefresh( squareWindows[i][j] );
  	    }
    }

  refreshScreen();
  wgetch( ioWindow );
}


void refreshScreen()
{
  for( int i = 0; i < 8 ; ++i )
    {
      for( int j = 0 ; j < 8 ; ++j )
	{
	  drawBoardSquare( board[i][j], squareWindows[i][j] );
	}
    }
}

void endScreen()
{
  endwin();
  for( int i = 0; i < 8; ++i )
    for( int j = 0; j < 8; ++j )
      delwin( squareWindows[i][j] );
  delwin( ioWindow );
}
