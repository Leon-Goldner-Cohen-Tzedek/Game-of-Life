#include <iostream>
using namespace std;
#define GAME_BOARD_SIZE 12

void one_gen(int game_board[][GAME_BOARD_SIZE], int newGB[][GAME_BOARD_SIZE ]);
void record(int newGB[][GAME_BOARD_SIZE], int x, int y, int cells_number);//records the dead or alive cells
void transfer(int game_board[][GAME_BOARD_SIZE], int newGB[][GAME_BOARD_SIZE]);
// one_gens every single cell's neighbours, returns the "cell's number"
//       Cell's number is the sum of all the cells around it. +1 for all the alive cells, +0 for all the dead cells

//  makes a new game board and copies the new board into it with these rules <====+
//    Any live cell with a cells number of 2 live neighbours dies (becomes 0)     |
//     Any live cell with a cells number of two or three lives on (stays 1)       |
//     Any live cell a cells number of  more than 3 dies (becomes 0)              |
//     Any dead cell with a cells number of exactly 3 l a live cell (becomes1)    |
//iterates by column only, then by row                                            |
//uses cell's number to decide the rules above >>=================================+

int main ()
{
  int game_board[GAME_BOARD_SIZE][GAME_BOARD_SIZE];
  int newGB[GAME_BOARD_SIZE][GAME_BOARD_SIZE];
  bool game_over = 0;

  while (game_over != 1)
  {
    one_gen(game_board, newGB);
    game_over = 1;
  }

  return 0;
}

void one_gen(int game_board[][GAME_BOARD_SIZE], int newGB[][GAME_BOARD_SIZE])
{
  int cells_number;
  for (int x = 0; x < GAME_BOARD_SIZE - 2; x++) //using x,y represents columns better
  {
    for (int y = 0; y < GAME_BOARD_SIZE - 2; y++)
    {
        cells_number = 0;

        if (game_board[x-1][y-1] == 1) {cells_number++;}
        if (game_board[x][y-1] == 1) {cells_number++;}
        if (game_board[x+1][y-1] == 1) {cells_number++;}
        if (game_board[x-1][y] == 1) {cells_number++;}
        if (game_board[x+1][y] == 1) {cells_number++;}
        if (game_board[x-1][y+1] == 1) {cells_number++;}
        if (game_board[x][y+1] == 1) {cells_number++;}
        if (game_board[x+1][y+1] == 1) {cells_number++;}

        record(newGB, x, y, cells_number);
    }
  }

  transfer(game_board, newGB);
}

void record(int newGB[][GAME_BOARD_SIZE], int x, int y, int cells_number)//records the dead or alive cells
{
  if (cells_number < 2)
  {
    newGB[x][y] = 0;
  }
  else if (cells_number == 2 || cells_number == 3)
  {
    newGB[x][y] = 1;
  }
  else if (cells_number > 3)
  {
    newGB[x][y] = 0;
  }
}

void transfer (int game_board[][GAME_BOARD_SIZE], int newGB[][GAME_BOARD_SIZE])
{
  for (int x = 0; x < GAME_BOARD_SIZE; x++)
  {
    for (int y = 0; y < GAME_BOARD_SIZE; y++)
    {
      game_board[x][y] = newGB[x][y];
    }
  }
}
