/****************************************
Bellarose Jardin
CS111
chipsSalsa.cpp
4-9-25

This program lets a maker of chips and salsa keep track of sales for five 
different types of salsa: mild, medium, sweet, hot, and zesty.
****************************************/
#include <iostream>
#include <iomanip>
#include "input.h"
using namespace std;
const int SIZE = 5; //number of types of salsa

//prototypes
void fillJarsSoldArray(const string s[], int j[]);
void printSales(const string s[], const int j[]);
int getTotal(const int j[]);
void getHighestLowestSelling(const int jar[], int&highest, int&lowest);

int main()
{
  //decalre varibles / arrays
  string salsas[SIZE] = {"mild", "medium", "sweet", "hot", "zesty"}; //types of salsa
  int jars[SIZE]; //number of jars sold per salsa type
  int highest; //highest number of jars sold                                                       
  int lowest; //lowest number of jars sold
  
  // call arrays
  fillJarsSoldArray(salsas, jars);
  printSales(salsas, jars);
  cout << endl << "The total number of jars sold is " << getTotal(jars) << endl;
  getHighestLowestSelling(jars, highest, lowest); 

  cout << "The highest selling type is " << salsas[highest] << endl;
  cout << "The lowest selling type is " << salsas[lowest] << endl << endl;

  return 0;
}

/***********
This function prompts the user to enter the # of jars sold for each salsa type
and fills the jars sold array.
string s[] is salsa name array and int j is jar #
***********/
void fillJarsSoldArray(const string s[], int j[])
{
  for(int i = 0; i < SIZE; i++) //pass through array
    {
      cout << "Enter the number of jars sold for " << s[i] << ": ";
      j[i] = getInt(0,1000000, "\tInvalid. Enter a number between 0 and 1000000: "); //refernce getint
      cout << endl;
    }
}

/********************
This function displays the sales for each salsa type.
const string s[] is name of salsa, const int j[] is # of jars
**************************************/
void printSales(const string s[], const int j[])
{
  for(int i = 0; i < SIZE; i++)
      cout << left << setw(10) << s[i] << right << setw(5) << j[i] << endl;
}

/***********
total == total number of jars sold
This function will return the total number of jars sold.
const int j[] is array in main of # of jars
***********/
int getTotal(const int j[])
{
  int total = 0; //total number of jars
  for(int i = 0; i < SIZE; i++) //pass through array
    total += j[i]; //add value of index to total

  return total;
}

/***********
highest == index of highest value
lowest == index of lowest value
last == last index in unsorted portion
This function finds the highest and lowest selling salsas
***********/
void getHighestLowestSelling(const int jar[], int&highest, int&lowest)
{
  highest = 0;
  lowest = 0;
 
  for(int i = 1; i < SIZE; i++)
    {
      if(jar[i] > jar[highest])
	highest = i;

      if(jar[i] < jar[lowest])
        lowest = i;
    }
}
