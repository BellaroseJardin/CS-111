/*************************************************************************
Bellarose Jardin
CS 111
Professor slott
Sqrt.cpp
3-23-25
a program that will find the square root of a positive integer number
 ************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;
#include "input.h"

int main()
{
  int num; //number entered by user
  double start; //finds the square root using for the num entered 
  int bottom, top; //bottom and top for the sqrt
  
  cout << "Enter a positive integer number that you want to find the square root for: ";
  
  //ensures that num will only be a positive integer greater than zero
  num  = getInt(1, 9000000, "Enter a positive integer number between 1 and 9000000: ");
  
  //finds bottom and top perfect squares 'num' lies between
  for(int b = 1; b * b <= num; b++) 
    {    
      bottom = b;
      top = b + 1;
    }
  
  if(bottom * bottom == num) //if the square root of num is a perfect square
    cout << bottom << " is the square root of " << num << endl << endl;
  else //if the square root of num is NOT a perfect square
    {
      if((top * top - num)  < (num - bottom * bottom )) //if the square of the top number is closer to 'num' than the square of the bottom
	start = top;
      else //if the square of the bottom number is closer to 'num' than the square of the top
	start = bottom;

      cout << "Start at " << start << endl; //output start point
      
      for (int i = 0; i < 10; i++) //repeats step 3 & 3 10 times
	{ 
	  start = (start + num / start) /2;
	}  
      
      // out put information
      cout << "The square root of " << num << " is " << setprecision(6) << start << endl;
      cout << "The square of the square root is " << num << endl << endl;
    }
  
  return 0;
}
