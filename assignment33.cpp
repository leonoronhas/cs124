/***********************************************************************
* Program:
*    Assignment 33, Pointers
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

float getSamBalance();
float getSueBalance();
void date(float *pAccount);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   float sam = getSamBalance();
   float sue = getSueBalance();
   float* richPersonAccount;

   //assign the pointer to the person with the largest balance
   if (sam > sue)
   {
      richPersonAccount = &sam;
   }
   else
      richPersonAccount = &sue;
   
   //find the cost and the new balance
   date(richPersonAccount);

   //print the balance after deductions
   cout << "Sam's balance: $" << sam << endl;
   cout << "Sue's balance: $" << sue << endl;

   return 0;
}

void date(float* pAccount)
{
   cout << "Cost of the date:" << endl;
   
   float dinner, movie, iceCream;
   
   //get individual costs
   cout << "\tDinner:    ";
   cin >> dinner;
   
   cout << "\tMovie:     ";
   cin >> movie;
   
   cout << "\tIce cream: ";
   cin >> iceCream;
   
   //get the sum of the costs
   float total = dinner + movie + iceCream;
   
   //subtract it from balance
   *pAccount -= total;   
}

float getSamBalance()
{
   float balance;
   cout << "What is Sam's balance? ";
   cin >> balance;
   return balance;
}

float getSueBalance()
{
   float balance;
   cout << "What is Sue's balance? ";
   cin >> balance;
   return balance;   
}
