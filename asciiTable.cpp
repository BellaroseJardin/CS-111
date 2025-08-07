/***************************************************************************
Bellarose Jardin
CS 111
Professor Slott
AsciiTable.cpp
3/6/25
Write a program that uses a “for” loop to display the characters for the ASCII values 35 through 126. Display 14 characters on each line.
****************************************************************************/
#include <iostream>
using namespace std;
int main ()
{
  //declare variables
  int count= 0;
  
  //for loop
  for (int i = 35; i <= 126; i++) // i is each char set as 35 as an int to start then  up to 126, incremnet by 1
    {
      cout << char (i) << " " ; // type casting and a space after each char
      count ++; //incremnt count of char by row by 1
      if (count >= 14) // if the count (characters) reaches 14 then end the line
	{
	  cout << endl;
	  count = 0; //reset count to start over
	}
    }
  
  cout << endl; // endl OUT of loop once all is done



  return 0;
}
