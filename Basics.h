#ifndef __BASICS_H__


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
