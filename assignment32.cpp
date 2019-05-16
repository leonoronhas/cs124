/***********************************************************************
* Program:
*    Assignment 32, Strings
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
using namespace std;

#define TEXTSIZE 256

int countLetters(char letter, char text[])
{
   int count = 0;

   for (int i = 0; i < TEXTSIZE ; i++)
   {
      if (letter == text[i])
         count++;   
   }

   return count;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   char letter;
   char text[TEXTSIZE];

   cout << "Enter a letter: ";
   cin >> letter;
   cin.ignore();
   
   //cout <<

   cout << "Enter text: ";
   cin.getline(text, TEXTSIZE);
   
   int count = countLetters(letter, text);

   cout << "Number of '" << letter << "'s: " <<  count << endl;

   return 0;
}










