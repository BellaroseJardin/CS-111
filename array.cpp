/**********************************************************************************
Bellarose Jardin
 array.cpp
Professor Slott
4-9-25
 This program will use arrays and functions to compute what the user wants from a menu
****************************************************************************/
#include <iostream>
using namespace std;
void fillArray(int ar[], int s);
void printArray(const int ar[], int s);
void reverseArray(int ar[], int s);
int sequentialSearch(const int ar[], int s, int k);
void selectionSortAscend(int array[], int N);
void selectionSortDescend(int array[], int N);
double getAvg(const int ar[], int s);
int findHighest(const int ar[], int s);
void doubleArray(int ar[], int s);
void ShowBarGraph(int ar[], int s);

int main()
{
  //decalre variables
  const int SIZE = 5; //constant array size
  int array[SIZE]; //initalize array
  int choice; //what choice the user picks
  int key; //key for option 10
  int index; // where the key was found
  double average; //to putput average of the array
  int highest; //fund the highest int in the array
  
  //do while loop for all cases utill 13 is entered then escape
  do{
    /*
      cout << "============" << endl << "1. Fill array" << endl << "2. print array" << endl << "3. reverse array" << endl;
      cout << "8. Sort Ascend" << endl << "9. Sort Decend" << endl << "10. sequential search" << endl;
      cout << endl << "Enter your choice: " ;
      cin >> choice;
    */
    
    //new menu
    cout << "----------------------------------------------------------------------" << endl;
    cout << "1) fill 2) print 3) reverse 4) average 5) highest 6) double 7) bar graph 8) selection sort ascending 9) selection sort descending 10) sequential search 13) quit" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    //switch correspinding to menu above
    switch(choice)
      {
      case 1: fillArray(array,SIZE); //user enters nums
	cout << endl ;
	break;
      case 2: cout << endl;
	printArray(array,SIZE); //prints values of array
	cout << endl ;
	break;
      case 3:reverseArray(array, SIZE); //reverses num in array
	break;
      case 4: average = getAvg(array,SIZE); //average gets average from func
	cout << endl << "The average number is  " << average << endl << endl;
	break;
      case 5: highest = findHighest(array,SIZE); //highest is the highest return value form the function
	cout << endl<< "The highest number is " << array[highest] << endl << endl;
	break;
      case 6:cout << endl;
	doubleArray(array,SIZE); //doubles (*2) in the array
	break;
      case 7: ShowBarGraph(array,SIZE); //shows star bar graph by num/10
	break;
      case 8: selectionSortAscend(array,SIZE); //shows nums from low to high
	cout << endl;
	break;
      case 9: selectionSortDescend (array, SIZE); //shows num from high to low
	cout << endl;
	break;
      case 10: //key case
	cout << endl  << "Enter the key: ";
	cin >> key;
	index = sequentialSearch(array,SIZE, key); //index is index form func if unc return -1 then nothing ws found
	if ( index == -1)
	  cout << endl << key << " was not found. " << endl << endl;
	else
	  cout << endl << key << " was found at index " << index << "." << endl << endl;
	break;
      case 13: cout << endl <<  "Thank you for using our system." << endl << endl; //exit case
	break;
      default: cout << endl << "Invalid choice" << endl << endl; //invalid
      }	  
  }while(choice != 13); //if 13 then exit
  
  return 0;
}

/***************************************
this function will fill the array with numbers the user inputs
ar[] is array in main and s is const SIZE
******************************************/
void fillArray(int ar[], int s)
{
  //  srand(time(0));
  cout  << endl;
  for(int i = 0; i < s; i++) //goes throgh array
    {
      cout  << "Enter a number: ";
      cin >> ar[i]; //each number inputted goes into that slot
      
      //  ar[i] = rand() % 50 + 1;
    }
  
}

/*************************************
this function will show the array with the correct values
ar[] is array and int s is const SIZE in main
***************************************/

void printArray(const int ar[], int s)
{
  cout << "The numbers in the array are ";
  for(int i = 0; i < s; i++) //again goe sthrough array
    cout << ar[i] << " " ; //cout each slot value
  cout << endl;
}

