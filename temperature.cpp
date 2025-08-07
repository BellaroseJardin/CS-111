/************************************************************************************************************************************
Bellarose Jardin
CS 111
Assignemnt 2 - temperature.cpp
2-10-2025
 This program will ask for a Celsius temperature (Requirement: use int for an input), convert it to the Fahrenheit temperature and round it to the nearest integer
***********************************************************************************************************************************/
#include <iostream>
using namespace std;

int main ()
{

  // declare varaiables

  int celsius; //for celsius
  double fahr; // double used here inorder to get the correct value BEFORE rounding
 



  // prompt user
  cout << "Enter a temperature in Celsius: " ;
  cin >> celsius;
  cout << endl;

  //calcuate
  fahr = (double) celsius * 9/5 + 32; // using the formula given, casts to double to get the correct rounded value 
  fahr = (int) (fahr + 0.5); // rounds to nearest int


  //output
  cout << celsius << " C = " << fahr << " F " << endl ; //outputs in desried format
  cout << endl; // blank line
  











  return 0;
}
