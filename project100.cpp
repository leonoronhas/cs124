/***********************************************************************
* Program:
*    Project 10, Mad Lib
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
#include <string>
#include <cctype>
using namespace std;

/***********************************************************************
 * This function will display the question for the user to enter the
 * file name 
 * ********************************************************************/
void getFileName(char *fileName)
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin.getline(fileName, 256);
}

/****************************************************************
 * This function will ask the questions based on the file the 
 * user chose.
 * **************************************************************/
void askQuestions(char words[][256], int totalWords)
{  
   for (int i = 0; i < totalWords; i++)
   {
      if (words[i][0] == '<')
      {   
         if (isalpha(words[i][1]))
         {   
            cout << "\t";  
            for (int a = 1; words[i][a] != '>'; a++)
            {
               if (a == 1)
               {
                  cout << (char) toupper (words[i][1]);   
               }
               else if (words[i][a] == '_')
               {
                  cout << ' ';
               }
               else
               {
                  cout << words[i][a];   
               }
            }
            cout  << ": ";
            
            cin.getline(words[i], 256);   
         }
      }
   }
}

void displayStory(char words[][256], int totalWords)
{ 
  // cout << endl;
   for (int i = 0; i < totalWords; i++)
   {
      if (words[i][0] == '<')
      {
         switch (words[i][1])
         {
            case '#':
               cout << '\n';
               words[i][0] = '\n';
               words[i][0] = '\0';
               break;
            case '{':
               cout << '"';
               break;
            case '}':
               cout << '"';
               cout << ' ';
               break;
            case '[':
               cout << '\'';
               break;
            case ']':
               cout << '\'';
               cout << ' ';
               break;
            case '.':
               cout << endl;
               break;
            case '?':
               cout << endl;
               break;
            case '"':
               break;
            case '!':
               
               words[i][1] = '\0';
               break;   
         }
      }
      else if (words[i - 1][0] == '<' || ispunct(words[i + 1][0]))
      {
         cout << words[i];   
         switch (words[i + 1][1])
         {
            case '{':
               break;
            case '[':
               cout << ' ';
               break;
            case '#':
               break;
            case '}':
               break;
            case ']':
               break;
            case '.':
               break;
            case '?':
               break;
            case '!':
               cout << endl;
               break;   
         }
      }
      else
      {
         if (words[i + 1][1] == '#')
         {
            cout << words[i];   
         }   
         cout << words[i] << " ";
      } 
   }
}

/********************************************************************
 * This function will read the file and count the words in it.
 * ******************************************************************/
int readFile(char *fileName, char words[][256])
{
   ifstream fin(fileName);

   if (fin.fail())
   {
      return -1;   
   }
   
   int i = 0;
   while (i <= 256 && !fin.eof())
   {
      fin >> words[i++];
   }      
   fin.close();
   return i;
}

/**********************************************************************
 * Main will ask the other function and make sure the right values are
 * transfered over to the right functions.
 ***********************************************************************/
int main()
{
   char fileName[256];
   char words [256][256];
   char repeat;
   int totalWords = 0;

   do
   {
      getFileName(fileName);  
      int totalWords = readFile(fileName, words);   
      askQuestions(words, totalWords);
      displayStory(words, totalWords);
      
      cout << endl;
      cout << "Do you want to play again (y/n)? ";
      cin >> repeat;
      cin.ignore();
      
   }   
   while (repeat == 'y');
   cout << "Thank you for playing. \n";
        
   return 0;
}




























