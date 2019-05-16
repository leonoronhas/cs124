/***********************************************************************
* Program:
*    Assignment 16, If Statements
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
*      Getting the if statements to work properly.
************************************************************************/

#include <iostream>
using namespace std;
/**********************************************************************
 * This function will determine which tax bracket a user is in 
 * ******************************************************************/
int computeTax(int income)
{
   int input = income;

   if (input >= 0 && input <= 15100)
   {
        input = 10;
   } 
   if (input >= 15101 && input<= 61300)
   {    
       input = 15;
   }  
   if (input >= 61301 && input <= 123700)
   {    
       input = 25;
   }  
   if (input >= 123701 && input <= 188450)
   {    
       input = 28;
   }  
   if (input >= 188451 && input <= 336550)
   {    
       input = 33;
   }  
   if (input >= 336551)
   {   
       input = 35;
   }
   return input;
}


/**********************************************************************
 * Main will ask the user for input and then run function computeTax
 * to reveive the number that correspond to its bracket.
 ***********************************************************************/
int main()
{
   int income;

   cout << "Income: ";
   cin >> income;
   
   cout << "Your tax bracket is " << computeTax(income) << "%" << endl;

 return 0;
}
