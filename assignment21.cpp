/***********************************************************************
* Program:
*    Assignment 21, Debbuging
*    Brother Cook, CS124
* Author:
*    Leonardo Santos
* Summary: 
*    This program will create stub functions for all the functions in
*    Sue's program.
*
*    Estimated:  01.0 hrs   
*    Actual:     01.30 hrs
*      The most difficult part was getting the program to compile using 
*      all stub functions.
************************************************************************/

#include <iostream>
using namespace std;

double getPeriodicCost();
double getUsageCost();
double promptDevalue();
double promptMileage();
double promptGas();
double promptRepairs();
double promptTires();
double promptInsurance();
double promptParking();
void display();

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   getPeriodicCost();
   getUsageCost();
   display();

   return 0;
}

double getPeriodicCost()
{
   double devalue = promptDevalue();
   double insurance = promptInsurance();
   double parking = promptParking();

   return 0.00;
}

double promptDevalue()
{
   return 0.00;
}

double promptInsurance()
{
   return 0.00;
}

double promptParking()
{
   return 0.00;
}

double getUsageCost()
{
   double mileage = promptMileage();
   double gas = promptGas();
   double repairs = promptRepairs();
   double tires = promptTires();

   return 0.00;
}


double promptMileage()
{
   return 0.00;
}

double promptGas()
{
   return 0.00;
}

double promptRepairs()
{
   return 0.00;
}

double promptTires()
{
   return 0.00;
}

void display()
{
   cout << "Success\n";
}

