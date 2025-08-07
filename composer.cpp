/**********************************************************
Bellarose Jardin
COMPOSER final project
Professor slott
3 may 2025
thsi program will read composers from a input file and sort them accrodingly
*********************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "input.h"
using namespace std;
//global varibales
const int CAPACITY = 10; //max of array
const int NUM_PIECES = 5;//number of pieces per composer
//structs

//struct of composers peices with title of song and year
struct piece {
  string title;
  string year;
};

//struct for each composer with and array inside that contains the above struct
struct composer {
  string fName; //first name
  string lName; //last name
  string place; //where they are from
  piece pcsAr[NUM_PIECES]; //an array that conatins their songs with a struct INSIDE each slot for itle and year
};

//protoypes
int showMenu();
void removeSpaces(string& str);
void readOneComposer(ifstream& fin, composer& c);
void addInOrder(composer ar[], composer c, int& num);
void fillAr(composer ar[], int& num);
void displayOneComposer(const composer& c);
void displayAll(const composer ar[], int num);
void findKey(const composer ar[], int num);
int avgYear(const composer& c);
void showComposersChronologically(const composer ar[], int num);
int stringToInt(string s);
void sortPieces(piece pcs[], int size);

//MAIN
int main()
{
  //declare
  composer ar[CAPACITY]; //initialize array with composer inside
  int num = 0; //start at the first slott
  fillAr(ar, num);//fill the array from the input file
  int choice; //choice the user inputs
  
  do {
    choice = showMenu(); //calls the showmenu function whatever the user enters is now the value of choice
    
    //switch that corresponds with the menu shown
    switch(choice)
      {
      case 1:
	{
	  cout << endl << "Which composer would you like to see?" << endl;
	  for (int i = 0; i < num; i++) //go through each composer and print last then first name
	    {
	      cout << i + 1 << ": " << ar[i].lName << ", " << ar[i].fName << endl;
	    }
	  cout << "Enter your choice from 1 to " << num << ": "; //asks which composer they would like to see
	  int idx = getInt(1, num, "Invalid choice. Enter again: "); //indx is the index of desored composer in the array, get int rejects bad
	  cout << endl;
	    displayOneComposer(ar[idx - 1]); //call display one composer function -1 to get the corrcet slot otherwise it is one off
	    cout << endl;
	    break;
	}
      case 2: cout << endl;
	displayAll(ar, num); //calls display ALL function
	break;
      case 3:
	findKey(ar, num); //cals findkey FUNC
	break;
      case 4: 
	showComposersChronologically(ar, num); //calls function
	  break;
      }
  } while (choice != 5); //break out if the user enters 5 ....the choice used to end teh porgram
  
  return 0;
}

/*******************************
this function will display the menu and return the useres choice to the main fuction, no parametres just returns and int (choice)
********************************/
int showMenu()
{
  int choice;
  cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
  cout << "1: display information on a composer" << endl;
  cout << "2: display information on all the composers" << endl;
  cout << "3: find a keyword" << endl;
  cout << "4: Show composers chronologically" << endl;
  cout << "5: End" << endl;
  cout << "Enter your choice: ";
  choice = getInt(1, 5, "Invalid choice. Enter again: "); //rejcts bad input
    return choice;
}

/*********************************************
this function will remove unwanted spaces so the compser info may be displayed correctly
string & str is a pass by refence updating a string by removing spaces will use in other fuctions like readonecomposer
*******************************************/
void removeSpaces(string& str)
{
  int start = 0; // Initialize start index to 0
  while (start < str.length() && (str[start] == ' ' || str[start] == '\n'))  // Loop through the string from the beginning, skipping spaces or newlines
    start++;
  int end = str.length() - 1; // Set the end index to the last character in the string (length - 1)
  while (end >= 0 && str[end] == ' ')// Loop backwards from the end of the string, skipping trailing spaces
    end--;
  
  str = str.substr(start, end - start + 1);  // Extract the substring from 'start' to 'end', 
}

/********************************************8
this fuction will read one composer form the array from the pinput file
fin - ifstream reference used to read data from the input file
   c - reference to a 'composer' structure where data will be stored
**********************************************/
void readOneComposer(ifstream& fin, composer& c)
{
  string fullName;
  // Read the composer's full name from the file until a comma is encountered
  getline(fin, fullName, ',');
  removeSpaces(fullName); // Remove any leading/trailing spaces from the full name
  
  // Find the space between the first and last name in the full name string
  int spacePos = fullName.find(' ');
  // Extract the first name (from start to the space position)
  c.fName = fullName.substr(0, spacePos);
  // Extract the last name (from space position + 1 to end of string)
  c.lName = fullName.substr(spacePos + 1);
  // Remove spaces from both
  removeSpaces(c.fName);
  removeSpaces(c.lName);
  // Read the composer's place from the file until a comma is encountered
  getline(fin, c.place, ',');
  removeSpaces(c.place); //remove spaces

 // Read data for each musical piece associated with the composer
    for (int i = 0; i < NUM_PIECES; i++)
      {
	 // Read the piece title until an opening parenthesis '(' is encountered
	getline(fin, c.pcsAr[i].title, '(');
	removeSpaces(c.pcsAr[i].title);
	getline(fin, c.pcsAr[i].year, ')');
	removeSpaces(c.pcsAr[i].year);
	// Skip the comma or newline after the year if it's not the last piece
	if (i < NUM_PIECES - 1)
	  fin.ignore(); // skip comma or newline
      }
}


