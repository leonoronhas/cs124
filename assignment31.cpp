/***********************************************************************
* Program:
*    Assignment 31, Array Design
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

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void getGrades(int listGrades[], int numGrade)
{
  
   for (int iGrades = 0; iGrades < numGrade; iGrades++)
   {
      cout << "Grade " << iGrades + 1 << ": ";
      cin >> listGrades[iGrades];
   }

}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int averageGrades(int listGrades[], int numGrade)
{
   int sum = 0;
   int count = 0;
   float average;

   for (int i = 0; i < numGrade; i++)
   {
      if (listGrades[i] != -1)
      { 
         sum += listGrades[i];
         count++; 
      }
           
   }
   
   //calculate the average
   if (count > 0)
   {   
      average = sum / count;
   }
   else
   {
      average = 0;
   }      
   return average;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   int numGrade = 10; 
   int listGrades[10];                 

   getGrades(listGrades, numGrade);
   int average = averageGrades(listGrades, numGrade);
   
   if (average > 0)
   {
      cout << "Average Grade: " << average << "%\n";
   }
   else
   {
     cout << "Average Grade: " << "---" << "%\n";
   }

   return 0;
}
