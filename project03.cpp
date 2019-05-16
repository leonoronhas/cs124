/***********************************************************************
* Program:
*    Project 03, Monthly Budget
*    Brother Cook, CS124
* Author:
*    Leonardo Santos
* Summary: 
*    This program will ask the user for their budget income and expenditures,
*    then for how much they actually made and spent. The program will then
*    display a report of whether the user is on target to meet their
*    financial goals.
*
*    Estimated:  1.0 hrs   
*    Actual:     3.0 hrs
*      Putting everything together was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * This function will get the monthly income amount from the user.
 ***********************************************************************/
double getIncome()
{
   double income;
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";
 
   cout << "\tYour monthly income: ";
   cin >> income;
   
   return income;
}

/***************************************************************
 * this function will ask the user for the actual other amount
 * ***********************************************************/
double getLivExp()
{
   double exp;
   cout << "\tYour budgeted living expenses: ";
   cin >> exp;
  
   return exp;
}

/***************************************************************
 * This function will ask the user for the actual living expenses
 *  amount.
 * ***********************************************************/
double getActLivExp()
{ 
   double aexp;
   cout << "\tYour actual living expenses: ";
   cin >> aexp;
   
   return aexp;
}

/***************************************************************
 * This function will ask the user for the actual Tax amount
 * ***********************************************************/
double getActTax()
{
   double tax;
   cout << "\tYour actual taxes withheld: ";
   cin >> tax;

   return tax;
}

/***************************************************************
 * This function will ask the user for the actual other tithe
 * ***********************************************************/
double getActTithe()
{
   double tithe;
   cout << "\tYour actual tithe offerings: ";
   cin >> tithe;

   return tithe;
}

/***************************************************************
 * This function will ask the user for the actual other amount
 * ***********************************************************/
double getActOther()
{
   double other;
   cout << "\tYour actual other expenses: ";
   cin >> other;

   return other;
}

/*********************************************************************
 * This function will display the table with the correct information.
 * ******************************************************************/
void display(double income1,double livExp1, double actLivExp1, double actTax1,
                  double actTithe1, double actOther1)
{
   cout.setf(ios::fixed);     //no scientific notation
   cout.setf(ios::showpoint); //always show the decimal for real numbers(.)
   cout.precision(2);         //two digits after the decimal
   
   double income = income1;
   double livExp = livExp1;
   double actLivExp = actLivExp1;
   double actTax = actTax1;
   double actTithe = actTithe1;
   double actOther = actOther1;
   double mThithe = income * 0.10;
   double mOther = income - (mThithe + livExp);
   double diFF = income - actLivExp - actTax - actTithe - actOther;

   cout << "" << endl;
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
   cout << "\tTithing" << "         " << "$" << setw(11) <<  mThithe;
   cout << "    " << "$" <<  setw(11) << actTithe   
        << endl;
   cout << "\tLiving" << "          " << "$" << setw(11) << livExp;
   cout << "    " << "$" <<  setw(11) << actLivExp
        << endl;
   cout << "\tOther" << "           " << "$" << setw(11) << mOther ;
   cout << "    " << "$" <<  setw(11) << actOther
        << endl;
   cout << "\t===============" << " " << "===============" << " " 
        << "==============="
        << endl;                          
   cout << "\tDifference" << "      " << "$" << setw(11) << 0.00;
   cout << "    " << "$" <<  setw(11) << diFF
        << endl;

 
}

/***********************************************************************
 * Main will ask for the input using a function for each input and print
 * the table with the information entered.
 * *******************************************************************/
int main()
{
   double income = getIncome();
   double livExp = getLivExp();
   double actLivExp = getActLivExp();
   double actTax = getActTax();
   double actTithe = getActTithe();
   double actOther = getActOther();
  
   display(income, livExp, actLivExp, actTax, actTithe, actOther);

   return 0;
}
















