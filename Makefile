TARGET=Chess
OBJ=Main.c Screen.c Board.c
CFLAGS=-lncurses

all:
	gcc -o $(TARGET) $(OBJ) $(CFLAGS)
