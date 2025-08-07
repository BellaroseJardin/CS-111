/******************************************************************************************
Bellarose Jardin
CS 111
Professor Slott
TemperatureSwitch.cpp
3/6/25
onvert a temperature between Fahrenheit and Celsius. Your program will ask the user to enter an F or C (F if he has a temperature in Fahrenheit and C if he has a temperature in Celsius). It will then convert the temperature to the other unit. You MUST use switch for this program
*******************************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
  // delcare variables
  char temp; // for either 'C' || 'c' || 'F' || 'f' || invalid character 
  int cel; // for when celsius is entered
  int fahr; //for when fahrenheit is entered
  
  // prompt user
  cout << "Which temperature do you have? Enter F for Fahrenheit or C for Celsius?: " ;
  cin >> temp; //get what type of temp they have
  
  //switch
  
  switch(temp) // switch to corrclate the correct char for each prompt and/or calculation
    {
     case'F': //upercase
     case'f': cout << "Enter a temperature in Fahrenheit: "; //lower case for SWITCH cout works for both cases until BREAK
     cin >> fahr; //retreieve temp in fahrenheit from user
     cout << fahr << " Fahrenheit = " << fixed << setprecision(2) <<  (fahr - 32) * 5.0/9 << " Celsius" << endl << endl; //set decimals to 2 places and caluclate fahrentheit to celsius
     break; // out of condition
     case'C': //uppercase
     case'c': cout << "Enter a temperature in Celsius: " ; //lower case and cout counts for all cases after previous break for SWITCH
     cin >> cel; //get degrees in celsius from user
     cout << cel << " Celsius = " << fixed << setprecision(2) << (9.0/5) * cel + 32 << " Fahrenheit" << endl << endl; //set deciaml places to 2 and caluclate to fahrenheit with a double value
     break; //get out of this condition
     default: cout << "Invalid choice" << endl << endl; //if char entered is none of the above cases THEN value is invalid
    }


  return 0;
}