/***************************************************
 Inserts a composer record into the array in alphabetical order
           by last name, then by first name if last names are the same.
 Parameters:
   - ar[] : The array of composer records.
   - c    : The composer record to insert.
   - num  : The current number of composers in the array (passed by reference).
 ******************************************/
void addInOrder(composer ar[], composer c, int& num)
{
  int i = num - 1;
  // Shift elements to the right until the correct position for c is found
  while (i >= 0 && (ar[i].lName > c.lName || (ar[i].lName == c.lName && ar[i].fName > c.fName)))
    {
      ar[i + 1] = ar[i];  // Move element one position to the right
      i--;
    }
  ar[i + 1] = c; // Insert the new composer at the correct position
  num++;
}
/****************************************
Reads composer records from the "composer.in" file and stores
them in an array in sorted order (by last name, then first name).
 The function stops when either the file ends or the array reaches  its capacity.
 Parameters:
   ar[] : The array of composer records to be filled.
    num  : The number of composers currently in the array (passed by reference).

 ***************************************/
void fillAr(composer ar[], int& num)
{
  composer c;
  // Check if the file opened successfully
  ifstream fin("composer.in");
  if (!fin)
    {
      cout << "Could not open file." << endl;
      exit(1);
    }
  
  readOneComposer(fin, c);
   // Continue reading and adding composers while stream is valid and space remains
  while (num < CAPACITY && fin)
    {
      addInOrder(ar, c, num);
      readOneComposer(fin, c);
    }
  
  fin.close();
}

/************************************
Sorts an array of musical pieces in descending order by year
ar[]  : The array of piece structs to be sorted.
   - size  : The number of elements in the array.
 ***********************************/
void sortPieces(piece ar[], int size)
{
  int lrgIndex;
  piece temp;

   // Loop through each position in the array, starting from the end
  for (int last = size - 1; last >= 1; last--)
    {
      lrgIndex = 0;
      // Find the index of the largest (most recent) year in the unsorted portion
      for (int i = 1; i <= last; i++)
	  {
            if (ar[i].year > ar[lrgIndex].year)
	      {
                lrgIndex = i;
	      }
	  }
      
      // Swap the largest to the end
      temp = ar[lrgIndex];
      ar[lrgIndex] = ar[last];
      ar[last] = temp;
    }
}

/*****************************************
Displays detailed information about a single composer
c : A constant reference to the composer to be displayed.
 ****************************************/
void displayOneComposer(const composer& c)
{
  cout << "----------------------------------------" << endl;
  cout << c.fName << " " << c.lName << " from " << c.place << endl;
  // Copy pieces to a local array for sorting
  piece sorted[NUM_PIECES];
  
  for (int i = 0; i < NUM_PIECES; i++)
    {
      sorted[i] = c.pcsAr[i];
    }
  // Sort the copied pieces in descending order by year
  sortPieces(sorted, NUM_PIECES);
  
  // Display sorted pieces
  for (int i = 0; i < NUM_PIECES; i++)
    {
      cout << "\t" << sorted[i].title << " " << sorted[i].year << endl;
    }
    
}

/******************************************
Displays all composer records in the array by calling displayOneComposer for each one.
ar[] : The array of composer records to display.
num  : The number of composers currently in the array.
*******************************************/
void displayAll(const composer ar[], int num)
{
  // Loop through each composer and display their information
  for (int i = 0; i < num; i++)
    {
      displayOneComposer(ar[i]);
    }
  cout << endl;
}

