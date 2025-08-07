/************************************************************************************************************************************************

Bellarose Jardin
CS 111
homework: clock.cpp
2-12-2025

The program will ask for a time in 2 integers: hours and minutes. It will tell the angles of the hour and minute hands on the clock
***********************************************************************************************************************************************/

#include <iostream>
using namespace std;

int main ()
{

  //delcare varibales
  int hour; //hour whole number value
  int minute; //minute whole number value
  double angleH; // angle of hour hand
  double angleM; // angle of minute hand 

  //promt user
  cout << "Enter hours: " ; 
  cin >> hour; //input hour into int vatiable
  cout  << "Enter minutes: " ;
  cin >> minute; //get minute from user
  

  // calulte angles
  angleM = (double) minute * 6; // each minute is 6 degrees, convert it double as well
  angleH = (double) (hour % 12) * 30 + minute * 0.5;  // 30/60 is 0.5 times each minute, hour hand moves 30 degrees every hour 360/12 is 30, modulus makes sure even 26 hours ect is correct.


  //output result
  cout << "The angle of the hour hand is : " << angleH << endl; //output hour hand angle
  cout << "The angle of the minute hand is : " << angleM << endl; //output minute hand angle
  cout << endl;












  return 0;
}
