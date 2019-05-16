/***********************************************************************
* Program:
*    Project 04, Monthly Budget
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
*    Actual:     4.30 hrs
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

/******************************************************************
 * This function will compute the tax for the income provided by
 * the user and return the amount to the main function.
 * **************************************************************/
double computeTax(double income)
{
   double yearlyIncome = income * 12.0;
   double yearlyTax;
   double monthlyTax;

   if (yearlyIncome <= 15100.00)
   {
      yearlyTax = yearlyIncome * 0.10;
   } 
   else if ( yearlyIncome <= 61300.00)
   {    
      yearlyTax = 1510.00 + (0.15 * (yearlyIncome - 15100.00));
   }  
   else if (yearlyIncome <= 123700.00)
   {    
      yearlyTax = 8440.00 + (0.25 * (yearlyIncome - 61300.00));
   }  
   else if (yearlyIncome <= 188450.00)
   {    
      yearlyTax = 24040.00 + (0.28 * (yearlyIncome - 123700.00));
   }  
   else if (yearlyIncome <= 336550.00)
   {    
      yearlyTax = 42170.00 + (0.33 * (yearlyIncome - 188450.00));
   }  
   else if (yearlyIncome >= 336550.00)
   {   
      yearlyTax = 91043.00 + (0.35 * (yearlyIncome - 336550.00));
   }
   monthlyTax = yearlyTax / 12.0;
   return monthlyTax;
}

/***********************************************************************
 * Display function will print the information provided by each input and print
 * the table with the information entered by the user. Will not return
 * anything to main.
 * *******************************************************************/
void display(double income1,
             double livExp1,
             double actLivExp1,
             double actTax1,
             double actTithe1,
             double actOther1)
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
   double diFF = income - actLivExp - actTax - actTithe - actOther; 
   double Tax = computeTax(income);
   double mOther = income - (mThithe + livExp + Tax);

   //the code below will display the table with the amounts in it
   cout << endl;
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
   cout << "\tTaxes" << "           " << "$" << setw(11) << Tax;
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

/*******************************************************************
 * Main will call the other functions 
 * ****************************************************************/
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
















