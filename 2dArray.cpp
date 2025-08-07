/*****************************************************************
CS111
Template prepared by Kazumi Slott
11-1-16
Lab on 2D arrays
*****************************************************************/ 
#include <iostream>
#include <iomanip>
using namespace std;

// Where does the prototypes must go after

//declare 2 constants for the sizes of the 2 dimensional array
const int  NUM_STU  = 5;
const int  NUM_TEST = 3;

void fillArray(int scores[] [NUM_TEST]);
void showTable(const int scores [] [NUM_TEST]);


int main()
{
  //declare the 2 dimensional array and initialize the array using the initialization list
  int scores[NUM_STU][NUM_TEST] ; //COLUM then ROW
  fillArray(scores); //fills arrays with scores
  // Call showTable here
  showTable(scores);
  
  return 0;
}
/*******************************
this funcytion will print the test scores for each student and display the averages
const int socre is for the 2D array called scores in mian
NUM_TEST is the size of the subarray
***********************************/

void showTable(const int scores [] [NUM_TEST])
{
  int total; //to calulate the avg
  
  //Show the lables for the table
  cout << setw(10) << "Test#" << setw(10) << "Stu 1" << setw(10) << "Stu 2" << setw(10) << "Stu 3" 
       << setw(10) << "Stu 4" << setw(10) << "Stu 5" << setw(10) << "Average" << endl;
  
  // Show the table using a nested for loop here
  for( int test = 0; test < NUM_TEST; test++) //start with row for each test score and test avg
    {
      total = 0; //set to 0 so each test avg is differnt
      cout << setw(10) <<  test + 1 ;
      for (int stu = 0; stu < NUM_STU ; stu++) //fill each students score
	{
	  cout << setw(10) <<  scores[stu][test] ; //print the score
	  total += scores[stu][test]; //total gets each value of the indexes
	}
      cout << setw(10) << fixed << setprecision(1) << (double)total/NUM_STU ;//cast to double
      
      cout << endl;
    }
  //TEST averaage
  cout << setw(10) <<  "Average";
  for (int stu = 0; stu < NUM_STU; stu ++) //starts with columns
    {
      total = 0; //must set total to 0 so each student's avg is correct
      for( int test = 0; test < NUM_TEST; test ++)
	{
	  total += scores[stu][test]; //total gets the value of the index of scores
	}
      cout << setw(10) << fixed << setprecision(1)<< (double)total/NUM_TEST;
    }
  cout << endl;
  
  cout << endl;
}
/********************
this function will get number from the user and input them into the array
int scores is the scores array in mian
NUM_TEST is the rows of test and subarray in mian 
**********************************/
void fillArray(int scores[] [NUM_TEST])
{
  for(int test = 0; test < NUM_TEST; test++) //filling horizontally so starts with rows
    {
      cout << "Enter scores for Test #" << test + 1 << endl;
      for(int stu = 0; stu < NUM_STU ; stu++) //then fills each coloumn
	{
	  cout << "Student #" << stu + 1 << ": " ;
	  cin >> scores[stu][test]; //inputs into array indexes
	}
      cout << endl;
    }
}
