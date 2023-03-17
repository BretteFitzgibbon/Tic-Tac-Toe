# Goal
Write a program that enables 2 human players to play a game of Tic Tac Toe using a 3 by 3 grid and two player tokens 'X' and 'O'.  Your program must implement a class that manages the game and it must utilize "out of class" definitions for all of its constructors and methods. This assignment offers an additional +5 point bonus for implementation of specific enhancments.

 

Your program should fully manage alternating player turns, starting the game with player 'X'.
- Allow players to specify only the row and column number of their choice on a single line (the game should know what token to use, depending on who's turn it is). Row and column numbers range from 1 to 3.  Like this:

```
 X's turn: 1 1 (<- the player enters "1 1")
```

- Row and Column titles should be values 1, 2, or 3. (`even though your data members will start counting from zero!`)
- A player wins when their token occupies all of a single row, column, or diagonal.
- A tie occurs when all positions on the board are filled, but neither player has won the game.
 
```
  1 2 3
1 X - -
2 - O -
3 - - X
```

# Getting Started
You should fork this repl (or just start editing) help you get started

 

# Sample Output
```
Let's play Tic Tac Toe!
  1  2  3
1 -  -  -
2 -  -  -
3 -  -  -

Enter a move like "1 2" for row 1 column 2.
X's turn: 1 1
  1  2  3
1 X  -  -
2 -  -  -
3 -  -  -

O's turn: 2 2
  1  2  3
1 X  -  -
2 -  O  -
3 -  -  -

X's turn: 3 2
  1  2  3
1 X  -  -
2 -  O  -
3 -  X  -

O's turn: 2 1
  1  2  3
1 X  -  -
2 O  O  -
3 -  X  -

X's turn: 3 3
  1  2  3
1 X  -  -
2 O  O  -
3 -  X  X

O's turn: 2 3
  1  2  3
1 X  -  -
2 O  O  O
3 -  X  X

O wins via Row 2
O has won the game!
Goodbye!
```


# Implementation Constraints and Scoring
- The class `Tictactoe` will manage your game. It has been started for you.
- The Tictactoe.h file is provided for you (do not change it).  It provides a "blueprint" for the Tictactoe class, to help you implement the constructors and methods for the Tictactoe class in the Tictactoe.cpp file.  This "separation" between prototypes of the class (.h) and its implementation (.cpp) demonstrates good design methodology!

-  ** (5 points) ** : Code Clarity: Ensure that all curly braces `{` and `}` are aligned within you code.  Match curly brace pairs vertically in the same column (or alternatively: match the closing curly brace to the starting column of the statement that contains the opening brace). Use consistent indentation for all logical blocks of code.  Add blank lines between functions and large blocks of logic to help readability.  Add comments to explain complex code or anytime you are not sure what a specific piece of code is doing!

-  ** (5 points) ** : In the Tictactoe.cpp file, Give your class a default `public constructor` that will initialize the emptyToken to a '-' character, and, and will automatically initialize all grid positions to the emptyToken. Be sure to `implement your constructor OUT OF CLASS` by prefixing it with the name of the class followed by the scope resolution operator.

-  ** (5 points) ** : In the Tictactoe.cpp file, Give your class a `second public constructor` that accepts a char `_emptyToken` as its only argument.  Initialize the private member variable emptyToken using the _emptyToken argument of the constructor.  Initialize the character for all grid positions to the emptyToken. Please note the prefixed underscore "_" character on our local _emptyToken argument.  This subtle name change prevents ambiguity in your constructor between the argument and the private member name.  Be sure to `implement your constructor OUT OF CLASS` by prefixing it with the name of the class followed by the scope resolution operator.

-  ** (5 points) ** : In the Tictactoe.cpp file, Give your class a `third public constructor` that accepts a char `_emptyToken` argument, and a vector of characters `vector<char> initTokens`.  Initialize your private emptyToken member as you did in your second constructor above.    Then, initialize your private grid member by using the character tokens provided in initTokens.  These tokens represent the initial state of our game board.  Providing this type of constructor allows our class to be used to start a game that is "already in progress" because we can specify the entire state of the game board using initTokens.  Note you should take precautions to deal with the situation where initTokens has less than 9 characters. You can use the .size() method of the initTokens vector to determine if it is safe to access all 9 members of that vector, when assigning them to grid.  Be sure to `implement your constructor OUT OF CLASS` by prefixing it with the name of the class followed by the scope resolution operator.

-  ** (5 points) ** : In the Tictactoe.cpp file, Give your class a public `printMe()` function that will print out the current grid in human-readable form (3x3).  You may want to pad each grid token with a space character on either side when you print (3 characters per grid location when printed) to keep your grid square.  Label the rows and columns of your grid with the values 1,2,3 as shown above, to help players see which numbers to use when they enter a move on the keyboard. (see example above). Be sure to `implement this method OUT OF CLASS` by prefixing the method with the name of the class followed by the scope resolution operator.

- Check point 1: To quickly test what you have developed so far, in main(), create an instance of your Tictactoe object and initialize it with default settings.  Then print your game board using the printMe() function. Reinitialize your game with a different empty character token like '.', and print it to be sure it appears correct.  Lastly, reinitialize your game with an empty character and a default string like "XX-O-OX-O" and print it to be sure your printMe() function and your 3nd constructor are working properly.  Ensure that you can print your board correctly before you continue with the assignment. (Note that you will overwrite his "check point 1" code exercise in the steps that follow). 

-  ** (5 points) ** : In the main.cpp file, In your `main()`, using a default initialized instance of your Tictactoe class called myGame,  first print simple instructions for the player to indicate how they should enter a move (row range, column range, etc.).  Then, prompt the user for their FIRST move.  Next, create a while() loop in your main() that continually reads 2 integers from standard input (using cin ) that represent the players row and column move.  Ensure that your program prompts continually for another move after each move is scanned via cin.  (Do not worry at this point about who's turn it is or about what to do with the move information you collected with cin.)


-  ** (5 points) ** : In the main.cpp file, In your `main()`, `define a vector<char> playerTokens` variable that you will use to represent the character tokens which represent each of your players.  For traditional tic tac toe, these characters would be 'X' and 'Y'.  But your playerTokens vector will allow any 2 characters to be used to represent these tokens, if desired.   Initialize your vector to hold your 2 favorite player characters.  Next, in your main(), define a `int currentPlayerId` which will represent the integer id of the current player : either zero or one. Initialize currentPlayerId to 0 (player zero always goes first).  We will use simple modulo math to change the player's turn within your while loop by incrementing the currentPlayerId variable after each successful turn.  Note that `playerTokens[ currentPlayerId ]`  will always give us the character of the current player based on currentPlayerId !! From within your while loop, print out a prompt for the current player, asking them to take their turn as shown above: "X's turn". etc.  Next, before the next loop iteration, update currentPlayerId to move to the next player.  You can use modulo or a simple if/else block to determine the next player's id. Note that you will modify this logic slightly in the steps to follow, so that you only update the currentPlayerId if the player's recent move was valid and the game is not over.

- Check Point 2.  Test the current version of your game to ensure that each new while loop iteration in main() prompts clearly for the next player's turn, alternating between players: "X's turn", then "O's turn", etc. Verify this step before continuing with the assignment. 

-  ** (10 points) ** : In the Tictactoe.cpp file, Give your class a boolean `takeTurn()` method that has 3 arguments: int rownum, int colnum, and char playerToken.  This function will attempt to make a "move" by placing the indicated playerToken on the board at the specified rownum & colnum position.  You will call this class member function from its object instance in main like this: `myGame.takeTurn(???, ???, ???)`. In takeTurn(), verify that row and column numbers range from 1 to 3. Note: you will need to adjust these values so that they are zero based before using them to index into your grid.  If the values entered by the player are out of range, print an appropriate error message from within takeTurn() and return false to indicate that the move has failed.  Otherwise, check to see if the requested grid location already has a non-empty token. (In other words, in takeTurn(), `if (grid[r][c] == emptyToken)`, we can make a move at r, c)  If the grid location is already occupied by a non-empty token, print an appropriate error message from within takeTurn() and return false.  Otherwise, assign the playerToken character to the appropriate location on the grid and return true (you can assume that the player requesting the move is taking their proper turn; you do not need to check who's turn it is in your takeTurn() function. Be sure to `implement this method OUT OF CLASS` by prefixing the method with the name of the class followed by the scope resolution operator.

-  ** (10 points) ** : In the main.cpp file, From your `main()`, within while() loop, insert your takeTurn() function and provide it with the appropriate row and column value as input by the most recent player via cin.  Also send in the token of the most recent player as the 3rd argument of the takeTurn() function.   Remember that you can determine the character of the most recent player in main() as `playerTokens[ currentPlayerId ]`.  Lastly, be sure to store the boolean return value from your takeTurn() function in your while loop so you can tell whether the move was valid or not.

-  ** (10 points) ** : In the main.cpp file, From main(), within your while loop, If the above takeTurn() was valid, update the current player Id (if it was zero, now it needs to be one, etc.).  Then prompt the user for another move.  Be sure to tell the user who's turn it is on each new loop iteration.


- Check Point 3.  Test the current version of your game to ensure that each new move makes the appropriate change to the game board and that it is printed out in a logical fashion that enables interactive play. Be sure that the current player is always indicated before a new move is requested in your main loop.  Be sure that "bad moves" do not advance the current player and that the player who made the bad move is asked to "go again".  Verify this step before continuing with the assignment. 

-  ** (10 points) ** : In the Tictactoe.cpp file, Give your class a boolean `isWin()` function with a single char playerToken argument that will simply test if the current state of the game has been won by the specified character token.  Return true if the board has 3 of the specified player tokens in any row, column or one of the 2 diagonals on the board.  Otherwise return false.  To receive full credit, your isWin() routine MUST print out a message describing which player has won, and HOW they won (by which row, column, or diagonal) any time a win is detected: "Player X won via row1", "Player O won via diagonal 2", etc.  You should be able to call your function from main() like `myGame.isWin('X')`, or even better `myGame.isWin( playerTokens[  currentPlayerId ] )`. Be sure to `implement this method OUT OF CLASS` by prefixing the method with the name of the class followed by the scope resolution operator.

-  ** (10 points) ** : In the Tictactoe.cpp file, Give your class a boolean `isTie()` function that will test whether all locations of the game grid are filled or not, and if any player has won the game.  Your isTie() function can call your isWin() function to determine that there is no win. (this may be necessary since the last move of the game might fill the board and create a "win" condition).  Your isTie() function should return true only if the game is truly tied. Be sure to `implement this method OUT OF CLASS` by prefixing the method with the name of the class followed by the scope resolution operator.

-  ** (10 points) ** : In the main.cpp file, In `main()`, add both your isWin() and isTie() functions to your while() loop and if either state is detected, your while loop should print an appropriate message and exit the game.  Your game should print "goodbye" or something similar to make it clear that the game is over.  You do NOT need to prompt the user to play again when a game is over.

-  ** (5 points) ** : In the main.cpp file, Tune the interactive feedback of your game so that it is understandable and immediately playable based on the instructions you print out.   At no point should a reasonable player (that is "me" ) be left in the dark about when or how to input values for a move, what value are legal, whose turn it is, who won the game, etc.  

# Testing
- Your repl includes 1 testing file:

  - TestMe.xxx


- Your main.cpp includes the following code:



```
#include "TestMe.xxx"    // this file contains the code for the Testme class, which can be used to test your solution before you submit

...

int main() {

   // TestMe testInstance; // Uncomment when ready: default constructor will do the test when it is called (see results: testMeOut.txt when created)
...
}
```

# Bonus Points
If you have completed all aspects of the above project, you may pursue the following enhancements for a maximum total of 15 bonus points.  These points can serve as insurance against your overall Homework grade for the semester (though they will not affect any other aspect of your grade from Quizzes, the Midterm, or the Final Exam). Please indicate when you submit your assignment which of the following bonus tasks, if any, you are attempting.

-  ** (5 points bonus) ** : Enhance your isTie() function to report when the game is effectively tied, even before the board is completely full with moves.  For example, the following situation would be a tie, assuming it is player x's turn to move.  (with your isTie() function, you would never print out the state of the board below, rather you would detect a tie and report that the game is over because it is tied.)
```
X  O  -
X  O  O
O  X  X
X's turn:
```

-  ** (10 points bonus) ** : Automate your game so that player O is controlled intelligently by the computer.  Grading on this task is subject to the effectiveness of a your algorithm.  For example, random selections of open positions on the board is worth only 5 points.

# Concepts Covered in this Homework
- 2d Arrays
- declaration, initialization, access
 classes
- general design of usable classes 
- public and private members
- constructors
- function (method) overloading
- out-of-class methods
- iostream input using cin
- vector container - initialization
- loops
 

###### Copyright © 2022 by Jeff Yates

All rights reserved. No part of this publication may be reproduced, distributed, or transmitted in any form or by any means, including photocopying, recording, or other electronic or mechanical methods, without the prior written permission of the publisher, except in the case of brief quotations embodied in critical reviews and certain other noncommercial uses permitted by copyright law.

 