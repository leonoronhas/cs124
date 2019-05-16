/***********************************************************************
* Program:
*    Assignment 13, Temperature converter
*    Brother Cook, CS124
* Author:
*    Leonardo Santos
* Summary: 
*    This program will convert Fahrenheit to Celcius. This program will
*    prompt the user for the Fahrenheit number and convert it to Celsius
*    The equation is: c = 5/9 (f -32).
*
*    Estimated:  0.30 hrs   
*    Actual:     1.0 hrs
*      The most difficult part was figuring it out why all my answers
*      were returning with a .(period), the issue was that I had to 
*      remove showpoint from my code and then it worked.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * ftoC will convert the number recived from the user as fahr to Celsius
 ***********************************************************************/
float ftoC(float f) 
{
   float celsius;
   celsius = (f - 32) * 5.0 / 9;
   return celsius;
}
/**********************************************************************
 * Main will get the input from the user and calculate the value into
 * Celsius.
 **********************************************************************/
int main()
{ 
  //set the number to no decimals
   cout.setf(ios::fixed);
   cout.precision(0);
  
   float f;
   int result;
   //print the question to the user
   cout << "Please enter Fahrenheit degrees: ";
   cin  >> f;  //recieve input from user
   //print the answer
   cout << "Celsius: "  << (ftoC(f))
        << endl;

   return 0;
}
