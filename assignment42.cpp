/***********************************************************************
* Program:
*    Assignment 42, String Class
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
#include <string>
using namespace std;

/********************************************************************
 *  * GENERATE SONG                                                                
 *   * This function will generate one long string that constitutes the             
 *    * complete song "Dem Bones."  Note that the list of bones is provided          
 *     * by the parameter list                                                        
 *      ********************************************************************/
string generateSong(string list[], int num)
{
   string output;

   // your code goes here
   for (int i = 0; i < num - 1; i++)
   {
      output += list[i] + " bone connected to the " +  list[i + 1] + " bone\n";
   }
         
  return output;
}
        
/**********************************************************************         
* MAIN                                                                         
* In this program, MAIN is a driver program.  It will feed to generateSong()   
* the list of bones and get back the complete song as a string.  MAIN will     
* then display the song                                                        
***********************************************************************/
int main()
{
   string list[9] =
   {
     "toe",
     "foot",
     "leg",
     "knee",
     "hip",
     "back",
     "neck",
     "jaw",
     "head"
    };

// generate the song                                                         
    string song = generateSong(list, 9);
   // display the results                                                       
    cout << song;
    return 0;
}
