/***********************************************************************
* Program:
*    Assignment 25, Calendar
*    Brother Cook, CS124
* Author:
*    Leonardo Santos
* Summary: 
*    This program will display a function on the screen according to the
*    information the user will enter. The display function will print the
*    calendar on the screen.
*
*    Estimated:  1.0 hrs   
*    Actual:     2.0 hrs
*      The most difficult part was getting the rows and columns of the 
*      calendar aligned with the offset.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * The function display, will display the table according to the offset.
 ***********************************************************************/
void displayTable(int numbDays1, int offset1)
{
   int blanks = offset1 + 1;           
   if (offset1 == 6)                    
   {                                   
      blanks = 0;
   }
   
   //display the names of the days of the week
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
   
   cout << setw(blanks * 4) << "";   
   
   int days = 1;  //each month starts at day 1
   int dayWeek = blanks;

   while (days <= numbDays1)
   {
      cout << setw(4) <<  days;

      //create the rows / up to 7 numbers
      if ((days + blanks) % 7 == 0)
      {
         if (days != numbDays1)
         {
            if (dayWeek != 5)
            {
               cout <<  endl;
               dayWeek = 5;
            }
         }
      }
      days++;
      dayWeek++;
   }
   cout << endl; 
}

/**********************************************************************
 * Main will prompt and receive the inputs from the user and send the 
 * information to the display function to show the calendar according 
 * to the offset.
 ***********************************************************************/
int main()
{
   int numDays;
   int offset;
   
   //prompt the user to ender the number of days
   cout << "Number of days: ";
   cin >> numDays;

   //prompt the user to enter the offset
   cout << "Offset: ";
   cin >> offset;

   //send the values in both var. to the display function 
   displayTable(numDays, offset);   


   return 0;
}

