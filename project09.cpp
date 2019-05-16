/***********************************************************************
* Program:
*    Project 09, Mad Lib
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
#include <cassert>
using namespace std;

/***********************************************************************
 * This function will display the question for the user to enter the
 * file name 
 * ********************************************************************/
void getFileName(char fileName[])
{
  
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
}

/*****************************************************************
 * This function will ask the questions based on the file the 
 * user chose.
 * **************************************************************/
void askQuestions(char words[][32], int totalWords)
{  
   for (int i = 0; i < totalWords; i++)
   {
      if (words[i][0] == ':')
      {   
         cout << "\t" << (char) toupper (words[i][1]);  
         for (int j = 2; words[i][j] > 0; j++)
         {
            if (words[i][j] == '_')
            {
               cout << words[i][j];   
            }
            else
            {
               cout << words[i][j];
            }      
         }
         cout << ": ";
         cin.getline(words[i], 33);   
      }
    }
  //  cout << endl;   
}

/*********************************************************************
 * This function will read the file and count the words in it.
 * ******************************************************************/
int readFile(char fileName[], char words[][32])
{
   ifstream fin(fileName);

   if (fin.fail())
   {
      return -1;   
   }
   
   int i = 0;
   while (fin >> words[i])
   {
      i++;
   }      
   return i;
}

/**********************************************************************
 * Main will ask the other function and make sure the right values are
 * transfered over to the right functions.
 ***********************************************************************/
int main()
{
   char fileName[256];
   char words [256][32];
   getFileName(fileName);  
   
   int totalWords = readFile(fileName, words);
   
   askQuestions(words, totalWords);


   return 0;
}