/*************************************
thsi function will search array for given num
const int ar[] gets array from main doesn't change
int s is const SIZE
int k is key inputted by user
********************/
int sequentialSearch(const int ar[], int s, int k)
{
  int key = -1; //set key to -1
  
  for(int i = 0; i < s ; i++)
    {
      if(ar[i] == k) //if key inputted by user is in array return the index
	key = i;
    }
  //if not return -1 or key
  return key;
    
}

/***********************************************
this function will sort the numbers in ascending order: smallest up to largest                           
int array[] is array in mian int N is const SIZE
*********************************************/
void selectionSortAscend(int array[], int N)
{
  int lrgIndx; //the index of the largest value                                                            
  int temp; //temporary variable that holds the largest value                                              
  
  //last is the last index in unsorted portion                                                             
  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest                                                  
      //find the largest in unsorted portion ([0..last])                                                   
      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger                                       
            lrgIndx = i;
        }
      
      //swap the largest with the last item in the unsorted portion                                        
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}

/**************************************************
 this function will sort the numbers in descending order: largest down to smallest
int array is array form main int N is const SIZE form main 
*************************************************/
void selectionSortDescend(int array[], int N)
{
  int smlIndx; // the index of the smallest value
  int temp;    // temporary variable that holds the smallest value
  
  // last is the last index in the unsorted portion
  for (int last = N - 1; last >= 1; last--)
    {
      smlIndx = 0; // assume the first item is the smallest
      
      // find the smallest in the unsorted portion ([0..last])
      for (int i = 1; i <= last; i++)
	{
	  if (array[i] < array[smlIndx]) // the current item is smaller
	    smlIndx = i;
	}
      
      // swap the smallest with the last item in the unsorted portion
      temp = array[smlIndx];
      array[smlIndx] = array[last];
      array[last] = temp;
    }
}
/**********************************
this function will reverse the array
int ar[] is array form main and int s is const SIZE
************************************/
void reverseArray(int ar[], int s)
{
  int temp; //tempory place holder
  for(int L = 0, R = s - 1; L < s/2 ; R--, L++) //left strats at ar[0] right strats at ar[4]
    {
      temp = ar[L]; //tempormary gets ar[0] for first round
      ar[L] = ar[R]; // ar[0] now has value of ar[4]
      ar[R] = temp; //ar[4] now was ar[0] value
      
    }
}
/********************************
this function will find the average of the array 
const int ar is array 
int s is const int SIZE
******************************/
double getAvg(const int ar[], int s)
{
  int total = 0; //total value
  int count = 0;
  double average; //what im returning
  
  for(int i = 0 ; i< s; i++) //goes through array
    {
      total+= ar[i]; //for each index add value to total
      count++; //incrment count by 1
    }
  average = (double)total/count; //set average
  return average;
  
}
/******************************************
this function will find the highest index of the array
const int ar[] is the constant array form  main
int s is SIZE
**************************************/
int findHighest(const int ar[], int s)
{
  int highest = 0; //set highest to the first index (0)
  for(int i = 1; i < s; i++) //goes through array
    {
      if (ar[i] > ar[highest]) //if i index is greater
	highest = i; //highesy is now that index
    }
  return highest;
  
}
/****************************************
this function will double the values in the array
int ar[] will change value in array in main
int s is const int SIZE form main
*******************************/
void doubleArray(int ar[], int s)
{
  for (int i = 0; i < s; i ++) //goes through array
    ar[i]*= 2; //each index gets the value of the index * 2
  
}
/***********************************
this function will print stars according the num for a bar graph
int ar[] is array in main
int s is const SIZE in main
************************************/
void ShowBarGraph(int ar[], int s)
{
  int stars; //how many stars 
  for(int i = 0; i < s; i++) //goes through array
    {
      cout << endl << "Slot " << i << ": ";
      stars = ar[i]/10; //number of stars needed is index value /10
      for( int s = 0; s < stars; s++) //prints stars untill need bvalue is met
	cout << "*" ;      
    }
  cout << endl << endl;
  
}
