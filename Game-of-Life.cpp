#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// one_gens every single cell's neighbours, returns the "cell's number"
//       Cell's number is the sum of all the cells around it. +1 for all the alive cells, +0 for all the dead cells

//  makes a new game board and copies the new board into it with these rules <====+
//    Any live cell with a cells number of 2 live neighbours dies (becomes 0)     |
//     Any live cell with a cells number of two or three lives on (stays 1)       |
//     Any live cell a cells number of  more than 3 dies (becomes 0)              |
//     Any dead cell with a cells number of exactly 3 l a live cell (becomes1)    |
//iterates by column only, then by row                                            |
//uses cell's number to decide the rules above >>=================================+

int main (int argc, char* argv[])
{
  const char DEAD_CHAR = '0';
  const char LIVE_CHAR = '1';
  const int GAME_BOARD_SIZE = 12;


  char game_board[GAME_BOARD_SIZE][GAME_BOARD_SIZE];
  char newGB[GAME_BOARD_SIZE][GAME_BOARD_SIZE];

  bool game_over = 0;

  ifstream config(argv[1]);

  for (int y = 0; y < GAME_BOARD_SIZE - 2; y++)
  {
    for (int x = 0; x < GAME_BOARD_SIZE - 2; x++)
    {
      config >> game_board[x][y];
      cout << game_board[x][y];
    }
  }

  for (int i = 0; i < stoi(argv[2]); i++)
  {
    int cells_number;

    for (int y = 0; y < GAME_BOARD_SIZE - 2; y++) //using x,y represents columns better
    {
      for (int x = 0; x < GAME_BOARD_SIZE - 2; x++)
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

          //checking and populating the new game board
          if (cells_number < 2)
          {
            newGB[x][y] = DEAD_CHAR;
          }
          else if (cells_number == 2 || cells_number == 3)
          {
            newGB[x][y] = LIVE_CHAR;
          }
          else if (cells_number > 3)
          {
            newGB[x][y] = DEAD_CHAR;
          }
      }
    }

    //transfering the new game board to the old one
    for (int y = 0; y < GAME_BOARD_SIZE - 2; y++)
    {
      for (int x = 0; x < GAME_BOARD_SIZE - 2; x++)
      {
        game_board[x][y] = newGB[x][y];
      }
    }

    for (int y = 0; y < GAME_BOARD_SIZE - 2; y++)
    {
      for (int x = 0; x < GAME_BOARD_SIZE - 2; x++)
      {
        if (game_board[x][y] == LIVE_CHAR)//replaces the 1s and 0s with a nicer looking thing
        {
          cout << " " << "#" << " ";
        }
        else
        {
          cout << " " << "." << " ";
        }
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
