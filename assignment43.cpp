/***********************************************************************
* Program:
*    Assignment 43, If Statements
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
#include <cstdlib> 
#include <iostream>
#include <string>
using namespace std;

float convertFeetToMeters(float feet);

/**********************************************************************
 *  * main
 *   * this function will iterate through all of the command line values
 *    * given by the user. It will then pass the values to the convert feet
 *     * to meters function and then print the value returned;
 *      ***********************************************************************/
int main(int argc, char *argv[])
{
   cout.setf(ios::showpoint);
   cout.setf(ios::fixed);
   cout.precision(1);
               
  // run through every arg value and convert it to meeters;
   for (int i = 1; i < argc; i++)
   {
   // convert the value to a float and store it
      float feet = atof(argv[i]);
      float meters = convertFeetToMeters(feet);
                               
      cout << feet << " feet is " << meters << " meters" << endl;
   }
   return 0;
}
/**********************************************************************
* convert feet to meters
* Will convert and return the value of feet to meters.
***********************************************************************/
float convertFeetToMeters(float feet)
{
   return feet * 0.3048;
}
