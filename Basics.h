#ifndef __BASICS_H__

enum ChessTool{
  None,
  WhiteKing,
  BlackKing,
  WhiteQueen,
  BlackQueen,
  WhiteSteeple,
  BlackSteeple,
  WhiteRunner,
  BlackRunner,
  WhiteHorse,
  BlackHorse,
  WhiteSolider,
  BlackSolider
};


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
} Diff;

#endif
