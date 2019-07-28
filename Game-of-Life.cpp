#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (int argc, char* argv[])
{
  const char DEAD_CHAR = '0';
  const char LIVE_CHAR = '1';
  const int GAME_BOARD_SIZE = 12;


  char game_board[GAME_BOARD_SIZE][GAME_BOARD_SIZE];
  char temp_game_board[GAME_BOARD_SIZE][GAME_BOARD_SIZE];


  ifstream config;
  config.open(argv[1]);

// initial config
  for (int y = 0; y < GAME_BOARD_SIZE; y++)
  {
    for (int x = 0; x < GAME_BOARD_SIZE; x++)
    {
      config >> game_board[x][y]; // loads the config file
      if (game_board[x][y] == LIVE_CHAR)//replaces the 1s and 0s with a nicer looking thing
      {
        cout << " # ";
      }
      else
      {
        cout << " . ";
      }
    }
    cout << endl;
  }
  cout << " Gen 0" << endl << endl;

//generation based for loop, arg2 is the number of gens
  for (int i = 0; i < stoi(argv[2]); i++)
  {
    for (int y = 0; y < GAME_BOARD_SIZE; y++) //using x,y represents columns better
    {
      for (int x = 0; x < GAME_BOARD_SIZE; x++)
      {
          int cells_number = 0;

          //core logic (IT'S KIND OF BROKEN)
          if (game_board[x][y-1] == LIVE_CHAR) {cells_number++;}
          if (game_board[x][y+1] == LIVE_CHAR) {cells_number++;}

          if (game_board[x-1][y] == LIVE_CHAR) {cells_number++;}
          if (game_board[x+1][y] == LIVE_CHAR) {cells_number++;}

          if (game_board[x-1][y-1] == LIVE_CHAR) {cells_number++;}
          if (game_board[x+1][y+1] == LIVE_CHAR) {cells_number++;}

          if (game_board[x+1][y-1] == LIVE_CHAR) {cells_number++;}
          if (game_board[x-1][y+1] == LIVE_CHAR) {cells_number++;}

          //    Any live cell with a cells number of 2 live neighbours dies (becomes 0)
          //     Any live cell with a cells number of two or three lives on (stays 1)
          //     Any live cell a cells number of  more than 3 dies (becomes 0)
          //     Any dead cell with a cells number of exactly 3 l a live cell (becomes1)
          //checking and populating the new game board (part of core logic)
          if (cells_number < 2)
          {
            temp_game_board[x][y] = DEAD_CHAR;
          }
          else if (cells_number == 3)
          {
            temp_game_board[x][y] = LIVE_CHAR;
          }
          else if (cells_number > 3)
          {
            temp_game_board[x][y] = DEAD_CHAR;
          }
        }
    }

    //transfering the temp_game_board  to the original
    for (int y = 0; y < GAME_BOARD_SIZE; y++)
    {
      for (int x = 0; x < GAME_BOARD_SIZE; x++)
      {
        game_board[x][y] = temp_game_board[x][y];
      }
    }

    for (int y = 0; y < GAME_BOARD_SIZE; y++)
    {
      for (int x = 0; x < GAME_BOARD_SIZE; x++)
      {
        if (game_board[x][y] == LIVE_CHAR)//replaces the 1s and 0s with a nicer looking thing
        {
          cout << " # ";
        }
        else
        {
          cout << " . ";
        }
      }
      cout << endl;
    }
    cout << " Gen " << i + 1 << endl << endl;
  }

  return 0;
}
// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;
//
// #define DEAD_CHAR '0'
// #define LIVE_CHAR '1'
//
// void read_board(char* file_name, char board[][SIZE])
// {
//     ifstream config;
//     config.open(argv[1]);
//
//     for (int y = 0; y < GAME_BOARD_SIZE; y++)
//     {
//         for (int x = 0; x < GAME_BOARD_SIZE; x++)
//         {
//           config >> game_board[x][y]; // loads the config file
//           if (game_board[x][y] == LIVE_CHAR)//replaces the 1s and 0s with a nicer looking thing
//           {
//             cout << " # ";
//           }
//           else
//           {
//             cout << " . ";
//           }
//     }
//     cout << endl;
//     }
// }
//
// void print_board(char board[GAME_BOARD_SIZE][GAME_BOARD_SIZE])
// {
//   // initial config
//   for (int y = 0; y < GAME_BOARD_SIZE; y++)
//   {
//     for (int x = 0; x < GAME_BOARD_SIZE; x++)
//     {
//       if (game_board[x][y] == LIVE_CHAR)//replaces the 1s and 0s with a nicer looking thing
//       {
//         cout << " # ";
//       }
//       else
//       {
//         cout << " . ";
//       }
//     }
//     cout << endl;
//   }
// }
//
// int count_neighbors(char board[][GAME_B])
// {
//     int cells_number = 0;
//
//     //core logic (IT'S KIND OF BROKEN)
//     if (game_board[x][y-1] == LIVE_CHAR) {cells_number++;}
//     if (game_board[x][y+1] == LIVE_CHAR) {cells_number++;}
//
//     if (game_board[x-1][y] == LIVE_CHAR) {cells_number++;}
//     if (game_board[x+1][y] == LIVE_CHAR) {cells_number++;}
//
//     if (game_board[x-1][y-1] == LIVE_CHAR) {cells_number++;}
//     if (game_board[x+1][y+1] == LIVE_CHAR) {cells_number++;}
//
//     if (game_board[x+1][y-1] == LIVE_CHAR) {cells_number++;}
//     if (game_board[x-1][y+1] == LIVE_CHAR) {cells_number++;}
//
//     return cells_number;
// }
//
// void copy_board(board, temp)
// {
//     //transfering the temp_game_board  to the original
//     for (int y = 0; y < GAME_BOARD_SIZE; y++)
//     {
//       for (int x = 0; x < GAME_BOARD_SIZE; x++)
//       {
//         game_board[x][y] = temp_game_board[x][y];
//       }
//     }
// }
//
// void generation(char board[][GAME_BOARD_SIZE])
// {
//      for (int y = 0; y < GAME_BOARD_SIZE; y++) //using x,y represents columns better
//     {
//       for (int x = 0; x < GAME_BOARD_SIZE; x++)
//       {
//           // INT COUNT_NEIGHBORS(char board[][size])
//
//           int cells_number = count_neighbors(board);
//
//           //    Any live cell with a cells number of 2 live neighbours dies (becomes 0)
//           //     Any live cell with a cells number of two or three lives on (stays 1)
//           //     Any live cell a cells number of  more than 3 dies (becomes 0)
//           //     Any dead cell with a cells number of exactly 3 l a live cell (becomes1)
//           //checking and populating the new game board (part of core logic)
//           if (cells_number < 2)
//           {
//             temp_game_board[x][y] = DEAD_CHAR;
//           }
//           else if (cells_number == 3)
//           {
//             temp_game_board[x][y] = LIVE_CHAR;
//           }
//           else if (cells_number > 3)
//           {
//             temp_game_board[x][y] = DEAD_CHAR;
//           }
//         }
//     }
//
//     // copy board
//     copy_board(board, temp);
// }
//
//
// int main (int argc, char* argv[])
// {
//   const char DEAD_CHAR = '0';
//   const char LIVE_CHAR = '1';
//   const int GAME_BOARD_SIZE = 12;
//
//   char game_board[GAME_BOARD_SIZE][GAME_BOARD_SIZE];
//   char temp_game_board[GAME_BOARD_SIZE][GAME_BOARD_SIZE];
//
//   // initial config
//   read_board(argv[1], game_board);
//
//   // print board
//   print_board(game_board);
//
//   cout << " Gen 0" << endl << endl;
//
// //generation based for loop, arg2 is the number of gens
//   for (int i = 0; i < stoi(argv[2]); i++)
//   {
//     generation(game_board);
//
//     // print board
//     print_board(board);
//
//     cout << " Gen " << i + 1 << endl << endl;
//   }
//
//   return 0;
// }
