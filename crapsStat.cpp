/******************************************************************
Bellarose Jardin
CS 111
March 22 2025
This program will claulate the prbility of winning agiven # of craps games
 ******************************************************************/
#include <iostream>
using namespace std;
#include <cstdlib>
#include <iomanip>
#include "input.h"

/*********************************************
This function simulates rolling dice
*********************************************/
void rollDice( int first, int & sum) //updating sum
{
  do
    {
      sum = (rand() % 6 + 1) + (rand() % 6 + 1); // from 1-7 random
    }while (sum != first && sum != 7); //if they dont win or lose then keep going
}

/***********************************
This function will return if the player won or lost
****************************************************/

bool playGame()//no param needed
{
  int first, sum; //first roll and sum of dice
  bool win = false; //set bollean to false

  first = (rand() % 6 + 1) + (rand() % 6 + 1); //caluclate first roll

  if(first == 7 || first == 11) // if sum == 7 or 11 then they won
    win = true;
  else if (first == 2 || first == 3 || first == 12) // if first roll == 2 || 3 || 12 then player lost
    win = false;
  else //if first round did not give a win or lose
    {
      rollDice(first, sum); //call roll dice to keep rollingg
      win = (sum == first);
    }
  return win; //retrun the booleean
}
/************************
this is the main to ptut everything together
*********************************************/

int main ()
{
  srand(time(0)); //to generate new random

  //decalre variables
  int num; // number of games played
  int wins = 0, lose = 0; // set win and lose # to 0

  //prompt user
  cout << "How many games do you want to play?: ";
  num = getInt(1,100000000, "You need to input a number between 1 and 100000000: "); //call get int to set min an max and error

  //play game
  for (int i = 0; i < num; i ++) //keeps playing for # enetred
    {
      if(playGame())
	wins++; //id true then win inrcements
      else
	lose++; //if not then lose incremnets

    }

  cout << "\t" << "win % \t lose %" << endl << fixed << setprecision(3) << "\t" << (wins * 100.0 /num); //calulate %'s won and lost
  cout << "\t" << (lose * 100.0/num) << endl << endl;
  return 0;
}
