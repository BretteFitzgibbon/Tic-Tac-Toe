
#include <iostream>
#include "Tictactoe.h" // The Tictactoe.h file contains our class "blueprint" we must include it so we can reference the class below

/*

  WRITE YOUR OUT-OF-CLASS constructors and methods HERE for the Tic Tac Toe class

  Start each constructor with the name of your class followed by the scope resolution operator like ::, and then the class name (again)

  Start each method with its return type, followed by the name of your class followed the scope resolution operator, and then the method name

  Use the Tictactoe.h file as a guide (along with the README.md file) to help guide which constructors and methods you need to implement.

*/

Tictactoe::Tictactoe() 
{
  emptyToken = '-'; 
  for (int r = 0; r < 3; r++)
    {
     for (int c = 0; c < 3; c++)
      grid[r][c] = emptyToken; 
    }    
}


Tictactoe::Tictactoe(char _emptyToken) //select what symbol to use for empty spaces on the board
{
  emptyToken = _emptyToken; 
  for (int r = 0; r < 3; r++)
    {
     for (int c = 0; c < 3; c++)
      grid[r][c] = _emptyToken; 
    }    
}


Tictactoe::Tictactoe(char _emptyToken, std::vector<char> initTokens) //recreate the configuration from a game in progress
{
  emptyToken = _emptyToken; 
  int counter = 0;
  for (int r = 0; r < 3; r++)
  {
    for (int c = 0; c < 3; c++)
    {
      if (counter < initTokens.size())
      {
        grid[r][c] = initTokens[counter];
        counter++;
      }
        else // when there are more game spaces than tokens in initTokens
          grid[r][c] = _emptyToken;
    }       
  }
}   


bool Tictactoe::takeTurn(int rownum, int colnum, char playerToken)
{
  if (rownum < 1 || rownum > 3 || colnum < 1 || colnum > 3) // outside the bounds of the board
    {
      std::cout << "Move not valid" << std::endl;
      return false;
    }    
  else
  {
    rownum--; // players enter rows and columns from 1 to 3, but the computer's indexing interprets spaces on the board based on indices starting with 0 
    colnum--;
    if (grid[rownum][colnum] != emptyToken)
      {
        std::cout << "Space already occupied" << std::endl;
        return false;
      }
    else
    {
     grid[rownum][colnum] = playerToken;
      return true;
    }    
  }
}


 bool Tictactoe::isWin(char playerToken) // all possible three-in-a-row configurations
{
  if (grid[0][0] == playerToken && grid[0][1] == playerToken && grid[0][2] == playerToken)
  {
    std::cout << "Player " << playerToken << " won via Row 1" << std::endl;
    return true;
  }
  else if (grid[2][0] == playerToken && grid[2][1] == playerToken && grid[2][2] == playerToken)
  {
    std::cout << "Player " << playerToken << " won via Row 3" << std::endl;
    return true;
  }
  else if (grid[0][0] == playerToken && grid[1][0] == playerToken && grid[2][0] == playerToken)
  {
    std::cout << "Player " << playerToken << " won via Column 1" << std::endl;
    return true;
  }
  else if (grid[0][2] == playerToken && grid[1][2] == playerToken && grid[2][2] == playerToken)
  {
    std::cout << "Player " << playerToken << " won via Column 3" << std::endl;
    return true;
  }
  else if (grid[0][0] == playerToken && grid[1][1] == playerToken && grid[2][2] == playerToken)
  {
    std::cout << "Player " << playerToken << " won via Diagonal 1" << std::endl;
    return true;
  }
  else if (grid[0][2] == playerToken && grid[1][1] == playerToken && grid[2][0] == playerToken)
    {
    std::cout << "Player " << playerToken << " won via Diagonal 2" << std::endl;
    return true;
    }
  else if (grid[1][0] == playerToken && grid[1][1] == playerToken && grid[1][2] == playerToken)
    {
    std::cout << "Player " << playerToken << " won via Row 2" << std::endl;
    return true;
    }
  else if (grid[0][1] == playerToken && grid[1][1] == playerToken && grid[2][1] == playerToken)
    {
    std::cout << "Player " << playerToken << " won via Column 2" << std::endl;
    return true;
    }
  else 
    return false;
}


bool Tictactoe::isTie()
{
  for (int row = 0; row < 3; row++)
    {
      for (int col = 0; col < 3; col++)
        {
          if (grid[row][col] == emptyToken) // game is not over yet
            return false;
        }
    }
  if (isWin('O'))
    return false;
  else if (isWin('X')) 
    return false;
  else 
  {
    std::cout << "It's a tie!" << std::endl;
    return true;
  }    
}


void Tictactoe::printMe()
{ 
  int num = 1; 
  int plus = 1; 
  for (int r = 0; r <= 3; r++) // reinterpret the grid as a 4 x 4 to include the number labels for rows and columns
  {
    for (int c = 0; c <= 3; c++)
    {
      if (r == 0 && c == 0)
        std::cout << ' ';
      else if (r == 0) // label rows 1, 2, and 3
      {
        std::cout << " " << num << " "; 
        num++;
      }   
      else if (c == 0)  // label columns 1, 2, and 3
      {
        std::cout << plus;
        plus++;
      }
      else
        std::cout << " " << grid[r-1][c-1] << " "; // pad each space on the board with spaces on either side
    }
    std::cout << std::endl;
  } 
}
