#include "Board.h"


void initBoard()
{
  for( int i = 0; i < 8; ++i )
    {
      for( int j = 0; j< 8; ++j )
	{
	  board[i][j] = None;
	}
    }
  board[0][3] = WhiteKing;
  board[0][4] = WhiteQueen;
  board[0][2] = board[0][5] = WhiteRunner;
  board[0][1] = board[0][6] = WhiteHorse;
  board[0][0] = board[0][7] = WhiteSteeple;
  for( int i = 0 ; i < 8 ; ++i )
    {
      board[1][i] = WhiteSolider;
    }
  
  board[7][3] = WhiteKing;
  board[7][4] = WhiteQueen;
  board[7][2] = board[7][5] = WhiteRunner;
  board[7][1] = board[7][6] = WhiteHorse;
  board[7][0] = board[7][7] = WhiteSteeple;
  for( int i = 0 ; i < 8 ; ++i )
    {
      board[6][i] = WhiteSolider;
    }
}

void boardDiff( Diff diff );
