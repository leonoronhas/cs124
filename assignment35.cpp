/***********************************************************************
* Program:
*    Assignment 35, Conditionals
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

#include <iostream>
using namespace std;

char computeGradeSign(int gradeNumber)
{
    char sign;
    switch (gradeNumber)
    {
      case 65:
      case 64:
      case 63:
      case 62:
      case 61:
      case 60:
      case 75:
      case 74:
      case 73:
      case 72:
      case 71:
      case 70:
      case 85:
      case 84:
      case 82:
      case 81:
      case 80:
      case 95:
      case 94:
      case 93:
      case 92:
      case 91:
      case 90:
         sign = '-';
         break;   
      case 66:
      case 67:
      case 68:
      case 69:
      case 76:
      case 77:
      case 78:
      case 79:
      case 87:
      case 88:
      case 89:
         sign = '+';
         break;
      default:
         sign = '\n';
      }
   return sign;
}

char computeLetterGrade(int grade)
{
   char letter;

   switch (grade / 10)
   {
      case 10:
      case 9:
         letter = 'A';
         break;   
      case 8:
         letter = 'B';
         break;
      case 7:
         letter = 'C';
         break;
      case 6:
         letter = 'D';
         break;
      default:
         letter = 'F';
   }   
   return letter;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   int gradeNumber;

   cout << "Enter number grade: ";
   cin >> gradeNumber;

   char numbLetter = computeLetterGrade(gradeNumber);
   char sign = computeGradeSign(gradeNumber);

   cout << gradeNumber << "% is " << numbLetter << sign;
   if (sign != '\n')
   {
      cout << endl;   
   }

   return 0;
}
