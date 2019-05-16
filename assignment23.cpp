/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax
*    Brother Cook, CS124
* Author:
*    Leonardo Santos
* Summary: 
*    This program will add all numbers multiples by a number the user
*    will provide that are less than 100. Then it will calculate the
*    sum of all the results and display the result.
*
*    Estimated:  01.0 hrs   
*    Actual:     01.30 hrs
*      Getting the loop to calculate the correct amount.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Main will ask the user for a number(int) and compute the sum of all
 * numbers up to 100.
 ***********************************************************************/
int main()
{
   int input;
   int result = 0;
   
  
   cout << "What multiples are we adding? ";
   cin >> input;
   
   int i = input;
   while(input < 100)
   {
       result += input; //result = result + input
        
       input += i;      //input = input + i 
   }
  
   cout << "The sum of multiples of " << i << " less than 100 are: " 
        << result << endl;

   return 0;
}
