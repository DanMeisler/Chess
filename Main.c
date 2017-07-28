#include "Screen.h"
#include "Board.h"

int main()
{
  initBoard();
  initScreen();
  endScreen();
  printf( "Game Over\n" );
  return 0;
}
