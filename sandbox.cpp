/***********************************************************************
* Program:
*    Assignment 16, If Statements
*    Brother Cook,CS124
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
void getFileName(char word[])
{
   cin >> word;

}


int main()
{
   char word [50];
   
   cout >> word >> endl;
   for (int i=0; i<50; i+=1)
   {
      cout << i << " " << word[i] << (int)word[i] << endl;
   }
      cout << word <<endl;
   return 0;
}
