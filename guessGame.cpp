/***********************************************************************
Bellarose Jardin
CS 111
Professor Slott
guessGame.cpp
3-12-25
A program that generates a random number between 1 and 100 and asks the user to guess what the number is. 
**************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  
  srand(time(0));//generates DIFFERNET random equence each time
  
  //declare varaibles
  int num; //variable for computers random int
  int guess; //user's guess
  
  //prompt user
  cout << "Guess a number between 1 and 100. Enter you guess: " ;
  cin >> guess;
  
  // generate random number
  num = rand() % 100 + 1; //num gets some random number between 1 and 100
  
  //while loop with if else
  while(guess != num) //when the guess is not correct
    {
      if(guess < num) //if the guess is lower than the answer
	cout  << "Too low, try again." << endl;
      else //if the guess is higher than the answer
	cout << "Too high, try again." << endl;
      
      //prompt user AGAIN in loop
      cout << "Enter your guess: " ;
      cin >> guess;
    }
  
  if(guess == num) //if the guess is correct!
    cout << "You guessed it right!" << endl;
  
  return 0;
}
