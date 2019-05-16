/***********************************************************************
* Program:
*    Project 02, Monthly Budget
*    Brother Cook, CS124
* Author:
*    Leonardo Santos
* Summary: 
*    This program will ask the user for their budget income and expenditures,
*    then for how much they actually made and spent. The program will then
*    display a report of whether the user is on target to meet their
*    financial goals.
*
*    Estimated:  3.0 hrs   
*    Actual:     3.0 hrs
*      Putting everything together was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Main will ask the user for their monthly income and display a table
 * with the information provided by the user.
 ***********************************************************************/
int main()
{
   cout.setf(ios::fixed);     //no scientific notation
   cout.setf(ios::showpoint); //always show the decimal for real numbers
   cout.precision(2);         //two digits after the decimal

   float income;
   float livExp;
   float actlivExp;
   float actTax;
   float actTithe;
   float actOther;

   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";
 
   cout << "\tYour monthly income: ";
   cin >> income;
   
   cout << "\tYour budgeted living expenses: ";
   cin >> livExp;
   
   cout << "\tYour actual living expenses: ";
   cin >> actlivExp;
   
   cout << "\tYour actual taxes withheld: ";
   cin >> actTax;

   cout << "\tYour actual tithe offerings: ";
   cin >> actTithe;

   cout << "\tYour actual other expenses: ";
   cin >> actOther;
   cout << endl;

/* After acquiring all user inputs, this next block of program will
 * execute the report in a table with the money aligned.*/

   cout << "The following is a report on your monthly expenses" << endl;
   cout << "\tItem"                      //begin of topics row 
        << "                  " 
        << "Budget" << "          "
        << "Actual" << endl;
   cout << "\t===============" << " " << "===============" << " " 
        << "==============="
        << endl;                           //end of topics row
   
   cout << "\tIncome" << "          " << "$" << setw(11) << income;
   cout << "    " << "$" <<  setw(11) << income  
        << endl;
   cout << "\tTaxes" << "           " << "$" << setw(11) << 0.00;
   cout << "    " << "$" <<  setw(11) << actTax
        << endl;
   cout << "\tTithing" << "         " << "$" << setw(11) << 0.00;
   cout << "    " << "$" <<  setw(11) << actTithe   
        << endl;
   cout << "\tLiving" << "          " << "$" << setw(11) << livExp;
   cout << "    " << "$" <<  setw(11) << actlivExp
        << endl;
   cout << "\tOther" << "           " << "$" << setw(11) << 0.00;
   cout << "    " << "$" <<  setw(11) << actOther
        << endl;
   cout << "\t===============" << " " << "===============" << " " 
        << "==============="
        << endl;                          
   cout << "\tDifference" << "      " << "$" << setw(11) << 0.00;
   cout << "    " << "$" <<  setw(11) << 0.00
        << endl;


   return 0;
}
















