/*******************************************************************************************************
Bellarose Jardin
CS 111
Professor Slott
fiboancci.cpp
3-12-25
a program that will show Fibonacci numbers ( 0 1 1 2 3 5 8 13 ... ). The program should ask for the
number of Fibonacci numbers the user wants to see (N >= 3). 
*********************************************************************************************************/
#include <iostream>
using namespace std;
int main ()
{
  //declare variables
  int num; //desired digits
  int n1 = 0; //set first int to 0
  int n2 = 1; //set second int to 1
  int next; //value of n1 and n2
  
  //prompt user AND reject band inputs
  do{
    cout << "Enter the number of fibonacci numbers you want to see (N >= 3): ";
    cin >> num;
  }while(num < 3); //if num is less than 3 loop back to prompt

  //n1 & n2 are pre set go ahead and ouput them
  cout << endl << n1 << " " << n2 << " ";
  
  //for loop
  for(int i = 3; i <= num; i++) //i begins at three since 1 & 2 are set! incremnet by 1
    {
      next = n1 + n2; //next int is value of last two
      cout << next << " "; //output next
      n1 = n2; //move over by one
      n2 = next; //move over by one
    }
  cout << endl << endl; //blak lines
  
  
  return 0;
}
