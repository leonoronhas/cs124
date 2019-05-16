/***********************************************************************
* Program:
*    Assignment 11, Budget
*    Brother Cook, CS124
* Author:
*    Leonardo Santos
* Summary: 
*    Write a program that will display a budget in a sort of table.
*
*    Estimated:  1.0 hrs   
*    Actual:     2.0 hrs
*      The most difficult part was getting the spacing correct.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Main will display a budget in a table with pre-set numbers. The money
 * will have two decimals.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.precision(2);         //set money to two decimals
   int width = 9;
   
   //print table with values
   cout << "\tItem           " << "Projected\n" 
        << "\t=============  " << "==========\n" 
        << "\tIncome         " << "$" << setw(width) << 1000.00 << endl;
   cout << "\tTaxes          " << "$" << setw(width) << 100.00 << endl;
   cout << "\tTithing        " << "$" << setw(width) << 100.00 << endl; 
   cout << "\tLiving         " << "$" << setw(width) << 650.00 << endl;
   cout << "\tOther          " << "$" << setw(width) << 90.00 << endl;
   cout << "\t=============  " << "==========\n"
        << "\tDelta          " << "$" << setw(width) << 60.0 << endl;
   
   return 0;
}
