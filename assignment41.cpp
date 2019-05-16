/***********************************************************************
* Program:
*    Assignment 41, Allocating Memory
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

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int getLength();

int main()
{
   int length = getLength();

   char* text = new(nothrow) char[length];

   if (text == NULL)
   {
      cout << "Allocation failure!" << endl;
   }
   else 
   {
      cout << "Enter Text: ";
      cin.ignore();
      cin.getline(text, length + 1);
      cout << "Text: " << text << endl;
      delete [] text;
   }
}

int getLength()
{ 
   int length;
   cout << "Number of characters: ";
   cin >> length;
   return length;
}

