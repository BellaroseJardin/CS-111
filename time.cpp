/******************************************************************************************************************************

Bellarose Jardin
CS 111
time.cpp
2-12-2025
 
 The user will enter a time in seconds (the number of seconds that have passed since midnight). this program will convert it to hours, minutes and seconds.
*******************************************************************************************************************************/
#include <iostream>
using namespace std;

int main ()
{



  // delcare variables
  
  int hour; //hours
  int minute; //minutes
  int sec; //what i will get from user, seconds

  // promt user
  
  cout << "Enter the time in seconds: "; //asks user for input
  cin >> sec; //get seconds from user stores into variable int sec
  cout << endl; // balnk line
  

  //calculate hours minetues and seconds using modulus

  hour = sec / 3600; // gives me how many hours
  sec = sec % 3600; // how many seconds remaining after hours is calcluated
  minute = sec / 60; // gives me how many minutes there are
  sec = sec % 60; // last seconds remaining

  //output result
  cout << hour << " hours " << minute << " minutes " << sec << " seconds " << endl; // shows statemnet with correct spaces
  cout << endl; // blank  space 






  return 0;

}
