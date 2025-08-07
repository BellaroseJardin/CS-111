/***********************************************************************
Bellarose Jardin
CS 111
Professor Slott
A program that caluclates invoice for a mail order
 *********************************************************************/
#include <iostream>
#include "input.h"
#include "/cs/slott/hw/35mailOrderA.h"
#include "/cs/slott/hw/24mailOrderB.h"
#include "/cs/slott/hw/mailOrderC.h"
using namespace std;
void getCustomerInfo(int & account, int & month, int & day, int & year, char & county);
void getItemsInfo(double & totalP, int & totalW);
void outputInvoice1(int acc, char co, int m, int d, int y);
void outputInvoice2(double total, double disc, double tax, double ship); 
double calcShipping(int tw); 
double calcDiscount(double pr, int mo); 
double calculateSalesTax(double total, double disc, char co);

int main ()
{
  //declare variables
  int acc, month, day, year; // account # month day and year
  char county; // S O or L
  double totalP; //items total price added
  int totalW ; //total weight
  double discount, salesTax,  shipping; //discount price salesTax and shipping prices
  
  //call functions
  getCustomerInfo(acc,month,day,year,county); //ask for account # date and county rejects bad
  getItemsInfo(totalP,totalW); //get items for mail order

  //get values
  discount = calcDiscount(totalP, month); //get discount from calcdiscount func
  shipping = calcShipping(totalW); //get shipping from calcShipping func
  salesTax = calculateSalesTax(totalP,discount,county); //salestax from mailOrderC

  //invoice
  outputInvoice1(acc,county,month,day,year); //part 1 of invoice
  outputInvoice2(totalP,discount,salesTax,shipping); //display prices
  
  return 0;
}
/************************************************************************************
this function will get the users information for the mailOrder
account number, month, day, year and county
************************************************************************************/
void getCustomerInfo(int & account, int & month, int & day, int & year, char & county)
{
  //account
  cout << "Enter an account number: ";
  account = getInt(1000,9999, "An account number must be 1000 - 9999. Enter again: ");
  //month
  cout << endl << "Enter a month: ";
  month = getInt(1,12,"A month must be 1 - 12. Enter again: "); //call getInt from input.h set min.max.msg
  //day
  cout << endl << "Enter a day: ";
  day = getInt(1,31,"A day must be 1 - 31. Enter again: "); 
  //year
  cout << endl << "Enter a year: ";
  year = getInt(2000,2100,"A year must be 2000 - 2100. Enter again: ");
  //county
  cout << endl << "Enter a county code. Enter S, O or L: ";
  cin >> county;
  while(county != 'S' && county != 'O' && county != 'L') //while char is not valid contine to invalid statemnt
    {
      cout << "Invalid county code. Enter uppercase S, O or L: " ;
      cin >> county;
    }

}
/******************************************************************************
This function will retrive the weight and price of items in the mail Order
totalP is the total price
totalW is the totalW
********************************************************************************/
void getItemsInfo(double & totalP, int & totalW)
{
  char ans; //county answer
  int weight; //weight inputted
  totalW= 0; //set to 0
  totalP = 0.00; //set to 0
  double price; // price inputted

  //get item info
  cout << endl <<"Do you want to order an item? Enter Y or N: ";
  ans = getYN("Invalid response. Enter Y or N: ");
  while(ans == 'Y') //if user wants to add item
    {
      //price
      cout << endl << "\tEnter a price: ";
      price = getDouble(0.00,999.99, "\tA price must be between 0.00 and 999.99. Enter again: "); //call getDOuble from input.h
      totalP += price; //add price to totalprice
      //weight
      cout << endl << "\tEnter a weight: ";
      weight = getInt(0,99,"\tA weight must be between 0 and 99. Enter again: ");
      totalW += weight; //add weight to total weight
      //anotehr item?
      cout << endl << "Do you want to order another item? Enter Y or N: ";
      ans = getYN("Invalid response. Enter Y or N: ");
    }
		     
}
