/***********************************************************************
* Program:
*    Assignment 40, Tik-tak-toe board
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
*    Actual:     01.30 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

#define ROWS 3
#define COLS 3

void getFileName(char fileName[]);
void readFile(char filename[], char game[][COLS]);
void displayGame(char game[][COLS]);
void getSaveFileName(char fileName[]);
void saveGame(char fileName[], char game[][COLS]);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   char fileName[256];
   char game[ROWS][COLS];

   getFileName(fileName);
   readFile(fileName, game);
   displayGame(game);

   getSaveFileName(fileName);
   saveGame(fileName, game);

   return 0;
}

void getFileName(char fileName[])
{
   cout << "Enter source filename: ";
   cin >> fileName;   
}

void readFile(char fileName[], char game[][COLS])
{
   ifstream fin(fileName);
   
   if (fin.fail())
   {
      return;   
   }   
   
   for (int r = 0; r < 3; r++)
   {
      for (int c = 0; c < 3; c++)
      {
         fin >> game[r][c];   
      }   
   }
   fin.close();
}

void getSaveFileName(char fileName[])
{
   cout << "Enter destination filename: ";
   cin >> fileName;
   cout << "File written\n";   
}

void saveGame(char fileName[], char game[][COLS])
{
   ofstream fout(fileName);
   
   if (fout.fail())
   {
      return;   
   }
   
   for (int r = 0; r < 3; r++)
   {
      for (int c = 0; c < 3; c++)
      {
         fout << game[r][c];
         if (c < COLS - 1)
            fout << " ";   
      }
      if (r < ROWS - 1)
         fout << endl;      
   }   
   fout.close();
}

void displayGame(char game[][COLS])
{
   for (int r = 0; r < 3; r++)
   {
      for (int c = 0; c < 3; c++) 
      {
         cout << " " << (game[r][c] == '.'?' ' : game[r][c]) << " ";
         if (c < COLS - 1)
            cout << "|";   
      }     
      cout << endl;
      if (r < ROWS - 1)
         cout << "---+---+---" << endl;
   }
   
}





