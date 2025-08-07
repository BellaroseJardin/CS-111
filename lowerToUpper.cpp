/****************************************************************************************************************************
Bellarose Jardin
CS 111
Assignment 2 - lowerToUpper.cpp
2-10-25

This program will ask for a lowercase letter. It will then convert it to the corresponding uppercase letter and display it

****************************************************************************************************************************/
#include <iostream> // for cin and cout
using namespace std;

int main ()
{
  //declare vairables
  char uppercase; //uppercase letter
  char lowercase; // lowercase letter
  int offset;     // used to calculate corresponding letter

  // promt user
  cout << "Enter a lowercase letter: "; // ask user to input lowercase 
  cin >> lowercase; // input gets stored into variable "lowercase
   
  
  // convert to corresponding uppercase
  offset = 32; // the value 32 is the differnce between each coressponding upper and lower case letter
  uppercase = lowercase - offset; // uppercase = lowercase - 32 ........ to calculate lowercase do the opposite

  // output corresponding letter
  cout << "The uppercase is " <<  uppercase << "." << endl; // outputs letter to user
  cout << endl; // creates blank space












  
  return 0;

 }
