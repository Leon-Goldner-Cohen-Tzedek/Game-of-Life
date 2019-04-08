#include <iostream>
using namespace std;
#define GAME_BOARD_SIZE 12

void scan(int array[][GAME_BOARD_SIZE]);
// scans every single cell's neighbours, returns the "cell's number"
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
  bool game_over = 0;

  while (game_over != 1)
  {
    for (int i = 0; i < GAME_BOARD_SIZE; i++)
    {
      game_board[i][i] = i;
    }
    scan(game_board);
    game_over = 1;
  }

  return 0;
}

void scan(int array[][GAME_BOARD_SIZE])
{
  for (int x = 0; x < GAME_BOARD_SIZE; x++) //using x represents columns better
  {
    for (int i = 0; i < 8; i++)
    {
      
    }
  }
}
