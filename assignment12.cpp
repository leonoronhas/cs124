/***********************************************************************
* Program:
*    Assignment 12, Monthly Budget
*    Brother Cook, CS124
* Author:
*    Leonardo Santos
* Summary: 
*    This program will ask the user for his or her monthly income amount,
*    then display the amount.
*
*    Estimated:  0.30 hrs   
*    Actual:     0.40 hrs
*     The most difficult part was figuring it out why the setw() was
*     not working.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Main will ask the user to input his/her monthly income and display
 * the result.
 ***********************************************************************/
int main()
{
   //format the output for money
   cout.setf(ios::fixed);     //no scientific notation
   cout.setf(ios::showpoint); //always show the decimal point
   cout.precision(2);         //money is formatted to two decimals

   float income;
   // print the monthly income with the value in it.
   cout << "\tYour monthly income: ";
   cin >> income;

   cout << "Your income is: $"
        << setw(9) << income
        << endl;

   return 0;
}





