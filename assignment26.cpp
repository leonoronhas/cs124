/***********************************************************************
* Program:
*    Assignment 26, Files
*    Brother Cook, CS124
* Author:
*    Leonardo Santos
* Summary: 
*    This program will read 10 grades from a file and display the average.
*    The function will include getFileName(), displayAverage() and 
*    readFile().
*
*    Estimated:  01.0 hrs   
*    Actual:     01.30 hrs
*      The most difficult part was getting was reading the file after
*      the user is done writing in it.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * This function will get the filename from the user
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName; 
}

float readFile(char fileName[])
{  
   float failReturn = -1;

   //declare the output stream
   ifstream fin(fileName);
   if (fin.fail())
      return -1;

   //read the data
   int grade;
   
   float sum = 0;
   float count = 0;
   
   while (fin >> grade)
   {
      sum += grade;
      count++;      
   }
    
   //close the stream
   fin.close();
   if (count < 10 || count > 10)
   {
      return failReturn;   
   }   
   else
   {
      return sum / count;   
   }
}

void display(float average, char fileName[])
{
   if (average < 0)
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;   
   }
   else
   {
      cout << "Average Grade: " << average << "%" << endl;   
   }   
}

int main()
{
   cout.setf(ios::fixed);
   cout.precision(0);

   char fileName[256];
   getFileName(fileName);
   double average = readFile(fileName);
  
   display(average, fileName);   

   return 0;
}
