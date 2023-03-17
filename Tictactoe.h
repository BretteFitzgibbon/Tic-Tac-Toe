#ifndef TICTACTOE_H  // INCLUDE GUARDS: IF we have not already defined this variable...
#define TICTACTOE_H  
//... then create it

#include <vector>

/*

  This .h file has already been written for you.  It is the "blueprint" for your Tictactoe class

  Note that we use "include guards" above (and below) to protect 
  against including this file more than once in our final executable program

  (Do not change this file)

*/

class Tictactoe 
{ // a blueprint for our class (implementation goes in the corresponding .cpp file)

  private:
    char grid[3][3]; // the game board - a 2D array of characters; NOTE: rows and columns go from 0 to 2, not 1 to 3! 
    char emptyToken;  // the character we want to use to represent an empty space on the board

  public:
    Tictactoe(); // default constructor sets the emptyToken and initializes all grid positions to that value
    Tictactoe(char _emptyToken);  // 2nd constructor - sets the empty token only, then inits the grid
    Tictactoe(char _emptyToken, std::vector<char> initTokens);  // 3rd constructor: sets the empty token and initial board tokens based in the initTokens vector (warning.. the initTokens vector could be shorter or longer than 9 characters!)

    bool takeTurn(int rownum, int colnum, char playerToken); // try to place the specified player token at location [r][c] on the board 
                                             // NOTE above that r and c are in the range of (1 to 3) when passed to the method
    bool isWin(char playerChar); // returns true if the specified player token has won the game
    bool isTie();    // returns true if the game is a tie
    void printMe(); // prints the game board
    
}; // end of TicTacToe class "blueprint"
#endif