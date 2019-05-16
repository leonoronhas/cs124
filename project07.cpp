/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Cook, CS124
* Author:
*    Leonardo Santos
* Summary: 
*    This program will display a calendar for any month of any year from
*    1753 forward. The program will prompt the user for the numeric month
*    and year to be displayed. The program will also start with the first
*    day of the month and year being January 1, 1753. This program will 
*    then take into account leap years.
*
*    Estimated:  4.0 hrs   
*    Actual:     8.0 hrs
*      The most difficult part was getting the all the functions to send
*      and return the correct values to display the calendar correctly.
************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
bool isLeapYear(int year);  //if I want to use a function outside main

/**********************************************************************
 * This function will prompt the user for the month and run it until
 * the user enters a valid month (1-12).
 * *******************************************************************/
int getMonth()
{
   int month;
   //Run loop until the user enters a valid month
   cout << "Enter a month number: ";
   cin >> month;
   
   while (month > 12 || month < 1)
   {
      cout << "Month must be between 1 and 12." << endl;
      cout << "Enter a month number: ";
      cin >> month;
   }
   return month;
}

/**********************************************************************
 * This function will prompt the user for the year and run the loop
 * until the user enters a year from 1753 forward.
 * *******************************************************************/
int getYear()
{
   int year;
   //Run loop until the user enters a valid year
   cout << "Enter year: ";
   cin >> year;
   
   while (year < 1753)
   {
      cout << "Year must be 1753 or later." << endl;
      cout << "Enter year: ";
      cin >> year;
   }
   return year;
}

/**********************************************************************
 * The function will check to see if the year is a leap year and return
 * true or false.
 ***********************************************************************/
bool isLeapYear(int year)
{
   bool leapYear = false;
   if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
   {
      leapYear = true;
   }
   return leapYear;
} 

/**********************************************************************
 * The function will calculate the amount of days in each month and will
 * also calculate when the year is a leap year.
 ***********************************************************************/
int numbDaysMonth(int year, int month)
{
   bool leapYear = isLeapYear(year);
   int value = 31;   

   switch (month)
   {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
         value = 31;
         break;
      case 2:
         if (leapYear)
         {
            value = 29;
         }
         else
         {
            value = 28;
         }
         break;
      default: 
         value = 30;
   }  
   return value;
} 

/**********************************************************************
 * The function will receive the month number and associate a name to
 * that number.
 ***********************************************************************/
string getMonthName(int month)
{
   string monthName;

   switch (month)
   {
      case 1:
         monthName = "January";
         break;
      case 2:
         monthName = "February";
         break;
      case 3:
         monthName = "March";
         break;
      case 4:
         monthName = "April";
         break;
      case 5:
         monthName = "May";
         break;
      case 6:
         monthName = "June";
         break;
      case 7:
         monthName = "July";
         break;
      case 8:
         monthName = "August";
         break;
      case 9:
         monthName = "September";
         break;
      case 10:
         monthName = "October";
         break;
      case 11:
         monthName = "November";
         break;
      case 12:
         monthName = "December";
         break;
   }
   return monthName;
}
 
/*********************************************************************
 * This function will calculate when the next month will start
 *******************************************************************/
int getFirstDayWeek(int year, int month)
{
   int days = 1;             //each month starts at day 1
   int dayWeek = 0;
   int daysMonth = 0;
   int initYear = 1753;
   int initMonth = 1;
   int finalYear = year;
   int limitMonth = 12;

   while (initYear <= finalYear)
   {
      initMonth = 1;
      if (initYear == finalYear)
      {
         limitMonth = month;   
      }   
      while (initMonth <= limitMonth)  
      {
         days = 1;
         daysMonth = numbDaysMonth(initYear, initMonth);
         while (days <= daysMonth)
         {
            dayWeek++;
            //create the rows / up to 7 numbers
            if (dayWeek == 6)
            {
               dayWeek = (-1); 
            }
            days++;
         }
         initMonth++;
      }
      initYear++;
   }
   if (dayWeek == -1)
   {
      dayWeek = 0;
   }
   else
   {
      dayWeek++;   
   }   
   return dayWeek;
}

/**********************************************************************
 * The function display, will display the table according to the month 
 * and year chosen by the user.
 ***********************************************************************/
void displayTable(int year, int month, string monthName)
{
   int firstDay = getFirstDayWeek(year, month - 1);
   
   int blanks = firstDay;
   if (year == 1753 && month == 1)
   {
      blanks = 1;   
   }
      
   int daysMonth = numbDaysMonth(year, month);

   cout << endl << monthName << ", " << year << endl; 
   //display the names of the days of the week
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
   
   cout << setw(blanks * 4) << "";   
   
   int days = 1;  
   int dayWeek = firstDay;

   while (days <= daysMonth )
   {
      cout << setw(4) <<  days;
   
      //create the rows / up to 7 numbers
      if ((days + blanks) % 7 == 0)
      {
         if (days != daysMonth)
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
 * Main will only call the functions and send the values received from
 * other functions.
 ***********************************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();
   string monthName = getMonthName(month);

   displayTable(year, month, monthName);
   
   return 0;
}


