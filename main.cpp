#include <iostream>
#include <string>
#include <vector>
#include "Tictactoe.h" 
#include "TestMe.xxx" 

using namespace std;

int main() 
{
  TestMe testInstance; 

  cout << "Let's Play Tic Tac Toe...\n";
  cout << endl;

  Tictactoe myGame;
  vector <char> playerTokens = {'O', 'X'};
  int currentPlayerId = 0;

  myGame.printMe(); 
  cout << endl;
  
  cout << "Enter a move by row (1-3) and column (1-3)." << endl;
  cout << endl;

  while (true)
    {
      int row;
      int column;
      bool turn;
      cout << playerTokens[currentPlayerId] << " \'s turn. ";

      while (true) // repeats in a loop until the player whose turn it is makes a valid move
        {
          cin >> row >> column;
          turn = myGame.takeTurn(row, column, playerTokens[currentPlayerId]); // determines whether the player currently taking a turn is O or X
          if (turn) // if a move is valid
            break;
          else
            cout << "Go again" << endl;
        }

        myGame.printMe();
        cout << endl;
        currentPlayerId++;
        currentPlayerId %= 2;  // currentPlayerId will always be 0 or 1

      if (myGame.isWin('O'))
        {
          cout << "Congratulations Player O!" << endl;
          cout << "Goodbye";
          break;
        }
      else if (myGame.isWin('X'))
        {
          cout << "Congratulations Player X!" << endl;
          cout << "Goodbye";
          break;
        }
      else if (myGame.isTie())
      {
        cout << "Goodbye"; 
        break;
      }    
    }
}
      
