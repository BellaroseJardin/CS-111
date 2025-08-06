/*******************************************************************************
Bellarose Jardin
CS 111
Profesor Slott
trainagle.cpp 3-28-25
This is a program that uses 3 point of a triangle o determine the typ, scalene ,isolises, equalateral
**********************************************************************************/
#include <iostream>
#include "myMath.h"
using namespace std;

void getPoint(int &x, int &y);
void showProgramInfo();
double calculateDistance(int x1, int y1, int x2, int y2);
void determineTriangleType(double d1, double d2, double d3);
int main()
{
  //decalre variables
  int x1, y1, x2, y2, x3, y3;

  //disaplay hit enter to continue
    showProgramInfo();

    //retrive 3 points
    cout << "Point 1" << endl;
    getPoint(x1, y1); //pass by refernce for all three points 
    cout << "Point 2" << endl;
    getPoint(x2, y2);
    cout << "Point 3" << endl;
    getPoint(x3, y3);

    //calculate the distance
    double d1 = calculateDistance(x1, y1, x2, y2); //distance with pass by value
    double d2 = calculateDistance(x2, y2, x3, y3);
    double d3 = calculateDistance(x1, y1, x3, y3);

    //what type is it?
    determineTriangleType(d1, d2, d3); //use above distance values to find out
    
    return 0;
}


/**************************************
 Function to display program information
user will hit enter to continue
**************************************/
void showProgramInfo()
{
  char enter;
    cout << "***************************************************************\n";
    cout << "This program will ask you to enter 3 points of a triangle and\n";
    cout << "tell what kind of triangle it is. Please hit ENTER to continue.\n";
    cout << "***************************************************************\n";
    cin.get(enter); //get enter char
}

/*******************************************
 Function to get a point from the user and update in main
x is x cordinate entered y is y cordinate entered
***********************************************/
void getPoint(int & x, int & y)
{
    cout << "\tEnter the x-cordinate: ";
    cin >> x ;
    cout << "\tEnter the y-cordinate: ";
    cin >> y;
    cout << endl;
}

/**************************************************
 Function to calculate the distance between two points
pass by value 3 entered cordinates, return distance
******************************************************/
double calculateDistance(int x1, int y1, int x2, int y2)
{
  int dx = x2 - x1; //differnce of x cordinates
  int dy = y2 - y1; //differnce of y cordintaes
  return sqrt(pow(dx, 2) + pow(dy, 2)); //formula to return distance 
}

/*************************************************
 Function to determine the type of triangle
d1 is distance 1, d2 = distance2, d3 = distance 3
***************************************************/
void determineTriangleType(double d1, double d2, double d3)
{
  if (fabs(d1 - d2) < 0.00001 && fabs(d2 - d3) < 0.00001) //if absolue of d1-d2 AND d2 -d3 < 0.00001 then equalaterial  
    cout << "This triangle is equilateral" << endl;
  else if (fabs(d1 - d2) < 0.00001 || fabs(d2 - d3) < 0.00001 || fabs(d1 - d3) < 0.00001) //if absolute d1-d2 OR d2 -d3 < 0.00001 isocolices
    cout << "This triangle is isosceles" << endl;
   else 
     cout << "This triangle is scalene" << endl; //if not above then scalene
  
  cout << endl;
}
