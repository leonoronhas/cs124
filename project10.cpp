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
*    Actual:     11.30 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void getFileName(char fileName[256]);
void askQuestions(char word[32]);
int readFile(char story[256][32]);
bool playAgain();
void isPunc(char character[32]);
void displayStory(char story[256][32], int length);

/***********************************************************************
 *Will call the necessary functions.
 ***********************************************************************/
int main()
{
   char story[256][32] = {'\0'};
   int length;
   bool play = true;

   while (play) //we need to keep playing
   {
      length = readFile(story);
      displayStory(story, length);
      play = playAgain();
   }
   cout << "Thank you for playing.\n";
}

/**********************************************************************
 * Will prompt the user for the filename.
 * *********************************************************************/
void getFile(char fileName[256])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin  >> fileName;
   cin.ignore(); //we don't want problems with \n's
}

/********************************************************************
 * Will prompt the user according to the prompts in the file.
 ********************************************************************/
void askQuestions(char word[32])
{
   if ((word[0] != ':') || !(isalpha(word[1])))
   {
      return; //if the word is a token, it should not be here!!
   }
   cout << "\t";
   cout << (char)toupper(word[1]); //we need to make it look pretty.

   for (int i = 2; word[i] != '\0'; i++)
   {
      if (word[i] == '_')
         cout << " ";
      else
         cout << (char)tolower(word[i]);
   }

   cout << ": ";
   cin.getline(word, 32);
}

/********************************************************************
*Will copy the stoy to an array.
*******************************************************************/
int readFile(char story[256][32])
{
   int length;
       
   char fileName[256];
   getFile(fileName);

   ifstream fin(fileName);   //opening the file.

   if (fin.fail())
   {
      cout << "Unable to open file : "
           << fileName << endl;
      return -1;
   }

   for (length = 0; fin >> story[length]; length++)
   {
      if (story[length][0] == ':') //copying it to the array
         askQuestions(story[length]);
   }

   fin.close(); //closing the file.
                                                                                               
   return length;
}

/****************************************************************
 *Will replace the special tokens with the corresponding character.
 ****************************************************************/
void isPunc(char word[32])
{   
   switch ((int)word[1])
   {
      case '!':                    //let's replace the tokens
         word[0] = '\n';           //with the corresponding
         word[1] = '\0';           //character
         break;
      case '.':
         word[0] = '.';
         word[1] = '\0';
         break;
      case ',':
         word[0] = ',';
         word[1] = '\0'; 
         break;
   }
}

/*****************************************************************
 *Will display the Story.
 *****************************************************************/
void displayStory(char story[256][32], int length)
{   
   cout << endl;

   cout << story[0];
            
   for (int i = 1; i < length; i++)
   {
      if ((story[i][0] == ':'))
         isPunc(story[i]);
         
         if ((story[i][1] == '<') && (story[i - 1][0] != '\n'))
            cout << " \"";
         else if (story[i][1] == '<')  //all these lines deal with
            cout << "\"";              //spaces: where there should
         else if (story[i][1] == '>')  //be and where there shouldn't
            cout << '"';
         else if ((story[i - 1][0] == '\n') || (story[i][0] == '.')
                   || (story[i][0] == ',') || (story[i][0] == '\n')
                   || (story[i - 1][1] == '<'))
            cout << story[i];
         else
            cout << " " << story[i];
    }
    cout << endl;
}

/****************************************************************
 *Will ask the user if the game will be played again.
 ****************************************************************/
bool playAgain()
{
   char answer;
   bool play;       //we need to run the game in a loop, this
                    //makes sure that happens.
   cout << "Do you want to play again (y/n)? ";
   cin  >> answer;
   
   if ((answer == 'y') || (answer == 'Y'))
      play = true;
   else if ((answer == 'n') || (answer == 'N'))
      play = false;
   
   return play;
}





















