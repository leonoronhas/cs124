/***********************************************************************
* Program:
*    Assignment 44, Search Speed
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
#include <fstream>
#include <iomanip>
using namespace std;

int readNumbers(int list[], int max);
float computeAverageLinear(int list[], int num);
float computeAverageBinary(int list[], int num);
int linear(int list[], int num, int search);
int binary(int list[], int num, int search);

/**********************************************************************                 
 * * main reads the list, determines the speed of the searches, and outputs                
 * * the results.                                                                          
 * ***********************************************************************/
int main()
{
   int list[1024];
   const int MAX = sizeof (list) / sizeof (list[0]);
   int num;

   // read the numbers                                                                  
   if (!(num = readNumbers(list, MAX)))
       return 1;
   // determine how long it takes for a linear search                                   
   float averageLinear;
   averageLinear = computeAverageLinear(list, num);
   
   // determine how long it takes for a binary search                                   
   float averageBinary;
   averageBinary = computeAverageBinary(list, num);
   
   // display results                                                                   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   cout << "Linear search: " << setw(10) << averageLinear << endl;
   cout << "Binary search: " << setw(10) << averageBinary << endl;
   return 0;
}

int readNumbers(int list[], int max)
{
   char fileName[256];
   int  num = 0;
                                                                    
   cout << "Enter filename of list: ";
   cin  >> fileName;
  
   ifstream fin(fileName);
      if (fin.fail())
      {
         cout << "Unable to open file " << fileName << endl;
         return 0;
      }
      while (num < max && fin >> list[num])
            num++;
    fin.close();
    return num;
}

float computeAverageLinear(int list[], int num)
{
   float averageLinear = 0.0;
                                                                                                            for (int i = 0; i < num; i++)
   {
       averageLinear += linear(list, num, list[i]);
   }
   averageLinear = averageLinear / num;
                                                                                                            return averageLinear;
                                                                                                         }
                                                                                                         float computeAverageBinary(int list[], int num)
{
   float averageBinary = 0.0;
                                                                                                            for (int i = 0; i < num; i++)
   {
      averageBinary += binary(list, num, list[i]);
   }
   averageBinary = averageBinary / num;                                                            
                                                                                                            return averageBinary;
}
                                                                                                         int linear(int list[], int num, int search)
{
   bool found = false;
   int  compares = 0;  // you will need to compute this                                 
                                                                                                            for (int i = 0; i < num && ! found; i++)
   {
       compares++;
       if (search == list[i])
       {
          found = true;
       }
   }
   return compares;
}
                                                                                                         int binary(int list[], int num, int search)
{
   bool found = false;
   int  compares = 0;  // you will need to compute this                                 
                                                                                                            // set the bounds of the search space, initially the whole list                      
   int iFirst = 0;
   int iLast = num - 1;
   // continue until found or the search size is not zero                               
                                                                                                            while (iLast >= iFirst && !found)
   {
      compares++;
      int iMiddle = (iLast + iFirst) / 2;
                                                                                                            // note that both the == and > count as one comparison                            
     if (list[iMiddle] == search)
         found = true;
     else if (list[iMiddle] > search)
         iLast = iMiddle - 1;
     else
         iFirst = iMiddle + 1;
   }
   return compares;
}