/******************************************                                                                                                                            Prompts the user for a keyword and searches for that keyword
ar[] : The array of composer records to search through.
num  : The number of composers currently in the array. 
*******************************************/
void findKey(const composer ar[], int num)
{
  string key; //the users key word
  cout << "\nPlease enter a keyword: ";
  cin.ignore(1000, '\n'); //empty input stream
  getline(cin, key); //read full line including spaces
  
  bool found = false; //tracker to see if anything matches
  
  cout << "\n--------------- RESULT ---------------" << endl;
  
  //go through each composer
  for (int i = 0; i < num; i++)
      {
        const composer& c = ar[i];
        bool matched = false; //did the composer already match?
        bool printedName = false; //did it already print their name?
	
	//to track each match type
        bool nameMatched = (c.fName.find(key) != string::npos || c.lName.find(key) != string::npos);
        bool placeMatched = (c.place.find(key) != string::npos);
	
	// Collect pieces with a matching title or year
        piece matchedPieces[NUM_PIECES];
        int matchCount = 0;
	
	//check each piece for a match in title or year
        for (int j = 0; j < NUM_PIECES; j++)
	  {
            if (c.pcsAr[j].title.find(key) != string::npos || c.pcsAr[j].year.find(key) != string::npos)
	      {
		matchedPieces[matchCount++] = c.pcsAr[j];
	      }
	  }
	
        //  If name or place matched, print name (and place if applicable)
        if (nameMatched || placeMatched)
	  {
            cout << c.fName << " " << c.lName;
            if (placeMatched)
	      {
                cout << " from " << c.place;
	      }
            cout << endl;
            found = true;
            matched = true;
            printedName = true;
	  }
	
        // If pieces matched, print name (if not already), then pieces
	if (matchCount > 0)
	  {
	    if (!printedName)
	      {
		// For piece matches only, show just name
		cout << c.fName << " " << c.lName << endl;
		printedName = true;
	      }
	    
	    // Sort and print matched pieces
	    for (int j = 0; j < matchCount - 1; j++)
	      {
		int minIdx = j;
		for (int k = j + 1; k < matchCount; k++)
		  {
		    if (stringToInt(matchedPieces[k].year) < stringToInt(matchedPieces[minIdx].year))
		      {
			minIdx = k;
		      }
		  }
		piece temp = matchedPieces[j];
		matchedPieces[j] = matchedPieces[minIdx];
		matchedPieces[minIdx] = temp;
	      }
	    // Print all matched pieces with tab indentation
	    for (int j = 0; j < matchCount; j++)
	      {
		cout << "\t" << matchedPieces[j].title << " " << matchedPieces[j].year << endl;
	      }
	    
	    found = true;
	    matched = true;
	  }
	
        // Add spacing between composers
        if (matched)
	  {
            cout << endl;
	  }
      }
    
    if (!found) //if no key was found return it was not found
      {
	cout << key << " was not found" << endl << endl;
      }
}

/************************************
Converts a string containing only numeric characters into an int
s : The input string consisting of digits 
*************************************/
int stringToInt(string s)
{
  int num = 0;
  // Loop through each character in the string
  for (int i = 0; i < s.length(); i++)
    {
      // Convert character to digit and update the number
      num = num * 10 + (s[i] - '0');
    }
  return num;
}
/************************************                                                                                                                                 
Calculates the average year of a composer's pieces
c : A reference to a composer struct containing an array of pieces.
***************************************/
int avgYear(const composer& c)
{
  int total = 0;
  // Loop through all pieces and sum the year values (converted from string)
  for (int i = 0; i < NUM_PIECES; i++)
    {
      total += stringToInt(c.pcsAr[i].year);
    }
  // Return the rounded average using integer division
  return (total + NUM_PIECES / 2) / NUM_PIECES;
}
/************************************                                                                                                                                   Displays a list of composers ordered by the average year of their
 compositions, from earliest to latest.
ar[] : The array of composer records to process.
 num  : The number of composers currently in the array.
*************************************/
void showComposersChronologically(const composer ar[], int num)
{
  // Define a temporary structure to hold the composer's name and average yea
  struct AvgComposer
  {
    string fName, lName;
    int avg;
  }
    avgList[CAPACITY]; // Array to store composers with average years
  
  // Populate avgList with composers' names and average years
  for (int i = 0; i < num; i++)
    {
      avgList[i] = {ar[i].fName, ar[i].lName, avgYear(ar[i])};
    }
  // Sort the avgList by average year using selection sort
  for (int i = 0; i < num - 1; i++)
    {
      int min = i;
      // Find the index of the minimum average year
      for (int j = i + 1; j < num; j++)
	{
	  if (avgList[j].avg < avgList[min].avg)
	    min = j;
	}
      // Swap the found minimum with the current position
      AvgComposer temp = avgList[i];
      avgList[i] = avgList[min];
      avgList[min] = temp;
    }
  
  cout << "\nFirst Name        Last Name                   Avg Year of Compositions" << endl;
  cout << "----------------------------------------------------------------------" << endl;
  // Display the sorted composers and their average year
  for (int i = 0; i < num; i++)
    {
      cout << left << setw(20) << avgList[i].fName << setw(25) << avgList[i].lName << avgList[i].avg << endl;
    }
  cout << endl;
}
