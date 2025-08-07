/*******************************************************************************************
Bellarose Jardin
CS 111
Professor Slott
age.cpp
3-12-25
a program that will read an unknown number of ages. (0 is a valid age used for a baby.) The user will
enter a negative number if there are no more ages to enter. The program will output the average age, the
number of minors (less than 18), the number of adults (18 and above) and the youngest and oldest ages. If
no ages were entered, display “No ages were entered”
********************************************************************************************/
#include <iostream>
using namespace std;
int main ()
{
  //declare variables
  int oldest; //oldest
  int youngest; //youngest
  int total = 0; //set total to zero
  int num; //how mnay ages were entered could so minor + adult i prefer this way
  int adult; //adult number
  int minor; //minor number
  int age; //age enters
  
  //prompt user
  cout << "Enter an age: ";
  cin >> age;
  
  oldest = age; //set oldest to the first age
  youngest = age; //set yougest to the first age
  
  //while loop
  while( age >= 0) //if age is NOT negative continue to loop
    {
      
      total += age; //add age to total
      num++; //incrment num by 1
      if (age >= 18) //if age is adult 
	adult++; //incremnet adult by 1
      else //not adult
	minor ++; //incremnet minor by 1
      if( age > oldest) //if age is GREATER than oldest 
	oldest = age; //oldest takes the new age value
      if (age < youngest) //if age is LESS than youngest
        youngest = age; //youngest takes new age value
      //re propmp user
      cout << "Enter an age: ";
      cin >> age;
    }
  
  //check to make sure ages were entred
  if(num == 0) //if no ages were entered
    cout << endl << "No ages were entered" << endl << endl;
  else //if ages were entered
    {
      cout << endl << (double)total/num << " (average)" << endl; //double to output decimal
      cout << minor << " (minors)" << endl; //minors output
      cout << adult << " (adults)" << endl; // adults output
      cout << oldest << " (oldest)" << endl << youngest << " (youngest)" << endl << endl; //oldest output
    }
  
  return 0;
}
