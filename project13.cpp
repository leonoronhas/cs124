/***********************************************************************
* Program:
*    Project 13, Suduko
*    Brother Cook, CS124
* Author:
*    Leonardo Santos
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  01.0 hrs   
*    Actual:     18.30 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <string>
#include <cctype>
#include <stdio.h>
#include <ctype.h>
#include <sstream>

using namespace std;
int main();
void displayBoard(int board[][9]);
void writeFile(int sudokuBoard[][9]);
void displayOptions();
void getFile(int board[][9]);
void getCoordinates(int &r, char &c);
void editSquare(int board[][9],int &r, char &c);
bool computeValues(int &r, char &c,int board[][9],int value);
void displayPossible(int board[][9], int &r, char &c );

/**********************************************************************
* get File is to get the file name and read it.
***********************************************************************/
void getFile(int board[][9])
{
   char filename[256];
   ifstream fin;
   cout << "Where is your board located? ";
   cin  >> filename;
   fin.open(filename);
   if (fin.fail())
   {
      cout << "Input file opening failed.\n";
      return;
   }
   for (int c = 0; c < 9; c++)
   {
      for (int r = 0; r < 9; r++)
      {
         fin >> board[r][c];
      }
   }
   fin.close();
   return;
}

/**********************************************************************
* display Option is to display Option for the game.
**********************************************************************/
void displayOptions()
{
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n"
        << "\n";
}

/**********************************************************************
 * display Board is to display the game board.
 *********************************************************************/
void displayBoard(int board[][9])
{
   cout << "   A B C D E F G H I\n";
   for (int r = 0; r < 9; r++)
   {
      cout << r + 1 << "  ";
      for (int c = 0; c < 9; c++)
      {
         if (board[c][r] == 0)
            cout << " ";
         else
            cout << board[c][r];
         if (c == 2 || c == 5)
         {
            cout << "|";
         }
         else
            if ( c != 8)
            {
               cout << " ";
            }
         if (c == 8)
         {
            cout << endl;
         }
      }
      if (r == 2 || r == 5)
         cout << "   -----+-----+-----\n";
   }
   cout << endl;
   return;
}

/*************************************************************************
* Interact is to get the user input according to the option.
************************************************************************/
void interact(int board[][9], char &input)
{
   int r = 0;
   char c = '\0';
   do
   {
      cout << "> ";
      cin >> input;
      switch (input)
      {
         case '?':
            displayOptions();
            cout << endl;
            break;
         case 'd':
            displayBoard(board);
            break;
         case 'D':
            displayBoard(board);
            break;
         case 'e':
            getCoordinates(r, c);
            editSquare(board, r, c);
            break;
         case 'E':
            getCoordinates(r, c);
            editSquare(board,r,c);
            break;
         case 's':
            getCoordinates(r, c);
            displayPossible(board, r, c);
            break;
         case 'S':
            getCoordinates(r, c);
            displayPossible(board, r, c);
            break;
      }
   }
   while (input != 'q' && input != 'Q');
}

/**********************************************************************
* write File is to write the board to a new file.
**********************************************************************/
void writeFile(int sudokuBoard[][9])
{
   ofstream fout;
   char destinationFile[256];
   cout << "What file would you like to write your board to: ";
   cin  >> destinationFile;
   fout.open(destinationFile);
   if (fout.fail())
   {
      cout << "Output file opening failed.\n";
      return;
   }
   else
      cout << "Board written successfully\n";
   for (int col = 0; col < 9; col++)
   {
      for (int row = 0; row < 9; row++)
      {
         fout << sudokuBoard[row][col];
         if (row != 8)
         {
            fout << " ";
         }
         if (row == 8)
         {
            fout << endl;
         }
      }
   }
   fout.close();
}

/**********************************************************************
* get Coordinates is to get user input.
**********************************************************************/
void getCoordinates(int &r, char &c)
{
   cout << "What are the coordinates of the square: ";
   cin  >> c >> r;
   return;
}

/**********************************************************************
* edit Square is to edit a square in the board.
**********************************************************************/
void editSquare(int board[][9],int &r, char &c)
{
   int value = 0;
   c = toupper(c);
   if (board[c - 65][r - 1] != 0)
   {
      cout << "ERROR: Square \'" << c << r << "\' is filled\n";
      cout << "\n";
      return;
   }
   else
   {
      cout << "What is the value at \'" << c << r << "\': ";
      cin  >> value;
      if (computeValues(r, c, board, value) == false)
      {
         cout << "ERROR: Value '" << value << "' in square '"
              << c << r << "' is invalid\n\n";
         return;
      }
      cout << "\n";
      board[c - 65][r - 1] = value;
   }
}

/**********************************************************************
* display Possible is to show the possible solution for the game.
*********************************************************************/
void displayPossible(int board[][9], int &r, char &c )
{
   c = toupper(c);
   bool first = true;
   cout << "The possible values for '" << c << r << "' are: ";
               
                    
   for (int i = 1; i <= 9; i++)
   {
      if (computeValues(r,c,board,i) == true)
      {
         if (!first)
         {
            cout << ", ";
         }
         cout << i;
         first = false;
      }
   }
   cout << endl << endl;
}

/**********************************************************************
* compute Possible is to compute the possible value for the displayPossible.
*********************************************************************/
bool computeValues(int &r, char &c,int board[][9],int value)
{
   bool isValid = true;
   if (value < 1 || value > 9)
   {
      isValid = false;
      return isValid;
   }
   
   for (int k = 0; k < 9; k++)
   {
      if (board[k][r - 1] == value)
         isValid = false;
   }
   
   for (int k = 0; k < 9; k++)
   {
      if (board[c - 65][k] == value)
         isValid = false;
   }
   
   for (int iRow = 0; iRow <= 2; iRow++)
   {
      for (int iCol = 0; iCol <= 2; iCol++)
      {
         if (board[(c - 65) / 3 * 3 + iRow][(r - 1) / 3 * 3 + iCol] == value)
            isValid = false;
      }
   }
   return isValid;
}

/**********************************************************************
* main function is to dedicate the variable to other functions
********************************************************************/
int main()
{
   int board[9][9];
   char input = '\0';
   getFile(board);
   displayOptions();
   displayBoard(board);
   interact(board, input);
   writeFile(board);
   return 0;
}
